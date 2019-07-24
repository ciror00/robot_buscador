#include "Operador.h"

void Operador::begin(){
  EEPROM.begin(512);
  //EEPROM.put(this->primeraDireccion, primeraDireccion);
  //EEPROM.commit();
}

void Operador::GuardarDatoEnMemoria(int memoria, int datos){
  //int memoria = this->primeraDireccion + 1;
  EEPROM.put(memoria, datos);
  EEPROM.commit();
}

int Operador::LeerDatoEnMemoria(int memoria){
  int dato;
  EEPROM.get(memoria, dato);
  return dato;
}
