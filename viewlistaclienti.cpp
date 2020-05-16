#include "viewlistaclienti.h"

viewListaClienti::viewListaClienti(QWidget *parent):QListWidget (parent){}

unsigned int viewListaClienti::getIndex() const
{
    return (unsigned int)this->selectedIndexes()[0].row();
}

bool viewListaClienti::isSomeoneSelected() const
{
    return !this->selectedIndexes().empty();
}

void viewListaClienti::unSelectIndex() const
{
    this->selectedIndexes().clear();
}
