/*
   Universidad Tecnica del Norte
   FICA-CIERCOM
   Christofer Macas
   (i)Ingreso de datos y (ii) ordenamiento
   (i)Al ingresar la palabra solo pueden ser números por comunicación serial. (ii)
   Una vez ingresados lo números, ordenarlos de menor a mayor e imprimirlo por comunicación serial.
*/

String dato;          // Variables
int on = 0;
int num;
String nI;
int temp;
int cont;
boolean bandera;

void setup() {
  Serial.begin(9600);                 //Iniciamos la cx serial
  attachInterrupt(0, datos, LOW);    //Enlazamos los metodos con las interrupciones 
  attachInterrupt(1, orden, LOW);

}

void loop() {

  if (on == 1) {                    //Cuando se preciona la primera interrupcion ingreso de datos
    if (Serial.available() > 0) {
      dato = Serial.readString();
      if (dato != "") {
        int vector[dato.length()];
        for (int i = 0; i < dato.length(); i++) { //Guardamos en un vector
          nI = dato.substring(i, (i + 1));
          vector[i] = nI.toInt();
        }
        if (cont == 1) {

          do {                                    //ordenamos los numeros 
            bandera = false;
            for (int i = 0; i < dato.length(); i++) {  
              if (vector[i] > vector[i + 1]) {  //Coparamos las posiciones 
                bandera = true;
                int temp = vector[i];          //Variable temporal 
                vector[i] = vector[i + 1];
                vector[i + 1] = temp;
              }
            }
          }
          while (bandera);
          for (int i = 0; i < dato.length(); i++) {  //impresion de los numeros ordenados 
            Serial.print(vector[i]);
          }
          dato = "";
        }
      } 
    }
  }
}
void datos() {
  switch (on) {
    case 0:
      Serial.println("Sistema de ordenado de numeros");
      Serial.println("Ingrese los numeros");
      on++;
      break;
    case 1:
      Serial.println(" ");
      Serial.println("Reinicio del sistema");
      on = 0;
      cont = 0;
      break;

  }
}
void orden() {
  Serial.println(" ");
  cont++;

}
