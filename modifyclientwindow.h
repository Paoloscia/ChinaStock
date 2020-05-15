#ifndef MODIFYCLIENTWINDOW_H
#define MODIFYCLIENTWINDOW_H

#include "addclientwindow.h"

class modifyClientWindow : public addClientWindow
{
    Q_OBJECT
private:

    unsigned int ind; //indice dell' oggetto da moficare nel catalogo, si passa sia per tenere l' indice, sia per passare quello giuto da moficare

public:

    explicit modifyClientWindow(QWidget *parent = nullptr);

    void caricaDati(const QStringList &,const unsigned int);

    void clienteModificato();
public slots:

    void confirm() override;

signals:

    void rimpiazzaCliente(const unsigned int,const QStringList); //era replaceitem
};

#endif // MODIFYCLIENTWINDOW_H
