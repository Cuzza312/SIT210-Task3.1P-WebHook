#include <Adafruit_DHT.h>

int TempSensPin = D2;
#define DHTTYPE DHT11;

DHT dht(TempSensPin,DHT11);

// setup() runs once, when the device is first turned on.
void setup() {
  Serial.begin(9600);
  Serial.println("DHT Test");

  dht.begin();

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  float data = dht.getTempCelcius();

  if (isnan(data))
  {
    Particle.publish("DEBUG", "Couldn't fetch data", PRIVATE);
    return;  
  }
 
  String temp = String(data);

  Particle.publish("temp", temp, PRIVATE);
  
  delay(30s);
}