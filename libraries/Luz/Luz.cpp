#include <Arduino.h>
#include "Luz.h"

void Luz::begin(const int pin){
  this->pin = pin;
}

boolean Luz::Detectar(){
  int value = 0;
  value = digitalRead(this->pin);
  if (value == HIGH) {
    return true;
  }else{
    return false;
  }
  delay(1000);
}
