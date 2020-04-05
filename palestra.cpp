#include "palestra.h"

palestra::palestra(char n, char c, unsigned int g, unsigned int m, unsigned int a,string cf, char lN, char r, char v, unsigned int num,string nt,string em,bool s,bool sc,string ni,unsigned int sgpa,unsigned int smpa,unsigned int sapa):cliente(n,c,g,m,a,cf,lN,r,v,num,nt,em,s),scheda(sc),nomeistruttorepalestra(ni),sgiornopa(sgpa),smesepa(smpa),sannopa(sapa){}
palestra::palestra(cliente cli,bool sc,string ni,unsigned int sgpa,unsigned int smpa,unsigned int sapa):cliente(cli),scheda(sc),nomeistruttorepalestra(ni),sgiornopa(sgpa),smesepa(smpa),sannopa(sapa){}
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
bool palestra::isscheda() const
{
    return scheda;
}

string palestra::getnomeistruttorepalestra() const
{
    return nomeistruttorepalestra;
}

unsigned int palestra::getsgiorno() const
{
    return sgiornopa;
}

unsigned int palestra::getsmese() const
{
    return smesepa;
}

unsigned int palestra::getsanno() const
{
    return sannopa;
}

