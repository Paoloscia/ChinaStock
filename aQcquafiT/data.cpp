#include "data.h"

Data::Data(unsigned int gg, unsigned int mm, unsigned int aa)
{
    anno = aa;
    if (mm == 0 || mm > 12){
        mese = 1;
    }
    else{
        mese = mm;
    }
    if (gg == 0 || gg > 32 || (mm == 2 && gg > 28) || ((mm==4||mm==6||mm==9||mm==11) && gg==31)){
        giorno = 1;
    }
    else{
        giorno = gg;
    }

}

int Data::Giorno() const{
    return giorno;
}

int Data::Mese() const{
    return mese;
}

int Data::Anno() const{
    return anno;
}
