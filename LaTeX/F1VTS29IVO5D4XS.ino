#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2
#define Relay_Pin 4
int Low_temp=3;
int High_temp=7;
 
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
 
void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
  pinMode(Relay_Pin, OUTPUT);
  digitalWrite(Relay_Pin, LOW);
}
 
 
void loop(void)
{
  sensors.requestTemperatures(); 
  Serial.print(sensors.getTempCByIndex(0));
  if (sensors.getTempCByIndex(0) < Low_temp){
    /*Disconnect the relay module*/
    digitalWrite(Relay_Pin, HIGH);
   }
  if (sensors.getTempCByIndex(0) > High_temp){
    /*Connect the relay module*/
    digitalWrite(Relay_Pin, LOW);
  }
}
