/*
  D0 = GPIO16;
  D1 = GPIO5;
  D2 = GPIO4;
  D3 = GPIO0;
  D4 = GPIO2;
  D5 = GPIO14;
  D6 = GPIO12;
  D7 = GPIO13;
  D8 = GPIO15;
  D9 = GPIO3;
  D10 = GPIO1;
  LED_BUILTIN = GPIO16
 */
#include "Auto.h"
#include "Distancia.h"
#include "Luz.h"
#include "MQTT.h"
#include "Operador.h"

// Motor A
const int ENA = D8;
const int IN1 = D7;
const int IN2 = D6;

// Motor B
const int ENB = D3;
const int IN3 = D4;
const int IN4 = D5;

const int trigger = D0;
const int echo = D1;

const int luz = D2;

// Se tiene que descomentar y cargar con los datos correspondientes.
//char* red = "";
//char* pass = "";
//char* server = "";

char* topic_buscador = "planta/circulo/topadora/buscador";
char* topic_rfid = "planta/circulo/rfid/autorizacion";
char* topic_estado = "planta/circulo/topadora/estado";

long medida;
char distancia[7];
int distancia_minima = 15;
boolean linea;
boolean postSet = false;
byte emergency = 0;
//boolean emergencyMode = false;

byte knownObject = 0;
//boolean knownObjectMode = false;
int contador = 0;
