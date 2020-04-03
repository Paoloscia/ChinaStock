#include "cliente.h"
#include "ui_cliente.h"

Cliente::Cliente(char n, char c, unsigned int g, unsigned int m, unsigned int a, std::string cf, char lN, char r, char v, unsigned int num): nome(n),cognome(c),giorno(g),mese(m),anno(a),codicefiscale(cf),luogodN(lN),residenza(r),via(v),numvia(num){}

char Cliente::getnome() const
{
    return nome;
}

char Cliente::getcognome() const
{
    return cognome;
}

unsigned int Cliente::getgiorno() const
{
    return giorno;
}

unsigned int Cliente::getmese() const
{
    return mese;
}

unsigned int Cliente::getanno() const
{
    return anno;
}

std::string Cliente::getcodfiscale() const
{
    return codicefiscale;
}

char Cliente::getluogo() const
{
    return luogodN;
}

char Cliente::getres() const
{
    return residenza;
}

char Cliente::getvia() const
{
    return via;
}

unsigned int Cliente::getnum() const
{
    return numvia;
}
