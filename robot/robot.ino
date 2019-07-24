#include "robot.h"
#include "server.h" // Se agrega esta linea para datos de ssidd, password y servidor MQTT

Auto autito;
Distancia distancias;
MQTT mqtt;
Luz infrarojo;
Operador operador;

void setup(){
  Serial.begin(115200);
  autito.begin();
  distancias.begin(trigger, echo);
  infrarojo.begin(luz);
  mqtt.begin(red, pass, server);
  mqtt.IP();
  mqtt.Reconectar(topic_subscribe);
  mqtt.Suscribir(topic_subscribe);
  operador.begin();
}

void loop(){
  subscripcion = (int)operador.LeerDatoEnMemoria(0);
  //Ests lineas solo se ejecutan despues de retirar un objeto
  if(!postSet){
    linea = infrarojo.Detectar();
    autito.Girar();
    postSet = true;
  }
  if(subscripcion == 1){
    autito.Detener();
    Serial.println("Robot detenido.");
  }
  // Solo estas lineas se deben ejecutar constantemente
  medida = distancias.Medicion();
  sprintf(distancia, "%d cm", medida); Serial.println(distancia);
  mqtt.Reconectar(topic_subscribe);
  // A partir de aca, solo se ejecuta cuando hay un objeto
  if(medida < 10){
    autito.Detener();
    Serial.println("Objeto detectado. Avanzando");
    delay(2000);
    autito.Adelante();
    while(linea == true){
      linea = infrarojo.Detectar();
      delay(1000);
    }
    autito.Detener();
    delay(500);
    autito.Atras();
    delay(500);
    autito.Detener();
    Serial.println("Objeto quitado. Publicando");
    mqtt.Publicar(topic_publish, "Objeto quitado");
    Serial.println("Nueva busqueda.");
    postSet = false;
    delay(500);
  }
}
