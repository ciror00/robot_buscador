#include "MQTT.h"

void MQTT::begin(char* ssid, char* password, char* mqtt_server){
  this->ssid = ssid;
  this->password = password;
  this->mqtt_server = mqtt_server;
  this->client.setClient(this->esp);
  WiFi.begin(this->ssid, this->password);
  Serial.println();
  Serial.print("Conectando.");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Conectado, IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("Servidor MQTT: ");
  Serial.println(mqtt_server);
  this->client.setServer(mqtt_server, 1883);
  this->client.setCallback(Callback);
}

String MQTT::IP(){
  String buffer;
  ip = WiFi.localIP();
  return String(ip[0]) + String(".") +\
    String(ip[1]) + String(".") +\
    String(ip[2]) + String(".") +\
    String(ip[3]);
}

void MQTT::Reconectar(char* topic) {
  if (!this->client.connected()) {
    while (!this->client.connected()){
      Serial.print("Intentando conexion MQTT. ");
      String clientId = "ESP8266Client-";
      clientId += String(random(0xffff), HEX);
      if (this->client.connect(clientId.c_str())) {
        Serial.println("Conectado");
        this->client.subscribe(topic);
        //this->client.publish(topic, "PING");
        //delay(1000);
        //this->client.subscribe(topic);
      }else{
        Serial.print("Error, state: ");
        Serial.print(client.state());
        Serial.println(". Volviendo a intentar.");
        // Wait 5 seconds before retrying
        delay(3000);
      }
    }
  }
  this->client.loop();
}

void MQTT::Publicar(char* topic, char* mensaje){
  Serial.print("Funciona Publicar: ");
  if (this->client.connected()) {
    Serial.print(topic);
    Serial.print("\t");
    Serial.println(mensaje);
    this->client.publish(topic, mensaje);
  }else{
    Serial.print("Error. Estado:  ");
    Serial.println(client.state());
  }
}

void MQTT::Suscribir(char* topic){
  Serial.print("Funciona Suscribir: ");
  if (this->client.connected()) {
    Serial.println(topic);
    this->client.subscribe(topic);
  }else{
    Serial.print("Error. Estado:  ");
    Serial.println(client.state());
  }
}

void Callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensaje recibido de ");
  Serial.print(topic);
  Serial.print(". \t");
  char msj = (char)payload[0];
  //Serial.print(msj);
  Operador operador;
  if (msj == '1') {
    Serial.println("Valor 1");
    operador.GuardarDatoEnMemoria(0, 1);
  } else if(msj == '0'){
    Serial.println("Valor 0");
    operador.GuardarDatoEnMemoria(0, 0);
  } else {
    for (int i = 0 ; i < length ; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
  }
}
