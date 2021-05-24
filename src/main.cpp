
// Määritetään kirjastot
#include <Arduino.h>

//Määritetään vakiot
#define timeSeconds 10

// määritetään pinnit
const int potPin = 34; // <= Signaalipinni
const int pwm = 26;    // <= digitaalinen ulostulo pinni
int output_value;      // <= Analogisen signaalin vahvuus muuttuja

//
unsigned long now = millis(); // aina positiivinen 
unsigned long lastTrigger = 0;

unsigned long previousMillis = 0;


// määrittely functio Setup
void setup()
{
  // Nopeus jolla kommunikoidaan Esp:n kanssa
  Serial.begin(9600);
  //Määritetään power pinnin mode eli onko ulostulo vai input
  pinMode(pwm, OUTPUT);
}


void loop()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= (timeSeconds * 1000))
  {
    // Kirjoitetaan 1 power pinniin
    digitalWrite(pwm, HIGH);
    delay(1000);
    output_value = analogRead(potPin);
    output_value = map(output_value, 4095, 0, 0, 100);

    // Serial = terminaaliin tulostettavat rivit/teksti
    Serial.print("Moisture : ");
    Serial.print(output_value);
    Serial.println("%");

    delay(1000);
    previousMillis = currentMillis;
    // Kirjoitetaan 0 power pinniin
    digitalWrite(pwm, LOW);
  }
}