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
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  // Adelante rueda derecha
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Adelante rueda izquierda
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Auto::Atras(){
  Serial.println("Atras");
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  // Atras rueda derecha
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // Atras rueda izquierda
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}

void Auto::Detener(){
  Serial.println("Detener");
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}

void Auto::Girar(){
  Serial.println("Girar");
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  // Atras rueda derecha
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // Adelante rueda izquierda
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
/*
void Auto::Volver(){
  Serial.println("Volver");
  this->Detener();
  this->Atras();
  delay(2000);
  this->Detener();
}

void Derecha(){
  Serial.println("Derecha");
  //Direccion motor A
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, 200); //Velocidad motor A
  //Direccion motor B
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite (ENB, 100); //Velocidad motor A
}

void Izquierda(){
  Serial.println("Izquierda");
  //Direccion motor A
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENA, 50); //Velocidad motor A
  //Direccion motor B
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, 150); //Velocidad motor A
}
*/
