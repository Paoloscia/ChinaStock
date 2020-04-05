#ifndef PALESTRA_H
#define PALESTRA_H
#include "cliente.h"

class palestra : public Cliente
{
private:
    bool scheda; //se fa la scheda oppure no;
    string nomeistruttore; //nome istruttore;
    unsigned int sgiorno; //scadenza giorno
    unsigned int smese;  // scadenza mese
    unsigned int sanno;  // scadenza anno
public:
    palestra(char,char,unsigned int,unsigned int,unsigned int,string,char, char,char,unsigned int,string,string,bool,bool,string,unsigned int,unsigned int,unsigned int);
    //palestra(const palestra& p);

    virtual palestra* clone() const;
    //~palestra() override;
    //virtual bool operator==(const Cliente& c) const; //override?
    //virtual bool operator!=(const Cliente& c) const; //override?


    bool isscheda() const;
    string getnomeistruttore() const;
     /////////////DA DISCUTERE

    unsigned int getsgiorno() const;
    unsigned int getsmese() const;
    unsigned int getsanno() const;

};

#endif // PALESTRA_H
