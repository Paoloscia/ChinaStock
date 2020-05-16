#ifndef MODIFYCLIENTWINDOW_H
#define MODIFYCLIENTWINDOW_H

#include "addclientwindow.h"

class modifyClientWindow : public addClientWindow
{
    Q_OBJECT
private:

    unsigned int ind;

public:

    explicit modifyClientWindow(QWidget *parent = nullptr);

    void caricaDati(const QStringList &,const unsigned int);

    void clienteModificato();
public slots:

    void confirm() override;

signals:

    void rimpiazzaCliente(const unsigned int,const QStringList);
};

#endif // MODIFYCLIENTWINDOW_H
