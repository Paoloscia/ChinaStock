#ifndef PALESTRA_H
#define PALESTRA_H
#include "cliente.h"

class palestra : virtual public cliente
{
private:
    bool scheda; //se fa la scheda oppure no;
    string nomeistruttorepalestra; //nome istruttore;
    unsigned int sgiorno; //scadenza giorno
    unsigned int smese;  // scadenza mese
    unsigned int sanno;  // scadenza anno
public:
    palestra(char,char,unsigned int,unsigned int,unsigned int,string,char, char,char,unsigned int,string,string,bool,bool,string,unsigned int,unsigned int,unsigned int);
    //palestra(const palestra& p);
    palestra(cliente,bool,string,unsigned int,unsigned int,unsigned int);
    virtual palestra* clone() const;
    //virtual ~palestra();
    //virtual bool operator==(const cliente& c) const; //override?
    //virtual bool operator!=(const cliente& c) const; //override?


    bool isscheda() const;
    string getnomeistruttorepalestra() const;


    unsigned int getsgiorno() const;
    unsigned int getsmese() const;
    unsigned int getsanno() const;

};

#endif // PALESTRA_H
