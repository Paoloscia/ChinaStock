#ifndef PISCINA_H
#define PISCINA_H

#include "cliente.h"

class piscina : virtual public cliente
{
private:
    bool corsonuoto;
    string nomeistruttorepiscina;
    QDate scadenzapiscina;
public:
    piscina(string="",string="", int=2000, int=1, int=1,string="",string="", string="",string="",unsigned int = 0,string="",string="",bool=false,bool=false,string="",int=2000,int=1,int=1);
    piscina(cliente,bool=false,string="",int=2000,int=1,int=1);
    piscina* clone() const;
    //virtual ~piscina();

    int getGiornoPiscina() const;
    int getMesePiscina() const;
    int getAnnoPiscina() const;
    bool iscorsonuoto() const;
    string getnomeistruttorepiscina() const;

};

#endif // PISCINA_H
