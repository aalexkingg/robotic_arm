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
  
  Serial.begin(115200);
  //Serial.println("Which motor?");
}

void loop() {
  //---back and forth example

  int X = analogRead(X_pin);
  int Y = analogRead(Y_pin);

  Serial.print(Y + " " + X);

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
