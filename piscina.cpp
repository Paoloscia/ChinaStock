#include "piscina.h"



piscina::piscina(string n, string c, int a, int m, int g,string cf, string lN, string r, string v, unsigned int num,string nt,string em,bool s,bool cn,string ni,int sapi,int smpi,int sgpi):cliente(n,c,a,m,g,cf,lN,r,v,num,nt,em,s),corsonuoto(cn),nomeistruttorepiscina(ni),scadenzapiscina(sapi,smpi,sgpi){}
piscina::piscina(cliente cli,bool cn,string ni,int sapi,int smpi,int sgpi):cliente(cli),corsonuoto(cn),nomeistruttorepiscina(ni),scadenzapiscina(sapi,smpi,sgpi){}
piscina *piscina::clone() const{
    return new piscina(*this);
}

QDate piscina::getDataPiscina() const
{
    return scadenzapiscina;
}

int piscina::getGiornoPiscina() const
{
    return scadenzapiscina.QDate::day();
}

int piscina::getMesePiscina() const
{
    return scadenzapiscina.QDate::month();
}

int piscina::getAnnoPiscina() const
{
    return scadenzapiscina.QDate::year();
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
