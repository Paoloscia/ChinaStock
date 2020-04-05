#ifndef VIP_H
#define VIP_H

#include "piscina.h"
#include "palestra.h"

class vip: public palestra, public piscina
{
public:
    vip(){};
};

#endif // VIP_H
