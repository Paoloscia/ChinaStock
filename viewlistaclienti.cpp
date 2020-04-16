#include "viewlistaclienti.h"

viewListaClienti::viewListaClienti(QWidget *parent):QListWidget (parent){}

unsigned int viewListaClienti::getIndex() const
{
    return (uint)this->selectedIndexes()[0].row();
}

bool viewListaClienti::isSomeoneSeleceted() const
{
    return !this->selectedIndexes().empty();
}

void viewListaClienti::unSelectIndex() const
{
    this->selectedIndexes().clear();
}
