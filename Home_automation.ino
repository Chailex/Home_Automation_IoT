//Free to use and modify 
//Might come under MIT licence


#define BLYNK_PRINT Serial

#include "DHT.h"

#define DHTPIN 14     
#define DHTTYPE DHT22   
int led = 4;

DHT dht(DHTPIN, DHTTYPE);


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "e722c7813aa2426f94c61695a5d236df";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Realme 2 Pro";
char pass[] = "12345678";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  Serial.println("DHTxx test!");

  dht.begin();
  pinMode(led,OUTPUT);
}

void loop()
{
  Blynk.run();
    delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);
  if(t>15){
      digitalWrite(led,HIGH);
    }
}
