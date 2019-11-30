

/*
   Universidad Tecnica del Norte
   FICA-CIERCOM
   Integrantes: Almeida Axel
                Macas Christofer
                Rosero Romel

   Realizar un sistema dom´otico que encienda y apague 5 leds en relaci´on a los estados seleccionados dentro
   de una aplicaci´on del tel´efono. Para ello, se debe contectar un m´odulo bluetooth en el sistema. Cuando
   termina de realizar esta acci´on, env´ıa un mensaje que el proceso se ha efectuado correctamente.
   Como ejemplo del vencto a enviar podr´ıa ser:
   —A1,B0,C1,D0,E0—. Esto indica que los leds A Y C se van a encender y los dem´as deben permanecer
   apagados.
*/


#include <Separador.h> //Libreria para recolectar datos de una cadena
Separador s;           //Variable para almacenar los datos
String dato;           //VAriables
String Diodo1, Diodo2, Diodo3, Diodo4, Diodo5;
int led1 = 8;
int led2 = 9;
int led3 = 10;
int led4 = 11;
int led5 = 12;
int tam;

void setup() {
  Serial.begin(9600);   //Iniciamos la comunicacion serial a 9600
  pinMode(led1, OUTPUT);//Pines de salida para los leds
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

}

void loop() {
  if (Serial.available() > 0) {   //Comprobamos el envio y recibo de datos
    delay(3);
    dato = Serial.readString();
    tam = dato.length();
    //Serial.println(dato);
    Diodo1 = s.separa(dato, ',', 0);  //Almacenamos los datos separaos por un ,
    Diodo2 = s.separa(dato, ',', 1);
    Diodo3 = s.separa(dato, ',', 2);
    Diodo4 = s.separa(dato, ',', 3);
    Diodo5 = s.separa(dato, ',', 4);
    if ( tam == 18) {                 //Si supera el numero de carracteres 
      Serial.println("Dato enviado");
      luces();
    } else {
      Serial.println("Dato incorrecto");
      Serial.println(tam);
    }
  }
  
}

void luces() {                                 //Metodo para encender los diodos les de acuerdo a los datos recibidos 
  if (Diodo1 == "A0" || Diodo1 == "A1") {
    if (Diodo1 == "A0") {
      digitalWrite(led1, LOW);
    }
    if (Diodo1 == "A1") {
      digitalWrite(led1, HIGH);
    }
  } else {
    Serial.println("Dato A incorrecto");
  }
  if (Diodo2 == " B0" || Diodo2 == " B1") {
    if (Diodo2 == " B0") {
      digitalWrite(led2, LOW);
    }
    if (Diodo2 == " B1") {
      digitalWrite(led2, HIGH);
    }
  } else {
    Serial.println("Dato B incorrecto");
  }
  if (Diodo3 == " C0" || Diodo3 == " C1") {
    if (Diodo3 == " C0") {
      digitalWrite(led3, LOW);
    }
    if (Diodo3 == " C1") {
      digitalWrite(led3, HIGH);
    }
  } else {
    Serial.println("Dato C incorrecto");
  }
  if (Diodo4 == " D0" || Diodo4 == " D1") {
    if (Diodo4 == " D0") {
      digitalWrite(led4, LOW);
    }
    if (Diodo4 == " D1") {
      digitalWrite(led4, HIGH);
    }
  } else {
    Serial.println("Dato D incorrecto");
  }
  if (Diodo5 == " E0" || Diodo5 == " E1") {
    if (Diodo5 == " E0") {
      digitalWrite(led5, LOW);
    }
    if (Diodo5 == " E1") {
      digitalWrite(led5, HIGH);
    }
  } else {
    Serial.println("Dato E incorrecto");
  }
}
