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
  mqtt.Reconectar(topic_emergencia);
  mqtt.Suscribir(topic_emergencia);
  mqtt.Suscribir(topic_rfid);
  operador.begin();
}

void loop(){
  // Esto solo se ejecuta con habilitado desde Mosquitto
  if(emergency == 0){
    //Ests lineas solo se ejecutan despues de retirar un objeto
    if(!postSet){
      Serial.println("Iniciando modo busqueda.");
      mqtt.Publicar(topic_buscador, "Buscando objetos en plataforma.");
      autito.Girar();
      postSet = true;
    }
    medida = distancias.Medicion();
    linea = infrarojo.Detectar();
    sprintf(distancia, "%d cm", medida); Serial.println(distancia);
  }else{
    Serial.println("Busqueda detenida");
    if(postSet){
      mqtt.Publicar(topic_buscador, "Robot detenido.");
      autito.Detener();
      postSet = false;
    }
  }
  // A partir de aca, solo se ejecuta cuando hay un objeto
  if(medida < distancia_minima && emergency == 0){
    mqtt.Publicar(topic_buscador, "Objeto encontrado en plataforma.");
    autito.Detener();
    if(knownObject == 0){
      Serial.println("Objeto encontrado. Avanzando para quitar objeto.");
      delay(2000);
      autito.Adelante();
      while(linea == false){
        linea = infrarojo.Detectar();
        delay(250);
      }
      autito.Detener();
      mqtt.Publicar(topic_buscador, "Objeto quitado");
      delay(250);
      autito.Atras();
    }else{
      Serial.println("Objeto importante en plataforma.");
      mqtt.Publicar(topic_buscador, "Objeto importante en plataforma");
    }
    delay(2000);
    autito.Detener();
    Serial.println("Nueva busqueda.");
    postSet = false;
    delay(500);
  }
  // Solo estas lineas se deben ejecutar constantemente
  mqtt.Reconectar(topic_emergencia);
  emergency = operador.LeerDatoEnMemoria(0);
  knownObject = operador.LeerDatoEnMemoria(1);
}
