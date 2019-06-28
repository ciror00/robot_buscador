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
  //Direccion motor A
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, 255); //Velocidad motor A
  //Direccion motor B
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, 255); //Velocidad motor B
}

void Auto::Atras(){
  //Direccion motor A
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENA, 128);  //Velocidad motor A
  //Direccion motor B
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite (ENB, 128); //Velocidad motor B
}

void Auto::Detener(){
  //Direccion motor A
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, 0); //Velocidad motor A
  //Direccion motor B
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, 0); //Velocidad motor A
}

void Auto::Girar(){
  //Direccion motor A
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, 32); //Velocidad motor A
  //Direccion motor B
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, 127); //Velocidad motor A
}

void Auto::Volver(){
  this->Detener();
  this->Atras();
  delay(2000);
  this->Detener();
}

/*
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
