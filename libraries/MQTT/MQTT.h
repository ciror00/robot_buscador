#ifndef __MQTT__h__
#define __MQTT__h__

//#include <WiFi.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>


class MQTT{
  char* ssid;// = "CYS";
  char* password;// = "Informatica";
  char* mqtt_server;// = "192.168.1.177";

  WiFiClient esp;
  PubSubClient client;// = PubSubClient client(esp);

  IPAddress ip;

  long lastMsg = 0;
  char msg[50];

public:
    MQTT() = default;
    void begin(char* ssid, char* password, char* mqtt);
    String IP();
    void Reconectar();
    void Publicar(String mensaje);
    ~MQTT() = default;
};

#endif
