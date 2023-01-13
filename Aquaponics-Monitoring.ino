#include "Sensors.h"
#include "Display.h"

void setup(void){
// start serial port so we can see the data
Serial.begin(9600);

startTempSensor();
setupDisplay();
}

void loop(void){
setSensorValues(getSensorTemp(), getPH(), getPotassium());
updateValues();

// Print to serial for debugging or if the screen breaks
Serial.print("Temperature: ");
Serial.print(getSensorTemp());
Serial.println();
Serial.print("PH: "); 
Serial.print(getPH());
Serial.println();
Serial.print("Potassium: ");
Serial.print(getPotassium());
delay(1000);
}
 
