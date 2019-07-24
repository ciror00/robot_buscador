#ifndef __OPERADOR__h__
#define __OPERADOR__h__

#include <EEPROM.h>

class Operador{

  public:
      Operador() = default;
      void begin();
      void GuardarDatoEnMemoria(int memoria, int datos);
      int LeerDatoEnMemoria(int memoria);
      ~Operador() = default;
};

#endif
