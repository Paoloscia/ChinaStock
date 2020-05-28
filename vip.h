#ifndef VIP_H
#define VIP_H

#include "piscina.h"
#include "palestra.h"

class vip: public piscina, public palestra
{
public:
    vip* clone() const override;
    vip(string="",string="", int=0,int=0,int=0,string="",string="", string="",string="",string="",string="",string="",bool=false,bool=false,string="",int=0,int=0,int=0,bool=false,string="",int=0,int=0,int=0);
};

#endif
