#ifndef PISCINA_H
#define PISCINA_H

#include "cliente.h"
#include "data.h"

class Piscina : public Cliente
{
public:
    Piscina(Cliente,data,string,bool);
    ~Piscina();
    data getscadenzaabbonamento() const;
    string getnomeistruttorepiscina() const;
    bool getcorsonuoto() const;
    static int clientipiscina;
    int getclientipiscina();
private:
    data datascadenza;
    string nomeistruttorepiscina;
    bool corsonuoto;
    Cliente clientepiscina;
};

#endif // PISCINA_H
