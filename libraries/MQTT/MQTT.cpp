#include "MQTT.h"

void MQTT::begin(char* ssid, char* password, char* mqtt){
  this->ssid = ssid;
  this->password = password;
  this->mqtt_server = mqtt_server;
  //Serial.println();
  //Serial.print("Connecting to ");
  //Serial.println(ssid);
  WiFi.begin(this->ssid, this->ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  //Serial.println("");
  //Serial.println("WiFi connected");
  //Serial.println("IP address: ");
  //Serial.println(this->WiFi.localIP());
  //PubSubClient client(server, 1883, callback, wifiClient);
  //this->client(&mqtt_server, 1883, NULL, this->esp);
  this->client.setServer(mqtt_server, 1883);
  //this->client.setCallback(callback);
  this->lastMsg = 0;
}

String MQTT::IP(){
  String buffer;
  ip = WiFi.localIP();
  return String(ip[0]) + String(".") +\
    String(ip[1]) + String(".") +\
    String(ip[2]) + String(".") +\
    String(ip[3]);
}

void MQTT::Reconectar() {
  if (!client.connected()) {
    // Loop until we're reconnected
    while (!this->client.connected()) {
      if (this->client.connect("ESP8266Client")) {
        this->client.publish("casa/despacho/temperatura", "Enviando el primer mensaje");
        this->client.subscribe("casa/despacho/luz");
      } else {
        delay(5000);
      }
    }
  }
  this->client.loop();
}

void MQTT::Publicar(String mensaje){
  long now = millis();
  char buffer[50];
  mensaje.toCharArray(buffer, 50);
  if (now - this->lastMsg > 2000) {
    this->lastMsg = now;
    client.publish("casa/despacho/temperatura", buffer);
  }
}
