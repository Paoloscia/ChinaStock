#ifndef VIEWLISTACLIENTI_H
#define VIEWLISTACLIENTI_H
#include <QListWidget>

class viewListaClienti : public QListWidget
{
    Q_OBJECT
public:
    viewListaClienti(QWidget * =nullptr);

    unsigned int getIndex() const;

    bool isSomeoneSeleceted() const;

    void unSelectIndex() const;
};

#endif // VIEWLISTACLIENTI_H
