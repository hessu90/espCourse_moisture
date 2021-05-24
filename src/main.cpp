#include <Arduino.h>

const int potPin = 34;
const int pwm = 26;
int output_value;

#define timeSeconds 10
unsigned long now = millis();
unsigned long lastTrigger = 0;

unsigned long previousMillis = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(pwm, OUTPUT);
  
}
void loop()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= (timeSeconds * 1000))
  {
    digitalWrite(pwm, HIGH);
    delay(1000);
    output_value = analogRead(potPin);
    output_value = map(output_value, 4095, 0, 0, 100);

    Serial.print("Moisture : ");
    Serial.print(output_value);
    Serial.println("%");

    delay(1000);
    previousMillis = currentMillis;
    digitalWrite(pwm, LOW);
  }
}