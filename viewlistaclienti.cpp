#include "viewlistaclienti.h"

viewListaClienti::viewListaClienti(QWidget *parent):QListWidget (parent){}

unsigned int viewListaClienti::getIndex() const
{
    return (unsigned int)this->selectedIndexes()[0].row(); //era uint, abbiamo messo unsigned int
}

bool viewListaClienti::isSomeoneSeleceted() const
{
    return !this->selectedIndexes().empty();
}

void viewListaClienti::unSelectIndex() const
{
    this->selectedIndexes().clear();
}
