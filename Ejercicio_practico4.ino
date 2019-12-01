/*
   Universidad Tecnica del norte
   FICA-CIERCOM
   Christofer Macas
   Estimados estudiantes: Realizar un programa que el número ingresado por comunicación serial se
   refleje en código binario hasta 8 bits con leds. Ejemplo: número ingresado 5 -> sistema con leds 00000101
*/

String dato;      //Variable para almaacenar la lectura de la comunicación serial
int numero;       //Variable para almacer el dato en entero
int valor ;       //Variable para la lectura binaria 
boolean bandera = true;   //Variable para la impresion 


void setup() {
  Serial.begin(9600);           //Inicio la cominicación serial
  for (int i = 2; i <= 9; i++) {  //Ciclo para poner como salida a los pines 
    pinMode(i, OUTPUT);
  }
  Serial.println("Ingrese el numero");
}

void loop() {

  if (Serial.available() > 0) {   //Inicio la cominicación serial
    dato = Serial.readString();
    numero = dato.toInt();        //Almaceno el dato en entero
    if (numero < 256) {           //Conición para no superar los 8 bits
      valor = binario(numero);    //Inicio el metodo para imprimir el número binario
      delay(20);
      texto();                    //Método para imprimir el mensaje 
      bandera = true;
    } else {
      Serial.println("Supera los 8 bits");
    }

  }

}
int binario (int x) {             //Metodo para mostrar en leds el numero 
  digitalWrite(2, bitRead(x, 0));
  digitalWrite(3, bitRead(x, 1));
  digitalWrite(4, bitRead(x, 2));
  digitalWrite(5, bitRead(x, 3));
  digitalWrite(6, bitRead(x, 4));
  digitalWrite(7, bitRead(x, 5));
  digitalWrite(8, bitRead(x, 6));
  digitalWrite(9, bitRead(x, 7));
}
void texto() {                    //Método para imprimir mensaje 
  if (bandera == true) {
    Serial.println("Ingrese nuevo valor");
    bandera = false;
  }
}
