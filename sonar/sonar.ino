void setup() {
    Serial.begin(9600);

    pinMode(2, OUTPUT);
    digitalWrite(2, LOW);
    pinMode(3, INPUT);
}

void loop() {
    return;
    digitalWrite(2, HIGH);
    delayMicroseconds(10);
    digitalWrite(2, LOW);

    unsigned long duration = pulseIn(3, HIGH, 10000);

    Serial.println(duration * 0.5 / 1000000.0 * 340.0 * 100.0);

    delay(1000);
}
