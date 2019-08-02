#ifndef __AUTO__h__
#define __AUTO__h__

enum Velocidad{
    PARADO,
    LENTO = 767,
    RAPIDO = 1023
};

class Auto{
  // Motor Derecho
  const int ENA = D8;
  const int IN1 = D7;
  const int IN2 = D6;

  // Motor Izquierdo
  const int ENB = D3;
  const int IN3 = D5;
  const int IN4 = D4;

  public:
    Auto() = default;
    void begin();
    void Adelante();
    void Atras();
    void Detener();
    void Girar();
    void Volver();
    ~Auto() = default;
};

#endif
