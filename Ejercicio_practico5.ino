
/*
   Universidad Técnica del Norte
    FICA-CIERCOM
    Sistemas microprocesados
    Christofer Macas
    Estimados estudiantes realizar el siguiente ejercicio: Realizar un programa que active 4 juegos de luces con 5 leds
    al ingresar datos por comunicación serial de la siguiente forma: ACBF-> Activa juego 1 ACGF -> Activa juego 2 ADBF
  -> Activa juego 3 ADBH -> Activa juego 4
*/

int i;
int leds[5] = {8, 9, 10, 11, 12};
int num;
String dato;
int on=0;

void setup() {
  Serial.begin(9600);
  for (i = 0; i <= 5; i++) {
    pinMode(leds[i], OUTPUT);
  }

}

void loop() {

  if (Serial.available() > 0) {
    dato = Serial.readString();
    if(dato == "ACBF" || dato =="ACGF"|| dato =="ADBF"|| dato =="ADBH"){
    if (dato == "ACBF") {
      luces1();
    }
    if (dato == "ACGF") {
      luces2();
    }
    if (dato == "ADBF") {
      luces3();
    }
    if (dato == "ADBH") {
      luces4();
    }
    }else
    Serial.println("Dato incorrecto");
  }
}

void luces1() {
  
  for (i = 0; i < 8; i++) {
    digitalWrite(leds[i], HIGH); // encendiendo posicion i del vector
    delay(200);
    i = i + 1;
  }
  for (; i >= 0; i--) {
    digitalWrite(leds[i], LOW); // encendiendo posicion i del vector
    delay(200);
    i = i - 1;
  }
}
void luces2() {
  for (i = 0; i <= 5; i++) {
    digitalWrite(leds[i], HIGH); // encendiendo posicion i del vector
    delay(200);
    i = i + 1;
  }
  for (; i >= 0; i--) {
    digitalWrite(leds[i], LOW); // encendiendo posicion i del vector
    delay(200);
    i = i - 1;
  }
}
void luces3() {
  for (i=0; i < 5; i++) {
    digitalWrite(leds[i], HIGH); // encendiendo posicion i del vector
    delay(200);
    digitalWrite(leds[i], LOW); // encendiendo posicion i del vector
    delay(200);
  }
}

void luces4() {
  for (i = 0; i < 5; i++) {
    digitalWrite(leds[i], HIGH); // encendiendo posicion i del vector
    delay(200);
    digitalWrite(leds[i], LOW); // encendiendo posicion i del vector
    delay(200);
  }
  for (; i >= 0; i--) {
    digitalWrite(leds[i], HIGH); // encendiendo posicion i del vector
    delay(100);
    digitalWrite(leds[i], LOW); // encendiendo posicion i del vector
    delay(100);

  }
}
