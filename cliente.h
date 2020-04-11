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
    cliente(string,string, int, int, int,string,string, string,string,unsigned int,string,string,bool);
    //virtual ~cliente = default ;
    //virtual cliente* clone() const = 0;

    string getnome() const; //forse bisognerà passare per riferimento costante le stringhe ritornate per non fare la copia, quindi const string& come ritorno
    string getcognome() const;
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
