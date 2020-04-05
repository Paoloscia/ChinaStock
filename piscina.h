#ifndef PISCINA_H
#define PISCINA_H

#include "cliente.h"

class piscina : virtual public cliente
{
private:
    bool corsonuoto;
    string nomeistruttorepiscina;
    unsigned int sgiorno; //scadenza giorno
    unsigned int smese;  // scadenza mese
    unsigned int sanno;  // scadenza anno
public:
    piscina(char,char,unsigned int,unsigned int,unsigned int,string,char, char,char,unsigned int,string,string,bool,bool,string,unsigned int,unsigned int,unsigned int);
    piscina(cliente,bool,string,unsigned int,unsigned int,unsigned int);
    virtual piscina* clone() const;
    //virtual ~piscina();
    bool iscorsonuoto() const;

    string getnomeistruttorepiscina() const;


    unsigned int getsgiorno() const;
    unsigned int getsmese() const;
    unsigned int getsanno() const;

};

#endif // PISCINA_H
