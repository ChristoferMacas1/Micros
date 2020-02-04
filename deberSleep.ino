/* Universidad tecnica del norte
    FICA CIEROM
    CHRISTOFER MACAS
    DEBER SLEEP
   Realizar un ejercicio que cada 2 segundos el sistema se encuentre activado y cada 10 segundos
   el sistema baje su consumo de corriente. Envíe mensajes de comunicación serial para mostrar el resultado.
*/
#include<TimerOne.h>
#include<avr/sleep.h>
#include<avr/power.h>
#include <avr/wdt.h>
#include<EEPROM.h>
int cont = 0;
int estado;

void setup() {
  Serial.begin(9600);
  estado = EEPROM.read(0);
  EEPROM.write(0, 1);
  attachInterrupt(0, wakeup1, LOW);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(conteo);
  set_sleep_mode(SLEEP_MODE_IDLE);  //Se utilizo el IDLE por que no apaga los timers por completo a diferencia de los demas modos de sleep
  Serial.begin(9600);
  Serial.println(estado);


}

void loop() {
  activar();
  dormir();

}

void conteo() {
  cont++;

}

void wakeup1() {
  sleep_disable();
  Serial.println("DESPIERTO");
  cont = 0;
}
void activar() {
  if (cont == 2 ) {
    Serial.println("ACTIVO");
    Serial.println(cont);
  }
}
void dormir() {
  if (cont == 4) {
    Serial.println("DORMIDO");
    EEPROM.update(0, 0);
    sleep_mode();
    sleep_enable();
  } if (cont == 10) {
    sleep_disable();
    cont = 0;
  }
}
