#include <Servo.h>

#define ESC_PIN 10

Servo esc;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);

    
    esc.attach(ESC_PIN, 1000, 2000);
    esc.write(1000);
}

void loop() {
    if (Serial.available()) {
        char inchar = Serial.read();

        if (inchar == 'h') {
            esc.write(2000);
            digitalWrite(LED_BUILTIN, HIGH);
        }
        else if (inchar == 'l') {
            digitalWrite(LED_BUILTIN, LOW);
            esc.write(1000);
        }
    }
}
