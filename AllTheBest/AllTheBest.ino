#include <LiquidCrystal.h>

const int RS = 3;
const int EN = 4;
const int D4 = 9;
const int D5 = 10;
const int D6 = 11;
const int D7 = 12;

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

byte heart[8] = {
  B00000,
  B00000,
  B01010,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
};

void setup() {
  lcd.createChar(1, heart);
  lcd.begin(16, 2);
  lcd.clear();
}

String msg[] = {
  "  Vse nejlepsi  ",
  " k tvym dnesnim ",
  "  narozeninam   ",
  " ti preje tvuj  ",
  "    Zdenecek    ",
};
char sng[] = "Hodne stesti a zdravi!";

void loop() {
  delay(10000);
  
  for (int i = 5; i >= 0; i--) {
    lcd.print(i);
    lcd.print("  ");
    delay(1000);
  }
  
  lcd.setCursor(0, 1);
  for (int i = 0; i < 16; i++) {
    lcd.write(1);
    delay(250);
  }
  
  delay(2000);
  lcd.clear();
  
  lcd.print("Moje mila Evicko");
  lcd.setCursor(0, 1);
  for (int i = 0; i < 16; i++) {
    lcd.write(1);
  }

  delay(3000);

  for (int i = 0; i < 5; i++) {
    lcd.setCursor(0, 1);
    lcd.print(msg[i]);
    delay(3000);
  }

  lcd.setCursor(0, 1);
  for (int i = 0; i < 16; i++) {
    lcd.write(1);
  }

  delay(3000);
  lcd.clear();

  lcd.autoscroll();
  for (int n = 0; n < 2; n++) {
    lcd.setCursor(16, n % 2);
    for (int i = 0; i < 22; i++) {
      lcd.print(sng[i]);
      delay(666);
    }
    for (int i = 0; i < 16; i++) {
      lcd.print(" ");
      delay(666);
    }
    lcd.clear();
  }
  lcd.noAutoscroll();

  lcd.clear();
}
