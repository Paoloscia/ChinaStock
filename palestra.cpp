#include "palestra.h"

palestra::palestra(string n, string c, int a, int m, int g,string cf, string lN, string r, string v, string num,string nt,string em,bool s,bool sc,string ni,int sapa,int smpa,int sgpa):cliente(n,c,a,m,g,cf,lN,r,v,num,nt,em,s),scheda(sc),nomeistruttorepalestra(ni),scadenzapalestra(sapa,smpa,sgpa){}
palestra::palestra(cliente cli,bool sc,string ni,int sgpa,int smpa,int sapa):cliente(cli),scheda(sc),nomeistruttorepalestra(ni),scadenzapalestra(sgpa,smpa,sapa){}
palestra *palestra::clone() const
{
    return new palestra(*this);
}

QDate palestra::getDataPalestra() const
{
    return scadenzapalestra;
}

int palestra::getGiornoPalestra() const
{
    return scadenzapalestra.QDate::day();
}

int palestra::getMesePalestra() const
{
    return scadenzapalestra.QDate::month();
}

int palestra::getAnnoPalestra() const
{
    return scadenzapalestra.QDate::year();
}

bool palestra::isscheda() const
{
    return scheda;
}

string palestra::getnomeistruttorepalestra() const
{
    return nomeistruttorepalestra;
}
