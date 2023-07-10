#include <LiquidCrystal_I2C.h> /*include LCD I2C Library*/
LiquidCrystal_I2C lcd(0x27,16,2);  /*I2C scanned address defined + I2C screen size*/

void setup() {
  lcd.init();  /*LCD display initialized*/
  lcd.clear();     /*Clear LCD Display*/
  lcd.backlight();      /*Turn ON LCD Backlight*/
  lcd.setCursor(2,0);   /*Set cursor to Row 1*/
  lcd.print("Pitchayatida"); /*print text on LCD*/
  lcd.setCursor(2,1);   /*set cursor on row 2*/
  lcd.print("CDTI"); /*print message on LCD*/

}

void loop() {

}
