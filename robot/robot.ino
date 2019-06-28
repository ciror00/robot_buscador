#include "robot.h"

#define PROD false
#define SERIAL_BEGIN if(!PROD) Serial.begin(115200)
#define SERIAL_PRINT(MESSAGE) if(!PROD) Serial.println(MESSAGE)

Auto autito;
Distancia distancias;
MQTT mqtt;


void setup(){
  SERIAL_PRINT("Inicio");
  autito.begin();
  distancias.begin(trigger, echo);
  mqtt.begin(red, pass, server);
  mqtt.IP();
  mqtt.Reconectar();
  mqtt.Publicar("Hola mundo");
}

void loop(){
  detectar = distancias.Medicion();
  if(detectar < 10){
    autito.Detener();
    autito.Adelante();
  }else{
    autito.Girar();
  }
  attachInterrupt(digitalPinToInterrupt(LUZ), encontrar, FALLING);
}

void encontrar(){
  autito.Volver();
}
