#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int nine = 9;
const int ten = 10;
// defines variables

void setup() {

  //I put your setup code here, to run once:
  lcd.begin(16, 2);

  pinMode(nine, OUTPUT);
  pinMode(ten, INPUT);
  //digitalwrite(nine,LOW);

  Serial.begin(9600);
 
}
void loop() {


  digitalWrite(nine, LOW);
  delayMicroseconds(2);

  digitalWrite(nine, HIGH);
  delayMicroseconds(10);
  digitalWrite(nine, LOW);

  float t = pulseIn(ten, HIGH);
  float m =(t * 0.034) / 2;
  lcd.setCursor(6, 0);
  lcd.print("cm:");
  Serial.print("distance");
  Serial.println(m);
  lcd.print(m);
  delay(10);
  lcd.clear();
  
}
