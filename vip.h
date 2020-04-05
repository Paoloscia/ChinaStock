#ifndef VIP_H
#define VIP_H

#include "piscina.h"
#include "palestra.h"

class Vip: public Palestra, public Piscina
{
public:
    Vip(){};
};

#endif // VIP_H
