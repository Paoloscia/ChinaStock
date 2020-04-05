#ifndef VIP_H
#define VIP_H

#include "piscina.h"
#include "palestra.h"

class vip: public piscina, public palestra
{
public:

    vip(cliente,piscina,palestra);
};

#endif // VIP_H
