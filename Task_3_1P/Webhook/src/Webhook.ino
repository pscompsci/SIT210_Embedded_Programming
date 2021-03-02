/*
 * Project Webhook
 * Description: SIT210 - Task 3.1P
 * Author: Peter Stacey
 * Date:   2 March 2021
 */

#include "Adafruit_DHT.h"

#define DHT_PIN  6
#define DHT_TYPE DHT11

float hum;
float temp;

DHT dht(DHT_PIN, DHT_TYPE);

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  Serial.begin(9600);
  pinMode(DHT_PIN, INPUT);

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  hum = dht.getHumidity();
  temp = dht.getTempCelcius();
  Serial.print("{Hum: ");
  Serial.print(hum);
  Serial.print(", Temp: ");
  Serial.print(temp);
  Serial.println("}");

  delay(2000);
}