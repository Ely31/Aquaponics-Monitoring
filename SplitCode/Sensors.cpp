// Functions to return the values of all our sensors
#include <OneWire.h>
#include <DallasTemperature.h>
#include "Sensors.h"
#include "Arduino.h"

// Temp stuff
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature tempSensor(&oneWire);

// Ph stuff
#define phPin A0
#define phOffset -0.4
#define phConstant (14.0/1023.0)

// Phosphate stuff
#define phosphatePin A2
float phosphateConstant = 1;
float phosphateOffset = 0;

void startTempSensor(){
  tempSensor.begin();
}

float getSensorTemp(){
  tempSensor.requestTemperatures();
  return tempSensor.getTempCByIndex(0); // 0 refers to the first device on the wire
}

float getPH(){
  return (analogRead(phPin) * phConstant) - phOffset;
}

float getPhosphate(){
  return (analogRead(phosphatePin) * phosphateConstant) - phosphateOffset;
}
