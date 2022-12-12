#include <OneWire.h>
#include <DallasTemperature.h>
#include "Sensors.h"

void setup(void)
{
// start serial port so we can see the data
Serial.begin(9600);

startTempSensor();
}

void loop(void)
{
Serial.print("Temperature: ");
Serial.print(getSensorTemp());
Serial.println();
Serial.print("PH: "); 
Serial.print(getPH());
Serial.println();
Serial.print("Phosphate: ");
Serial.print(getPhosphate());
delay(1000);
}
 
