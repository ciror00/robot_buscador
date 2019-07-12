#ifndef __LUZ__h__
#define __LUZ__h__


class Luz{
  int pin;
  int value;

  public:
    Luz() = default;
    void begin(const int pin);
    boolean Detectar();
    ~Luz() = default;
};

#endif
