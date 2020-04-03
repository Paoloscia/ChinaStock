#ifndef MODEL_H
#define MODEL_H
#include<string>
class Cliente{
private:
    char nome;
    char cognome;
    unsigned int giorno;
    unsigned int mese;
    unsigned int anno;
    std:: string codicefiscale;
    char luogodN; // luogo di nascita
    char residenza; // residenza;
    char via;
    unsigned int numvia; // numero via;
public:
    Cliente(char,char,unsigned int,unsigned int,unsigned int,std::string,char, char,char,unsigned int);
    //virtual ~Cliente = default ;
    //virtual Cliente* clone() const = 0;

    char getnome() const;
    char getcognome() const;
    unsigned int getgiorno() const;
    unsigned int getmese() const;
    unsigned int getanno() const;
    std::string getcodfiscale() const;
    char getluogo() const;
    char getres() const;
    char getvia() const;
    unsigned int getnum() const;
};

#endif // CLIENTE_H
