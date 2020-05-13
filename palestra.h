#ifndef PALESTRA_H
#define PALESTRA_H
#include "cliente.h"

class palestra : virtual public cliente
{
private:
    bool scheda;
    string nomeistruttorepalestra;
    QDate scadenzapalestra;
public:
    palestra(string="",string="", int=2000,int=1,int=1,string="",string="", string="",string="",string="",string="",string="",bool=false,bool=false,string="",int=2000,int=1,int=1);
    palestra(cliente,bool=false,string="",int=2000,int=1,int=1);
    palestra* clone() const;
    //virtual ~palestra();
    //virtual bool operator==(const cliente& c) const; //override?
    //virtual bool operator!=(const cliente& c) const; //override?

    QDate getDataPalestra() const;
    int getGiornoPalestra() const;
    int getMesePalestra() const;
    int getAnnoPalestra() const;
    bool isscheda() const;
    string getnomeistruttorepalestra() const;

};

#endif
