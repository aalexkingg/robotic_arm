
int stepperPins[3][2] = {};

void step(boolean dir, int dirPin, int steps, int stepPin) {
    digitalWrite(dirPin,dir);
    delay(50);

    for(int i=0;i<steps;i++){
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(800);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(800);
    }
}


void setup() {
    /*
    for (int i=0; i<3; i++) {
        for (int j=0; j<2; j++) {
            pinMode(stepperPins[i][j], OUTPUT);
        }
    }
    */
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
}

void loop() {
    step(true, 6, 3600, 7);
    delay(1000);
}