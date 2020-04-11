#include "model.h"

<<<<<<< HEAD

model::model() : datiTotali(new Container<cliente*>()),datiFiltrati(new Container<cliente*>()),modificato(false)
{
    resetfiltro();
}

void model::resetfiltro() const
{
    datiFiltrati->clear();
    for(auto it = datiTotali->inizio();it!=datiTotali->fine();++it)
     {
        datiFiltrati->aggiungiDavanti(*it);
     }
}
