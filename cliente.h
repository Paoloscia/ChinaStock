#ifndef CLIENTE_H
#define CLIENTE_H
#include<string>
#include<QDate>
using std::string;
class cliente{
private:
    string nome;
    string cognome;
    QDate dataNascita;
    string codicefiscale;
    string luogodN; // luogo di nascita
    string residenza; // residenza;
    string via;
    unsigned int numvia; // numero via;
    string  numerotel;
    string mail;
    bool student;
public:
    cliente(string="",string="", int=2000, int=1, int=1,string="",string="", string="",string="",unsigned int = 0,string="",string="",bool=false);
    virtual ~cliente() = default;

    virtual cliente* clone() const; //DA CONTROLLARE!!

    string getnome() const; //forse bisognerà passare per riferimento costante le stringhe ritornate per non fare la copia, quindi const string& come ritorno
    string getcognome() const;
    QDate getDataN() const;
    int getGiornoN() const;
    int getMeseN() const;
    int getAnnoN() const;
    string getcodfiscale() const;
    string getluogo() const;
    string getres() const;
    string getvia() const;
    unsigned int getnum() const;
    string getnumerotel() const;
    string getmail() const;
    bool getstudent() const;
};

#endif // CLIENTE_H
