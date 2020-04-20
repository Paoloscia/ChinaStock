#include "palestra.h"

palestra::palestra(string n, string c, int g, int m, int a,string cf, string lN, string r, string v, unsigned int num,string nt,string em,bool s,bool sc,string ni,int sgpa,int smpa,int sapa):cliente(n,c,g,m,a,cf,lN,r,v,num,nt,em,s),scheda(sc),nomeistruttorepalestra(ni),scadenzapalestra(sgpa,smpa,sapa){}
palestra::palestra(cliente cli,bool sc,string ni,int sgpa,int smpa,int sapa):cliente(cli),scheda(sc),nomeistruttorepalestra(ni),scadenzapalestra(sgpa,smpa,sapa){}
palestra *palestra::clone() const
{
    return new palestra(*this);
}
/*
palestra::palestra(const palestra &p)
{

}

bool palestra::operator==(const cliente &c) const
{

}

bool palestra::operator!=(const cliente &c) const
{

}
*/
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
