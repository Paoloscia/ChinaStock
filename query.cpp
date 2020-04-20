#include "query.h"
query::query(string nome,string cognome, int giorno, int mese, int anno,string codicefiscale,string luogodN, string residenza,string via,unsigned int numvia,string numerotel,string mail,bool studente, bool palestra, bool piscina):nome(nome),cognome(cognome),
    giorno(giorno), mese(mese),anno(anno),codicefiscale(codicefiscale),luogo(luogodN),residenza(residenza),via(via),numero(numvia),numerotelefono(numerotel),mail(mail),studente(studente == false ? true : studente),piscina(piscina || palestra == false ? true:piscina),
    palestra(palestra || piscina == false ? true : palestra)
{
    //Bisogna sistemare Vip è decidere insieme se è corretto quanto è stato scritto
}

std::string query::getnome() const
{
    return nome;
}

std::string query::getcognome() const
{
    return cognome;
}

std::string query::getcodfiscale() const
{
    return codicefiscale;
}

std::string query::getluogo() const
{
    return luogo;
}

std::string query::getres() const
{
    return residenza;
}

std::string query::getvia() const
{
    return via;
}

unsigned int query::getnum() const
{
    return numero;
}

std::string query::getnumerotel() const
{
    return numerotelefono;
}

std::string query::getmail() const
{
    return mail;
}

bool query::getstudent() const
{
    return studente;
}

bool query::getpiscina() const
{
    return piscina;
}

bool query::getpalestra() const
{
    return palestra;
}
