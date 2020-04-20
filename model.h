#ifndef MODEL_H
#define MODEL_H

#include "container.h"
#include "cliente.h"
#include "piscina.h"
#include "palestra.h"
#include "vip.h"
#include <QString>
#include <QFile>
#include <QXmlStreamWriter>
#include <QDomDocument>

class model
{
public:
    model(QString path);
    ~model();
    void resetfiltro() const;

    void aggiungiOggetto(cliente *);

    void cancellaOggetto(cliente *, bool = true);

    void salva();

    void carica(QString path) const;

    //partire da clear, reset filter e costruttore

    //clear serve a distruggere tutto il container datitotali, è il nostro distruggi

private:
    QString path; //serve per prendere i dati dal percorso del file
    Container<cliente *> *datiTotali; //Vedere se effettivamente è giusto
    Container<cliente *> *datiFiltrati; //Vedere se effettivamente è giusto
    bool modificato; //teoricamente serve per non risalvare se non è stato modificato nulla
};

#endif // MODEL_H
