#ifndef __DISTANCIA__h__
#define __DISTANCIA__h__


class Distancia{
  int trigger;
  int echo;

  long tiempo;
  long distancia;

  public:
    Distancia() = default;
    void begin(const int trigger,const int echo);
    long Medicion();
    ~Distancia() = default;
};

#endif
