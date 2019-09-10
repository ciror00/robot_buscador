#include <Arduino.h>
#include "Luz.h"

void Luz::begin(const int pin){
  this->pin = pin;
  this->value = 0;
}

boolean Luz::Detectar(){
  this->value = digitalRead(this->pin);
  if (this->value == HIGH) {
    Serial.println("Fondo Negro");
    return false;
  }else{
    Serial.println("Fondo Blanco");
    return true;
  }
  delay(1000);
}
