#include "cliente.h"

cliente::cliente(string n, string c, int a, int m, int g,string cf, string lN, string r, string v, unsigned int num,string nt,string em,bool s): nome(n),cognome(c),dataNascita(a,m,g),codicefiscale(cf),luogodN(lN),residenza(r),via(v),numvia(num),numerotel(nt),mail(em),student(s){}

cliente *cliente::clone() const
{
    return new cliente(*this);
}

string cliente::getnome() const
{
    return nome;
}

string cliente::getcognome() const
{
    return cognome;
}

QDate cliente::getDataN() const
{
    return dataNascita;
}

int cliente::getGiornoN() const
{
    return dataNascita.QDate::day();
}

int cliente::getMeseN() const
{
    return dataNascita.QDate::month();
}

int cliente::getAnnoN() const
{
    return dataNascita.QDate::year();
}

string cliente::getcodfiscale() const
{
    return codicefiscale;
}

string cliente::getluogo() const
{
    return luogodN;
}

string cliente::getres() const
{
    return residenza;
}

string cliente::getvia() const
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
