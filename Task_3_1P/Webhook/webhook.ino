#include <Adafruit_Sensor.h>
#include <Adafruit_DHT.h>

#define DHT_PIN  6
#define DHT_TYPE DHT11

#define DELAY_TIME 30000  // 30 seconds

// For recordings readings from the sensor
float humidity;
float temperature;

// For sending the readings to thingspeak
String temp;
String hum;

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
    Serial.begin(9600);
    pinMode(DHT_PIN, INPUT);
}

void loop() {
    
    humidity = dht.getHumidity();
    temperature = dht.getTempCelcius();
    
    temp = String(temperature);
    hum = String(humidity);
    
    Particle.publish("temp", temp, PRIVATE);
    Particle.publish("hum", hum, PRIVATE);
    
    // Also print to monitor on the serial monitor
    // via the particle CLI. Command:
    // "particle serial monitor"
    Serial.print("{Temp: ");
    Serial.print(temp);
    Serial.print(", Hum: ");
    Serial.print(hum);
    Serial.println("}");
    
    delay(DELAY_TIME);
}