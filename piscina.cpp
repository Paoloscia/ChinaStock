#include "piscina.h"

int Piscina::clientipiscina = 0; //contatore statico per numero clienti piscina

Piscina::Piscina(Cliente cli, data d,string n,bool cn) :clientepiscina(cli), datascadenza(d), nomeistruttorepiscina (n), corsonuoto(cn)
{
    clientipiscina++;
}

Piscina::~Piscina()
{
    clientipiscina--;
}

data Piscina::getscadenzaabbonamento() const
{
    return datascadenza;
}

string Piscina::getnomeistruttorepiscina() const
{
    return nomeistruttorepiscina;
}

bool Piscina::getcorsonuoto() const
{
    return corsonuoto;
}

int Piscina::getclientipiscina()
{
    return clientipiscina;
}
