

/*
 * Universidad Tecnica del norte
 * FICA-CIERCOM
 * Christofer Macas
  Estimados estudiantes:
  Realizar un programa que mediante teclado matricial (consultar) ingrese el tiempo en segundos de una cuenta regresiva.
  Esta cuenta, decrece cada 1 segundo mediante timer.

*/
#include <Keypad.h>     // importa libreria Keypad
#include <MsTimer2.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const byte FILAS = 4;     // define numero de filas
const byte COLUMNAS = 4;    // define numero de columnas
char keys[FILAS][COLUMNAS] = {    // define la distribucion de teclas
  {'7', '8', '9', 'A'},
  {'4', '5', '6', 'B'},
  {'1', '2', '3', 'C'},
  {'*', '0', '#', 'D'}
};

byte pinesFilas[FILAS] = {A0, A1, A2, A3}; // pines correspondientes a las filas
byte pinesColumnas[COLUMNAS] = {7, 6, 5, 4}; // pines correspondientes a las columnas

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);  // crea objeto

char tecla;       // almacena la tecla presionada
String dato;
int seg;
int i = 0;
int valorM;


void setup()
{
  lcd.begin(16, 2);
  MsTimer2::set(1000, cuenta);
  MsTimer2::start();
  Serial.begin(9600);      // inicializa comunicacion serie
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Encendido");
}

void loop() {
  tecla = teclado.getKey();   // obtiene tecla presionada y asigna a variable
  if (tecla)        // comprueba que se haya presionado una tecla
  {
    MsTimer2::start();
    dato = dato + tecla; // almacena en array la tecla presionada
    seg = dato.toInt();
    if (tecla = 'A') {
      dato = " ";
    }
    lcd.setCursor(0, 1);
    lcd.print(seg);
  }
}

void cuenta() {
  i--;
  valorM = seg + i;
  Serial.println(valorM);
  if (valorM == 0) {
    MsTimer2::stop();
  }
}
