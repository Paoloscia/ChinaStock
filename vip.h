#ifndef VIP_H
#define VIP_H

#include "piscina.h"
#include "palestra.h"

class vip: public piscina, public palestra
{
public:

    vip(char,char,int,int, int,string,char,char,char,unsigned int,string,string,bool,bool,string,int,int,int,bool,string,int,int,int);
    vip(cliente,piscina,palestra);

};

#endif // VIP_H
