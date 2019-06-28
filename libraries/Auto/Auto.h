#ifndef __AUTO__h__
#define __AUTO__h__


class Auto{
  // Motor A
  const int ENA = D8;
  const int IN1 = D7;
  const int IN2 = D6;

  // Motor B
  const int ENB = D3;
  const int IN3 = D4;
  const int IN4 = D5;

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
