#include <Arduino.h>
#include "Auto.h"

void Auto::begin(){
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void Auto::Adelante(){
  Serial.println("Adelante");
  analogWrite(ENA, RAPIDO);
  analogWrite(ENB, RAPIDO);
  // Adelante rueda derecha
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // Adelante rueda izquierda
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Auto::Atras(){
  Serial.println("Atras");
  // Velocidad de los motores
  analogWrite(ENA, LENTO);
  analogWrite(ENB, LENTO);
  // Atras rueda derecha
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Atras rueda izquierda
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Auto::Detener(){
  Serial.println("Detener");
  // Velocidad de los motores
  analogWrite(ENA, PARADO);
  analogWrite(ENB, PARADO);
  //
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  //
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}

void Auto::Girar(){
  Serial.println("Girar");
  // Velocidad de los motores
  analogWrite(ENA, LENTO);
  analogWrite(ENB, LENTO);
  // Adelante rueda derecha
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // Atras rueda izquierda
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
