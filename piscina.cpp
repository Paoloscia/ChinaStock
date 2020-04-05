#include "piscina.h"



piscina::piscina(char n, char c, unsigned int g, unsigned int m, unsigned int a,string cf, char lN, char r, char v, unsigned int num,string nt,string em,bool s,bool cn,string ni,unsigned int sg,unsigned int sm,unsigned int sa):cliente(n,c,g,m,a,cf,lN,r,v,num,nt,em,s),corsonuoto(cn),nomeistruttorepiscina(ni),sgiorno(sg),smese(sm),sanno(sa){}
piscina::piscina(cliente cli,bool cn,string ni,unsigned int sg,unsigned int sm,unsigned int sa):cliente(cli),corsonuoto(cn),nomeistruttorepiscina(ni),sgiorno(sg),smese(sm),sanno(sa){}
piscina *piscina::clone() const{
    return new piscina(*this);
}
//piscina::~piscina(){}

bool piscina::iscorsonuoto() const
{
    return corsonuoto;
}

string piscina::getnomeistruttorepiscina() const
{
    return nomeistruttorepiscina;
}

unsigned int piscina::getsgiorno() const
{
    return sgiorno;
}

unsigned int piscina::getsmese() const
{
    return smese;
}

unsigned int piscina::getsanno() const
{
    return sanno;
}
