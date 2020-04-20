#ifndef QUERY_H
#define QUERY_H
#include <string>
using std::string;

class query
{
public:
    query(string nome,string cognome, int giorno, int mese, int anno,string codicefiscale,string luogodN, string residenza,string via,unsigned int numvia,string numerotel,string mail,bool studente, bool palestra, bool piscina);//ultimi 3 booleani sono abbonamento piscina, palestra o vip
    //ho tolto l'ultimo bool perchè è VIP
    string getnome() const;
    string getcognome() const;
    string getcodfiscale() const;
    string getluogo() const;
    string getres() const;
    string getvia() const;
    unsigned int getnum() const;
    string getnumerotel() const;
    string getmail() const;
    bool getstudent() const;
    bool getpiscina() const;
    bool getpalestra() const;
    bool getvip() const;
private:
    string nome;
    string cognome;
    unsigned int giorno;
    unsigned int mese;
    unsigned int anno;
    string codicefiscale;

    string luogo;
    string residenza;
    string via;
    unsigned int numero;
    string numerotelefono;
    string mail;
    bool studente;
    bool piscina;
    bool palestra;
    bool vip;
};


#endif // QUERY_H
