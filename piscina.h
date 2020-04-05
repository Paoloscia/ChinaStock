#ifndef PISCINA_H
#define PISCINA_H

#include "cliente.h"

class piscina : virtual public cliente
{
private:
    bool corsonuoto;
    string nomeistruttorepiscina;
    unsigned int sgiornopi; //scadenza giorno
    unsigned int smesepi;  // scadenza mese
    unsigned int sannopi;  // scadenza anno
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
