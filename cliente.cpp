#include "cliente.h"
#include "ui_cliente.h"

cliente::cliente(char n, char c, unsigned int g, unsigned int m, unsigned int a,string cf, char lN, char r, char v, unsigned int num,string nt,string em,bool s): nome(n),cognome(c),giorno(g),mese(m),anno(a),codicefiscale(cf),luogodN(lN),residenza(r),via(v),numvia(num),numerotel(nt),mail(em),student(s){}

char cliente::getnome() const
{
    return nome;
}

char cliente::getcognome() const
{
    return cognome;
}

unsigned int cliente::getgiorno() const
{
    return giorno;
}

unsigned int cliente::getmese() const
{
    return mese;
}

unsigned int cliente::getanno() const
{
    return anno;
}

string cliente::getcodfiscale() const
{
    return codicefiscale;
}

char cliente::getluogo() const
{
    return luogodN;
}

char cliente::getres() const
{
    return residenza;
}

char cliente::getvia() const
{
    return via;
}

unsigned int cliente::getnum() const
{
    return numvia;
}

string cliente::getnumerotel() const
{
    return numerotel;
}

string cliente::getmail() const
{
    return mail;
}

bool cliente::getstudent() const
{
    return student;
}
