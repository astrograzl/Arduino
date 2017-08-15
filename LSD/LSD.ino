#include <LiquidCrystal.h>

const int RS = 3;
const int EN = 5;
const int D4 = 9;
const int D5 = 10;
const int D6 = 11;
const int D7 = 12;
const int BTN = 7;

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

byte skull[8] = {
  B00000,
  B01110,
  B11111,
  B10101,
  B11011,
  B01110,
  B01010,
  B00000,
};

void setup() {
  pinMode(BTN, INPUT);
  lcd.createChar(8, skull);
  lcd.begin(16, 2);
  lcd.clear();
}

char url[] = "astrograzl.github.io";

void loop() {
  lcd.write(8);
  lcd.print(" Astro--Grazl ");
  lcd.write(8);

  delay(3000);

  lcd.setCursor(0, 1);
  lcd.print(" Hacker Amateur ");

  delay(5000);
  lcd.clear();

  lcd.autoscroll();
  lcd.setCursor(16, 1);
  for (int i = 0; i < 20; i++) {
    lcd.print(url[i]);
    delay(666);
  }
  for (int i = 0; i < 16; i++) {
    lcd.print(" ");
    delay(666);
  }
  lcd.noAutoscroll();

  lcd.clear();

  for (int n = 0; n < 10; n++) {
    for (int i = 0; i < 16; i++) {
      if (digitalRead(BTN) == HIGH) {
        lcd.clear();
        lcd.print("    janak @     ");
        lcd.setCursor(0, 1);
        lcd.print(" astronomie.cz  ");
        delay(10000);
        lcd.clear();
      } else {
        lcd.setCursor(i, abs(i % 2 - n % 2));
        lcd.write(8);
      }
    }
    delay(666);
    lcd.clear();
  }

  delay(2000);
}
