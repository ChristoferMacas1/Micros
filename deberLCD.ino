/*
 * Universidad tecnica del norte
 * FICA-CIERCOM
 * Crhistofer Macas
 * Realice un programa que ingrese una palabra por comunicación serial y genere una rotación de caracteres en la LCD.
 */

#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);  
String mensaje; 
int longitud_texto = mensaje.length();
  
void setup() {
    Serial.begin(9600);
      lcd.begin(16, 2);     
}

void loop() {
if(Serial.available()>0){
      mensaje=Serial.readString();
      Serial.println(mensaje);
      imp();
    }
}

void imp(){
  lcd.setCursor(0, 0);   
  lcd.print(mensaje);    
  delay(1500);
  for (int posicion = 0; posicion < longitud_texto; posicion++)
  {
    lcd.scrollDisplayLeft();
    delay(300);
  }
  for (int posicion = 0; posicion < (16 + longitud_texto); posicion++)
  {
    lcd.scrollDisplayRight();
    delay(300);
  }
  for (int posicion = 0; posicion < 16; posicion++)
  {
    lcd.scrollDisplayLeft();
    delay(300);
  }
  delay(1000);
}
