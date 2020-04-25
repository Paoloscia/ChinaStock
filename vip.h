#ifndef VIP_H
#define VIP_H

#include "piscina.h"
#include "palestra.h"

class vip: public piscina, public palestra
{
public:
    vip* clone() const;
    vip(string="",string="", int=0,int=0,int=0,string="",string="", string="",string="",unsigned int = 0,string="",string="",bool=false,bool=false,string="",int=0,int=0,int=0,bool=false,string="",int=0,int=0,int=0);
    vip(cliente,piscina,palestra);

};

#endif // VIP_H
