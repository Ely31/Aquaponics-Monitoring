// Program for testing out the LCD of the aquaponics system
#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library
#include "screen.h"

void setup(){
  setupScreen();
  printConstantText();
}

void loop() 
{
    // Change the numbers to test if that works
    updateScreen();
    delay(100);
    screentemp++;
    ph += 0.1;
    phosphate += 0.1;
    ammonia += 0.1;
}
