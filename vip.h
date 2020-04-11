#ifndef VIP_H
#define VIP_H

#include "piscina.h"
#include "palestra.h"

class vip: public piscina, public palestra
{
public:

    vip(string,string,int,int, int,string,string,string,string,unsigned int,string,string,bool,bool,string,int,int,int,bool,string,int,int,int);
    vip(cliente,piscina,palestra);

};

#endif // VIP_H
