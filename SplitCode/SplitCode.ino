#include "Sensors.h"
#include "Display.h"

void setup(void){
// start serial port so we can see the data
Serial.begin(9600);

startTempSensor();
setupDisplay();
}

void loop(void){
setSensorValues(getSensorTemp(), getPH(), getPhosphate());
updateValues();
  
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
 
