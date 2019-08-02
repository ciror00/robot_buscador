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
  // Esto solo se ejecuta con habilitado desde Mosquitto
  if(subscripcion == 0){
    //Ests lineas solo se ejecutan despues de retirar un objeto
    if(!postSet){
      Serial.println("Iniciando modo busqueda.");
      linea = infrarojo.Detectar();
      autito.Girar();
      postSet = true;
    }
    medida = distancias.Medicion();
    sprintf(distancia, "%d cm", medida); Serial.println(distancia);
  }else{
    Serial.println("Busqueda detenida");
    autito.Detener();
    postSet = false;
  }
  // Solo estas lineas se deben ejecutar constantemente
  mqtt.Reconectar(topic_subscribe);
  subscripcion = operador.LeerDatoEnMemoria(0);
  // A partir de aca, solo se ejecuta cuando hay un objeto
  if(medida < distancia_minima && subscripcion == 0){
    autito.Detener();
    Serial.println("Objeto detectado. Avanzando");
    delay(2000);
    autito.Adelante();
    while(linea == false){
      linea = infrarojo.Detectar();
      delay(500);
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
