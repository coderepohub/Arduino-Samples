//Writing sketch example for DHT11 sensor
#include "DHT.h"

//defining DHT PIN 
#define DHTPIN 0

//defining DHT Type
#define DHTTYPE DHT11

//Initialise DHT sensor
//takes two args 1-Pin 2-type of DHT
DHT dht(DHTPIN,DHTTYPE);

void setup()
{
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  //reading temperature and humidity takes 250 ms
  
  
  //reading humidity
  float humidity = dht.readHumidity();
  //reading temperature in Celcius
  float tempC = dht.readTemperature();
  //reading temp in farehnheit
  float tempF = dht.readTemperature(true);
  
  delay(2000);
  //checking for readig failure
  if(isnan(humidity) || isnan(tempC) || isnan(tempF))
  {
    Serial.println("Failed to read");
    return;
  }
  
  //compute heat index
  //it requires temperature in farehnheit
  //it takes two args 1-heat in farehnheit and 2-humidity
  float heatIndex = dht.computeHeatIndex(tempF,humidity);
  
   Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %t");
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print(" *C ");
  Serial.print(tempF);
  Serial.print(" *F\t");
  Serial.print("Heat Index: ");
  Serial.print(heatIndex);
  Serial.print(" *F");
  
}
