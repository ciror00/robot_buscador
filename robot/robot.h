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

// Motor A
const int ENA = D8;
const int IN1 = D7;
const int IN2 = D6;

// Motor B
const int ENB = D3;
const int IN3 = D4;
const int IN4 = D5;

const int trigger = D1;   //Pin digital 2 para el Trigger del sensor
const int echo = D0;   //Pin digital 3 para el Echo del sensor

const int LUZ = D2;

char* red = "";
char* pass = "";
char* server = "";

long detectar;
