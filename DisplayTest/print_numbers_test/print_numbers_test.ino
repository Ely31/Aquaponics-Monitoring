// Program for testing out the LCD of the aquaponics system
#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library

//if the IC model is known or the modules is unreadable,you can use this constructed function
LCDWIKI_KBV lcd(ILI9341,A3,A2,A1,A0,A4); //model,cs,cd,wr,rd,reset
//if the IC model is not known and the modules is readable,you can use this constructed function
//LCDWIKI_KBV mylcd(240,320,A3,A2,A1,A0,A4);//width,height,cs,cd,wr,rd,reset

//define some colour values
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#define LABEL_COLOR WHITE
#define NUMBER_COLOR GREEN

#define ORIGIN_X 10
#define ORIGIN_Y 15
#define LINE_SPACING 40

double temp = 20.56;
double ph = 7.0;
double phosphate = 1.0;
double ammonia = 1.0;

void printConstantText(){
  lcd.Set_Text_colour(LABEL_COLOR);
  lcd.Set_Text_Size(3);
  lcd.Print_String("Temp:", ORIGIN_X, ORIGIN_Y);
  lcd.Print_String("PH:", ORIGIN_X, ORIGIN_Y + 1*LINE_SPACING);
  lcd.Print_String("Phosphate:", ORIGIN_X, ORIGIN_Y + 2*LINE_SPACING);
  lcd.Print_String("Ammonia:", ORIGIN_X, ORIGIN_Y + 3*LINE_SPACING);

  lcd.Set_Text_Size(1);
  lcd.Print_String("Aquaponics Monitoring System V0", ORIGIN_X+10, 300);
}

// Display all of the numbers
void update()
{
  lcd.Set_Text_colour(NUMBER_COLOR);
  lcd.Set_Text_Size(3);
  // Temp
  lcd.Print_Number_Float(temp,2,100, ORIGIN_Y, '.', 0, ' ');
  // PH
  lcd.Print_Number_Float(ph, 2, ORIGIN_X + 60, ORIGIN_Y + 1*LINE_SPACING, '.', 0, ' ');
}


void setup(){
  Serial.begin(9600);
  lcd.Init_LCD();
  Serial.println(lcd.Read_ID(), HEX);
  lcd.Set_Rotation(2);
  lcd.Fill_Screen(BLACK);
  lcd.Set_Text_Mode(0);
  lcd.Set_Text_Back_colour(BLACK);

  printConstantText();
}

void loop() 
{
    update();
    delay(3000);
    temp++;
    ph += 0.1;
}
