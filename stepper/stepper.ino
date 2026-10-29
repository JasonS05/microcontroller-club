void setup() {
    Serial.begin(9600);

    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);

    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
}

int currentLocation = 0;

void loop() {
    int targetLocation = analogRead(A0);
    int distance = (((targetLocation - currentLocation) + 1024) % 2048) - 1024;

    if (distance > 10) {
        stepForward();
        currentLocation++;
    } else if (distance < -10) {
        stepBackward();
        currentLocation--;
    }

    stepForward();
}

void step(int n) {
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            stepForward();
        }
    } else if (n < 0) {
        for (int i = 0; i > n; i--) {
            stepBackward();
        }
    }
}

int position = 0;

void stepForward() {
    switch(position) {
    case 0:
        digitalWrite(8, LOW);
        digitalWrite(10, HIGH);
        break;
    case 1:
        digitalWrite(9, LOW);
        digitalWrite(11, HIGH);
        break;
    case 2:
        digitalWrite(10, LOW);
        digitalWrite(8, HIGH);
        break;
    case 3:
        digitalWrite(11, LOW);
        digitalWrite(9, HIGH);
        break;
    }

    position = (position + 1) % 4;
    delay(2);
}

void stepBackward() {
    switch(position) {
    case 0:
        digitalWrite(9, LOW);
        digitalWrite(11, HIGH);
        break;
    case 1:
        digitalWrite(10, LOW);
        digitalWrite(8, HIGH);
        break;
    case 2:
        digitalWrite(11, LOW);
        digitalWrite(9, HIGH);
        break;
    case 3:
        digitalWrite(8, LOW);
        digitalWrite(10, HIGH);
        break;
    }

    position = (position + 3) % 4;
    delay(2);
}
