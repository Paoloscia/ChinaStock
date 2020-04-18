#include "cliente.h"

cliente::cliente(string n, string c, int g, int m, int a,string cf, string lN, string r, string v, unsigned int num,string nt,string em,bool s): nome(n),cognome(c),dataNascita(g,m,a),codicefiscale(cf),luogodN(lN),residenza(r),via(v),numvia(num),numerotel(nt),mail(em),student(s){}

string cliente::getnome() const
{
    return nome;
}

string cliente::getcognome() const
{
    return cognome;
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
