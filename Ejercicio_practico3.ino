/*
 * Universidad Tecnica del norte 
 * FICA-CIERCOM
 * Christofer Macas
 * Realizar un programa que por comunicación serial se ingrese
   el límite de lectura del conversor análogo digital (0-1024) si el valor del conversor
   supera dicho valor, se enciende un led.
*/

float valor;  //Variable para el conversor analogo digital
String dato;  //Variable de lectura de datos
int valorM;   //Variable para la conversion a entero
int led = 8;  
boolean bandera = true;   //Variable para imprimir una sola vez 

void setup() {
  Serial.begin(9600);     //Iniciamos la Comunicación serial 
  pinMode(led, OUTPUT);   //Pin 8 en salida 
  Serial.println("Ingrese el valor maximo");

}

void loop() {
  
  rango();
  if (valorM < 1023) {    //Condición para no superar el rango máximo del conversor analogo
    bandera = true;      //Variable para la impresion 
    if (valorM > 0) {    //Condición para la ejecucion del codigo 
      valor = (analogRead(0)); 
      if (valor > valorM ) {      //Condiciónestablecida en el ejercicio 
        digitalWrite(led, HIGH);    
        rango();
      } else {
        digitalWrite(led, LOW);
      }
    }
  } else {
    if (bandera == true) {          //Impresion del mensaje si se supera el rango e ingreso de un nuevo valor
      Serial.println("Supera el rango");
      Serial.println("Ingrese nuevamente el rango");
      bandera = false;
    }
    rango();
  }
}

void rango() {              //Metodo para recibir un nuevo valor 

  if (Serial.available() > 0) {
    dato = Serial.readString();
    valorM = dato.toInt();
  }
}
