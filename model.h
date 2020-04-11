#ifndef MODEL_H
#define MODEL_H

#include "container.h"
#include "cliente.h"



class model
{
public:
    model();
    ~model();

    void aggiungiOggetto(cliente *);

    void cancellaOggetto(cliente *, bool = true);

    void salva();
};

#endif // MODEL_H
