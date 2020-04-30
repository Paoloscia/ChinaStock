#ifndef MODEL_H
#define MODEL_H

#include "container.h"
#include "cliente.h"
#include "piscina.h"
#include "palestra.h"
#include "vip.h"
#include "deeppointer.h"
#include <QString>
#include <QFile>
#include <QDomDocument>
#include <QXmlStreamWriter>
#include <QMap>
class model : public QObject
{

    Q_OBJECT

public:
    model(QString path);
    ~model();
    void resetfiltro() const;

    void cancellaOggetto(cliente *, bool = true);

    void salva();

    void carica(QString path) const;

    //partire da clear, reset filter e costruttore

    //clear serve a distruggere tutto il container datitotali, è il nostro distruggi

    QStringList getListaClientiFiltrata(const QString,QMap<unsigned int,unsigned int> &) const; //era getFilteredCatalog

public slots:
    void aggNelContainer(const QStringList);

signals:
    void clienteAggiunto();

private:

    QString path; //serve per prendere i dati dal percorso del file
    Container<deepPointer<cliente>> *datiTotali; //Vedere se effettivamente è giusto
    Container<deepPointer<cliente>> *datiFiltrati; //Vedere se effettivamente è giusto
    bool modificato; //teoricamente serve per non risalvare se non è stato modificato nulla

};

#endif // MODEL_H
