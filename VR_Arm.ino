//www.elegoo.com
//2016.12.12

/************************
Exercise the motor using
the L293D chip
************************/
int sideEnabled = 9;
int enabled[] = {5, 6, 7, 8};
int dir10 = 3;
int dir01 = 4;

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output

int motorNum = 1;

void setup() {
  //---set pin direction
  pinMode(dir10, OUTPUT);
  pinMode(dir01, OUTPUT);
  
  pinMode(enabled[0], OUTPUT);
  pinMode(enabled[1], OUTPUT);
  pinMode(enabled[2], OUTPUT);
  pinMode(enabled[3], OUTPUT);

  pinMode(sideEnabled, OUTPUT);

  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  
  Serial.begin(9600);
  //Serial.println("Which motor?");
  while (!Serial) {
    ;
  }
}

void loop() {
  //---back and forth example

  int X = analogRead(X_pin);
  int Y = analogRead(Y_pin);

  Serial.write(Serial.available());

  if (Serial.available() > 0) {

    byte incomingByte = Serial.read();

    if (incomingByte != -1) {

      switch (incomingByte) {

        // Motor 1 Up
        case 1:

          motorNum = 1;
          Serial.print("Forward\n");

          digitalWrite(dir01, HIGH);
          digitalWrite(dir10, LOW);

          break;

        // Motor 1 Down
        case 2:

          motorNum = 1;
          Serial.print("Back\n");

          digitalWrite(dir10, HIGH);
          digitalWrite(dir01, LOW);

          break;

        // Motor 2 Up
        case 3:

          motorNum = 2;
          Serial.print("Forward\n");

          digitalWrite(dir01, HIGH);
          digitalWrite(dir10, LOW);

          break;

        // Motor 2 Down
        case 4:

          motorNum = 2;
          Serial.print("Back\n");

          digitalWrite(dir10, HIGH);
          digitalWrite(dir01, LOW);

          break;

        // Motor 3 Up
        case 5:

          motorNum = 3;
          Serial.print("Forward\n");

          digitalWrite(dir01, HIGH);
          digitalWrite(dir10, LOW);

          break;

        // Motor 3 Down
        case 6:

          motorNum = 3;
          Serial.print("Back\n");

          digitalWrite(dir10, HIGH);
          digitalWrite(dir01, LOW);

          break;

        // Motor 4 Up
        case 7:

          motorNum = 4;
          Serial.print("Forward\n");

          digitalWrite(dir01, HIGH);
          digitalWrite(dir10, LOW);

          break;

        // Motor 4 Down
        case 8:

          motorNum = 4;
          Serial.print("Back\n");

          digitalWrite(dir10, HIGH);
          digitalWrite(dir01, LOW);

          break;
      }

    
      digitalWrite(enabled[motorNum-1], HIGH);
      delay(500);
      digitalWrite(enabled[motorNum-1], LOW);


    }
  }




  if (Y > 708) {
    if (X > 708) {
      
      //Serial.print("Back Left\n");
      
    } else if (X > 308) {
      
        Serial.print("Left\n");

        digitalWrite(dir10, HIGH);
        digitalWrite(dir01, LOW);

        digitalWrite(sideEnabled, HIGH);
        delay(250);
        digitalWrite(sideEnabled, LOW);
        
        //moveMotor(5);

    } else {
      
      //Serial.print("Forward Left\n");
      
    } 
  } else if (Y > 308) {
    if (X > 708) {
      
      Serial.print("Back\n");

      digitalWrite(dir10, HIGH);
      digitalWrite(dir01, LOW);

      //moveMotor(motorNum);

      digitalWrite(enabled[motorNum-1], HIGH);
      delay(250);
      digitalWrite(enabled[motorNum-1], LOW);

      //Up(motorNum);
      
    } else if (X < 308) {
      
      Serial.print("Forward\n");

      digitalWrite(dir01, HIGH);
      digitalWrite(dir10, LOW);

      //moveMotor(motorNum);

      digitalWrite(enabled[motorNum-1], HIGH);
      delay(250);
      digitalWrite(enabled[motorNum-1], LOW);
      
      //Down(motorNum);
      
    } 
  } else {
    if (X > 708) {
      
      //Serial.print("Back Right\n");
      
    } else if (X > 308) {
      
        Serial.print("Right\n");

        digitalWrite(dir01, HIGH);
        digitalWrite(dir10, LOW);

        digitalWrite(sideEnabled, HIGH);
        delay(250);
        digitalWrite(sideEnabled, LOW);

        //moveMotor(5);
      
      
    } else {
      
      //Serial.print("Forward Right\n");
      
    } 
  }

  if (!digitalRead(SW_pin)) {
    //Serial.print("Button pressed\n");

    motorNum++;

    if (motorNum > 4) {
      motorNum = 1;
    }

    Serial.print("Motor ");
    Serial.print(motorNum + "\n");

    delay(500);
    
  }

  //delay(500);

}
