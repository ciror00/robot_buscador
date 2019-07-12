#include <Arduino.h>
#include "Luz.h"

void Luz::begin(const int pin){
  this->pin = pin;
  this->value = 0;
}

boolean Luz::Detectar(){
  this->value = digitalRead(this->pin);
  if (this->value == HIGH) {
    Serial.println("Luz TRUE");
    return true;
  }else{
    Serial.println("Luz FALSE");
    return false;
  }
  delay(1000);
}
