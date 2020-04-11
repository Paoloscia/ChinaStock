#ifndef CLIENTE_H
#define CLIENTE_H
#include<string>
using std::string;
class cliente{
private:
    char nome;
    char cognome;

    string codicefiscale;
    char luogodN; // luogo di nascita
    char residenza; // residenza;
    char via;
    unsigned int numvia; // numero via;
    string  numerotel;
    string mail;
    bool student;
public:
    cliente(char,char,unsigned int,unsigned int,unsigned int,string,char, char,char,unsigned int,string,string,bool);
    //virtual ~cliente = default ;
    //virtual cliente* clone() const = 0;

    char getnome() const;
    char getcognome() const;
    unsigned int getgiorno() const;
    unsigned int getmese() const;
    unsigned int getanno() const;
    string getcodfiscale() const;
    char getluogo() const;
    char getres() const;
    char getvia() const;
    unsigned int getnum() const;
    string getnumerotel() const;
    string getmail() const;
    bool getstudent() const;
};

#endif // CLIENTE_H
