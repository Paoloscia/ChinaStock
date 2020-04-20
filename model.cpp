#include "model.h"

model::model() : datiTotali(new Container<cliente*>()),datiFiltrati(new Container<cliente*>()),modificato(false)
{
    resetfiltro();
}

model::~model()
{
    /*
    for (auto it = datiTotali->inizio(); it != datiTotali->fine(); ++it) {
           delete *it;
       }
    // FORSE E' INUTILE DA RICONTROLLARE!!!!
*/
       datiTotali->clear();
       datiFiltrati->clear();

       delete datiTotali;
       delete datiFiltrati;
}

void model::resetfiltro() const
{
    datiFiltrati->clear();
    for(auto it = datiTotali->inizio();it!=datiTotali->fine();++it)
     {
        datiFiltrati->aggiungiDavanti(*it);
    }
}

void model::aggiungiOggetto(cliente * cliente)
{
    modificato = true;
    datiTotali->aggiungiDavanti(cliente);
    resetfiltro();

}
