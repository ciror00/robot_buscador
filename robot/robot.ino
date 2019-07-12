#include "robot.h"

Auto autito;
Distancia distancias;
MQTT mqtt;
Luz infrarojo;

void setup(){
  Serial.begin(115200);
  autito.begin();
  distancias.begin(trigger, echo);
  infrarojo.begin(luz);
  mqtt.begin(red, pass, server);
  mqtt.IP();
  mqtt.Reconectar(topic_root);
  //mqtt.Publicar("Hola mundo");
}

void loop(){
  linea = infrarojo.Detectar();
  medida = distancias.Medicion();
  sprintf(distancia, "%d cm", medida); Serial.println(distancia);
  if(medida < 10){
    autito.Detener();
    Serial.println("Objeto detectado. Avanzando");
    delay(2000);
    autito.Adelante();
    while(linea == true){
      linea = infrarojo.Detectar();
      delay(1000);
    }
    delay(1000);
    autito.Detener();
    delay(1000);
    autito.Atras();
    delay(2000);
    autito.Detener();
    Serial.println("Objeto quitado. Publicando");
    mqtt.Reconectar(topic_root);
    mqtt.Publicar(topic_publish, "Objeto quitado");
    delay(2000);
    autito.Girar();
  }
}
