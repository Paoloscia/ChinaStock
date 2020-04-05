#ifndef VIP_H
#define VIP_H

#include "piscina.h"
#include "palestra.h"

class vip: public piscina, public palestra
{
public:

    vip(char,char,unsigned int,unsigned int, unsigned int,string,char,char,char,unsigned int,string,string,bool,bool,string,unsigned int,unsigned int,unsigned int,bool,string,unsigned int,unsigned int,unsigned int);
    vip(cliente,piscina,palestra);

};

#endif // VIP_H
