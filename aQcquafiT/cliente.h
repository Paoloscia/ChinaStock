#ifndef MODEL_H
#define MODEL_H
#include<string>
using std::string;
class Cliente{
private:
    char nome;
    char cognome;
    unsigned int giorno;
    unsigned int mese;
    unsigned int anno;
    string codicefiscale;
    char luogodN; // luogo di nascita
    char residenza; // residenza;
    char via;
    unsigned int numvia; // numero via;
    string  numerotel;
    string mail;
    bool student;
public:
    Cliente(char,char,unsigned int,unsigned int,unsigned int,string,char, char,char,unsigned int,string,string,bool);
    //virtual ~Cliente = default ;
    //virtual Cliente* clone() const = 0;

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
