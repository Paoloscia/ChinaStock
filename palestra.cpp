#include "palestra.h"

palestra::palestra(char n, char c, unsigned int g, unsigned int m, unsigned int a,string cf, char lN, char r, char v, unsigned int num,string nt,string em,bool s,bool sc,string ni,unsigned int sg,unsigned int sm,unsigned int sa):Cliente(n,c,g,m,a,cf,lN,r,v,num,nt,em,s),scheda(sc),nomeistruttore(ni),sgiorno(sg),smese(sm),sanno(sa){}

palestra *palestra::clone() const
{
    return new palestra(*this);
}
/*
palestra::palestra(const palestra &p)
{

}

bool palestra::operator==(const Cliente &c) const
{

}

bool palestra::operator!=(const Cliente &c) const
{

}
*/
bool palestra::isscheda() const
{
    return scheda;
}

string palestra::getnomeistruttore() const
{
    return nomeistruttore;
}

unsigned int palestra::getsgiorno() const
{
    return sgiorno;
}

unsigned int palestra::getsmese() const
{
    return smese;
}

unsigned int palestra::getsanno() const
{
    return sanno;
}

