#ifndef PALESTRA_H
#define PALESTRA_H
#include "cliente.h"

class palestra : virtual public cliente
{
private:
    bool scheda; //se fa la scheda oppure no;
    string nomeistruttorepalestra; //nome istruttore;
    QDate scadenzapalestra;
public:
    palestra(char,char,int,int,int,string,char, char,char,unsigned int,string,string,bool,bool,string,int,int,int);
    //palestra(const palestra& p);
    palestra(cliente,bool,string,int,int,int);
    virtual palestra* clone() const;
    //virtual ~palestra();
    //virtual bool operator==(const cliente& c) const; //override?
    //virtual bool operator!=(const cliente& c) const; //override?


    bool isscheda() const;
    string getnomeistruttorepalestra() const;

};

#endif // PALESTRA_H
