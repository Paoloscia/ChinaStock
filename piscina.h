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
    piscina(string,string,int,int,int,string,string, string,string,unsigned int,string,string,bool,bool,string,int,int,int);
    piscina(cliente,bool,string,int,int,int);
    virtual piscina* clone() const;
    //virtual ~piscina();
    bool iscorsonuoto() const;

    string getnomeistruttorepiscina() const;

};

#endif // PISCINA_H
