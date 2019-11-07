/*
   Universidad Tecnica del norte
       FICA-CIERCOM
   Sistemas Microprosesados
     Contador Binario
*/

#define btn 8
int led[] = {2, 3, 4, 5, 6, 7}; //Vector para los leds
int i=0;                        
int num;                        //Variable del contador 
int num2;                       //Variable para almacenar el dato del contador 


void setup() {
  pinMode(btn, INPUT);         //Declaro como entrada el boton 
  for (;i < 8; i++) {
    pinMode(led[i], OUTPUT);   //Declaro como salida al vector de led 
  }
  i=0;                        //Igualo la variable i a 0
 }
void loop() {
  for (i = 0; i < 6; i++) {   //0v en las posiciones correspondientes al vector led
    digitalWrite(led[i], LOW);
  }
  if (digitalRead(btn) == HIGH) { //Conicion para el funcionamiento del contador(boton en 1 funciona)
    delay(300);                   //Delay anti rebotes
    num = num + 1;                //Sumo 1 por cada pulsacion 
  }
    if (num >= 0 && num <= 64) { //Condicion del valor maximo del contador binario 6 bits = 2^6=64
      num2 =num;                 //Guardo el dato de la variable del contador
      for (i = 0; i < 6; i++) {      
        if (num2 % 2 == 1) {    //Saco el residuo del dato y si es igual a 1 activo 5v
          digitalWrite(led[i], HIGH);
          delay(10);

        }
        else {
          digitalWrite(led[i], LOW);
          delay(10);
          
        }
        num2 = num2 / 2;     //Divido el dato del contador para 2
      }

    }
  }
