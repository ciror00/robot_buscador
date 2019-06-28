#include <Arduino.h>
#include "Distancia.h"

void Distancia::begin(const int trigger,const int echo){
  this->trigger = trigger;
  this->echo = echo;
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trigger, LOW);
}

long Distancia::Medicion(){
  digitalWrite(this->trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(this->trigger, LOW);
  tiempo = pulseIn(this->echo, HIGH);
  distancia = tiempo/59;
  delay(100);
  return distancia;
}
