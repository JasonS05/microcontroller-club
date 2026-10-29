void setup() {
    Serial.begin(9600);

    pinMode(7, OUTPUT);
    digitalWrite(7, LOW);
}

void loop() {
    int width = (int)(analogRead(A0) / 1024.0 * 1000.0) + 1000;

    digitalWrite(7, HIGH);
    delayMicroseconds(width);
    digitalWrite(7, LOW);
    delayMicroseconds(20000 - width);
    return;
}
