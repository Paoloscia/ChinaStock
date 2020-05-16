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

    void resetfiltro() const;  //costante??
    void cancellaOggetto(cliente *, bool = true);
    void salva();
    bool getModificato() const;
    void carica(QString path) const;
    QStringList getCampiCliente(const unsigned int) const;
    QStringList getListaClientiFiltrata(const QString,QMap<unsigned int,unsigned int> &) const;
    QStringList getListaClientiCsv() const;
    QStringList getListaClientiPDF() const;
    void rimuoviCliente(const unsigned int);
    deepPointer<cliente> mostraCliente(const unsigned int);
    deepPointer<cliente> mostraClientePDF(const unsigned int);
    void filterPiscina();  //filtri costanti??
    void filterPalestra();
    void filterMaggiorenne();
    void filterMinorenne();
    void filterStudente();
    void filterVip();
    void filterCorsoPiscina();
    void filterSchedaPalestra();

public slots:
    void aggNelContainer(const QStringList);
    void modificaItem(const unsigned int,const QStringList);

signals:
    void clienteAggiunto();
    void clienteRimosso();
    void resetColoreFiltroM() const;

private:
    QString path;
    Container<deepPointer<cliente>> *datiTotali;
    Container<deepPointer<cliente>> *datiFiltrati;
    bool modificato;

};

#endif
