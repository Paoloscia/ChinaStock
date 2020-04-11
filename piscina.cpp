#include "piscina.h"



piscina::piscina(char n, char c, int g, int m, int a,string cf, char lN, char r, char v, unsigned int num,string nt,string em,bool s,bool cn,string ni,int sgpi,int smpi,int sapi):cliente(n,c,g,m,a,cf,lN,r,v,num,nt,em,s),corsonuoto(cn),nomeistruttorepiscina(ni),scadenzapiscina(sgpi,smpi,sapi){}
piscina::piscina(cliente cli,bool cn,string ni,int sgpi,int smpi,int sapi):cliente(cli),corsonuoto(cn),nomeistruttorepiscina(ni),scadenzapiscina(sgpi,smpi,sapi){}
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
