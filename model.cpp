#include "model.h"
#include<iostream>
using std::cout;
using std::endl;

model::model(QString path) : path(path),datiTotali(new Container<deepPointer<cliente>>()),datiFiltrati(new Container<deepPointer<cliente>>()),modificato(false)
{
    //carica(path); da implementare, ricordarsi di togliere commento a costruttore di controller che pesca data.xml
    //resetfiltro(); bisognerà implementare il reset filtro!
}

model::~model()
{
    /*
    for (auto it = datiTotali->inizio(); it != datiTotali->fine(); ++it) {
           delete *it;
       }
    // FORSE E' INUTILE DA RICONTROLLARE!!!!
*/
       datiTotali->clear();
       datiFiltrati->clear();

       delete datiTotali;
       delete datiFiltrati;
}

void model::resetfiltro() const
{
    datiFiltrati->clear();
    for(auto it = datiTotali->inizio();it!=datiTotali->fine();++it)
     {
        datiFiltrati->aggiungiDavanti(*it);
    }
}

//void model::aggiungiOggetto(cliente * cliente)
//{
//    modificato = true;
//    datiTotali->aggiungiDavanti(cliente);
//    resetfiltro();
//    emit clienteAggiunto();
//}

void model::salva()
{
    modificato = false;
    QFile file(path);
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    QXmlStreamWriter xw(&file);
    xw.setAutoFormatting(true);
    xw.writeStartDocument();
    xw.writeStartElement("Clienti");
    for (auto it = datiTotali->inizio(); it != datiTotali->fine(); ++it) {

        cliente *cliente = *it;
        xw.writeStartElement("cliente");

        if (dynamic_cast<vip *>(cliente) != nullptr) {
            auto clientevip = dynamic_cast<vip *>(cliente);

            xw.writeAttribute("type", "Vip");
            xw.writeTextElement("corsonuoto", QString::number(clientevip->iscorsonuoto()));  //::number???
            xw.writeTextElement("nomeistruttorepiscina", QString::fromStdString(clientevip->getnomeistruttorepiscina()));
            xw.writeTextElement("scadenzapiscinagiorno", QString::number(clientevip->getGiornoPiscina()));
            xw.writeTextElement("scadenzapiscinamese", QString::number(clientevip->getMesePiscina()));
            xw.writeTextElement("scadenzapiscinaanno", QString::number(clientevip->getAnnoPiscina()));
            xw.writeTextElement("scheda", QString::number(clientevip->isscheda()));  //::number???
            xw.writeTextElement("nomeistruttorepalestra", QString::fromStdString(clientevip->getnomeistruttorepalestra()));
            xw.writeTextElement("scadenzapalestragiorno", QString::number(clientevip->getGiornoPalestra()));
            xw.writeTextElement("scadenzapalestramese", QString::number(clientevip->getMesePalestra()));
            xw.writeTextElement("scadenzapalestraanno", QString::number(clientevip->getAnnoPalestra()));
        }
        else if (dynamic_cast<piscina *>(cliente) != nullptr) {
            auto clientepiscina = dynamic_cast<piscina *>(cliente);

            xw.writeAttribute("type", "Piscina");
            xw.writeTextElement("corsonuoto", QString::number(clientepiscina->iscorsonuoto()));  //::number???
            xw.writeTextElement("nomeistruttorepiscina", QString::fromStdString(clientepiscina->getnomeistruttorepiscina()));
            xw.writeTextElement("scadenzapiscinagiorno", QString::number(clientepiscina->getGiornoPiscina()));
            xw.writeTextElement("scadenzapiscinamese", QString::number(clientepiscina->getMesePiscina()));
            xw.writeTextElement("scadenzapiscinaanno", QString::number(clientepiscina->getAnnoPiscina()));
        }

        else if (dynamic_cast<palestra *>(cliente) != nullptr){
            auto clientepalestra = dynamic_cast<palestra *>(cliente);

            xw.writeAttribute("type", "Palestra");
            xw.writeTextElement("scheda", QString::number(clientepalestra->isscheda()));  //::number???
            xw.writeTextElement("nomeistruttorepalestra", QString::fromStdString(clientepalestra->getnomeistruttorepalestra()));
            xw.writeTextElement("scadenzapalestragiorno", QString::number(clientepalestra->getGiornoPalestra()));
            xw.writeTextElement("scadenzapalestramese", QString::number(clientepalestra->getMesePalestra()));
            xw.writeTextElement("scadenzapalestraanno", QString::number(clientepalestra->getAnnoPalestra()));
        }

//        else {xw.writeAttribute("type", "cliente");} CI SERVE?

        xw.writeStartElement("clienteInfo");
        xw.writeTextElement("nome", QString::fromStdString(cliente->getnome()));
        xw.writeTextElement("cognome", QString::fromStdString(cliente->getcognome()));
        xw.writeTextElement("giornoN", QString::number(cliente->getGiornoN()));
        xw.writeTextElement("meseN", QString::number(cliente->getMeseN()));
        xw.writeTextElement("annoN", QString::number(cliente->getAnnoN()));
        xw.writeTextElement("codicefiscale", QString::fromStdString(cliente->getcodfiscale()));
        xw.writeTextElement("luogodN", QString::fromStdString(cliente->getluogo()));
        xw.writeTextElement("residenza", QString::fromStdString(cliente->getres()));
        xw.writeTextElement("via", QString::fromStdString(cliente->getvia()));
        xw.writeTextElement("numvia", QString::number(cliente->getnum()));
        xw.writeTextElement("numerotel", QString::fromStdString(cliente->getnumerotel()));
        xw.writeTextElement("mail", QString::fromStdString(cliente->getmail()));
        xw.writeTextElement("student", QString::number(cliente->getstudent()));
        xw.writeEndElement();
    }

    xw.writeEndElement();
    xw.writeEndDocument();

    file.close();
}

void model::carica(QString path) const
{
    QFile file(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QDomDocument r;
    r.setContent(&file);

    QDomNodeList clienti = r.elementsByTagName("Clienti");
    for (int i = 0; i < clienti.size(); i++) {
        cliente *res = nullptr;
        QDomNode clienteNode = clienti.item(i);
        QDomElement clienteElem = clienteNode.toElement();

        QDomNode clienteInfo = clienteNode.firstChildElement("clienteInfo"); //dopo guardare come lo chiameremo su salva!

        QDomElement nomeElem = clienteInfo.firstChildElement("nome");
        QDomElement cognomeElem = clienteInfo.firstChildElement("cognome");
        QDomElement dataNascitaGiornoElem = clienteInfo.firstChildElement("giornoN"); //pesco i tre interi della data per ricreare la QDate
        QDomElement dataNascitaMeseElem = clienteInfo.firstChildElement("meseN");
        QDomElement dataNascitaAnnoElem = clienteInfo.firstChildElement("annoN");
        QDomElement codicefiscaleElem = clienteInfo.firstChildElement("codicefiscale");
        QDomElement luogodNElem = clienteInfo.firstChildElement("luogodN");
        QDomElement residenzaElem = clienteInfo.firstChildElement("residenza");
        QDomElement viaElem = clienteInfo.firstChildElement("via");
        QDomElement numviaElem = clienteInfo.firstChildElement("numvia");
        QDomElement numerotelElem = clienteInfo.firstChildElement("numerotel");
        QDomElement mailElem = clienteInfo.firstChildElement("mail");
        QDomElement studentElem = clienteInfo.firstChildElement("student");

        std::string nome = nomeElem.text().toStdString();
        std::string cognome = cognomeElem.text().toStdString();
        //unsigned short int dataNascitaGiorno = dataNascitaGiornoElem.text().toUInt(); PRIMA L'AVEVO MESSO COSì, STATIC CAST PROBABILMENTE PER CASTARE DA INT A UNSIGNED SHORT INT
        unsigned short int dataNascitaGiorno = static_cast<unsigned int>(dataNascitaGiornoElem.text().toInt()); //ho messo uint vedere se è giusto
        unsigned short int dataNascitaMese = static_cast<unsigned int>(dataNascitaMeseElem.text().toInt());
        unsigned short int dataNascitaAnno = static_cast<unsigned int>(dataNascitaAnnoElem.text().toInt());
        std::string codicefiscale = codicefiscaleElem.text().toStdString();
        std::string luogodN = luogodNElem.text().toStdString();
        std::string residenza = residenzaElem.text().toStdString();
        std::string via = viaElem.text().toStdString();
        unsigned short int numvia = static_cast<unsigned int>(numviaElem.text().toInt());
        std::string numerotel = numerotelElem.text().toStdString();
        std::string mail = mailElem.text().toStdString();
        bool student = studentElem.text().toInt() == 1; //checkbox

        auto elemType = clienteElem.attribute("type"); //questo dovrebbe essere il nostro tipo abbonamento
        if (elemType == "Piscina") {
            QDomElement corsonuotoElem = clienteElem.firstChildElement("corsonuoto");
            QDomElement nomeistruttorepiscinaElem = clienteElem.firstChildElement("nomeistruttorepiscina");
            QDomElement scadenzaPiscinaGiornoElem = clienteInfo.firstChildElement("scadenzapiscinagiorno");
            QDomElement scadenzaPiscinaMeseElem = clienteInfo.firstChildElement("scadenzapiscinamese");
            QDomElement scadenzaPiscinaAnnoElem = clienteInfo.firstChildElement("scadenzapiscinaanno");
            bool corsonuoto = studentElem.text().toUInt()== 1;
            std::string nomeistruttorepiscina = nomeistruttorepiscinaElem.text().toStdString();
            unsigned short int scadenzaPiscinaGiorno = static_cast<unsigned int>(scadenzaPiscinaGiornoElem.text().toInt());
            unsigned short int scadenzaPiscinaMese = static_cast<unsigned int>(scadenzaPiscinaMeseElem.text().toInt());
            unsigned short int scadenzaPiscinaAnno = static_cast<unsigned int>(scadenzaPiscinaAnnoElem.text().toInt());

            res = new piscina(nome, cognome, dataNascitaGiorno, dataNascitaMese, dataNascitaAnno,codicefiscale,luogodN,residenza,via,numvia,numerotel,mail,student,corsonuoto,nomeistruttorepiscina,scadenzaPiscinaGiorno,scadenzaPiscinaMese,scadenzaPiscinaAnno);


        } else if (elemType == "Palestra") {
            QDomElement schedaElem = clienteElem.firstChildElement("scheda");
            QDomElement nomeistruttorepalestraElem = clienteElem.firstChildElement("nomeistruttorepalestra");
            QDomElement scadenzaPalestraGiornoElem = clienteInfo.firstChildElement("scadenzapalestragiorno");
            QDomElement scadenzaPalestraMeseElem = clienteInfo.firstChildElement("scadenzapalestramese");
            QDomElement scadenzaPalestraAnnoElem = clienteInfo.firstChildElement("scadenzapalestraanno");
            bool scheda = studentElem.text().toUInt()== 1;
            std::string nomeistruttorepalestra = nomeistruttorepalestraElem.text().toStdString();
            unsigned short int scadenzaPalestraGiorno = static_cast<unsigned int>(scadenzaPalestraGiornoElem.text().toInt());
            unsigned short int scadenzaPalestraMese = static_cast<unsigned int>(scadenzaPalestraMeseElem.text().toInt());
            unsigned short int scadenzaPalestraAnno = static_cast<unsigned int>(scadenzaPalestraAnnoElem.text().toInt());

            res = new palestra(nome, cognome, dataNascitaGiorno, dataNascitaMese, dataNascitaAnno,codicefiscale,luogodN,residenza,via,numvia,numerotel,mail,student,scheda,nomeistruttorepalestra,scadenzaPalestraGiorno,scadenzaPalestraMese,scadenzaPalestraAnno);


        } else if (elemType == "Vip") {

            QDomElement corsonuotoElem = clienteElem.firstChildElement("corsonuoto");
            QDomElement nomeistruttorepiscinaElem = clienteElem.firstChildElement("nomeistruttorepiscina");
            QDomElement scadenzaPiscinaGiornoElem = clienteInfo.firstChildElement("scadenzapiscinagiorno");
            QDomElement scadenzaPiscinaMeseElem = clienteInfo.firstChildElement("scadenzapiscinamese");
            QDomElement scadenzaPiscinaAnnoElem = clienteInfo.firstChildElement("scadenzapiscinaanno");
            QDomElement schedaElem = clienteElem.firstChildElement("scheda");
            QDomElement nomeistruttorepalestraElem = clienteElem.firstChildElement("nomeistruttorepalestra");
            QDomElement scadenzaPalestraGiornoElem = clienteInfo.firstChildElement("scadenzapalestragiorno");
            QDomElement scadenzaPalestraMeseElem = clienteInfo.firstChildElement("scadenzapalestramese");
            QDomElement scadenzaPalestraAnnoElem = clienteInfo.firstChildElement("scadenzapalestraanno");
            bool corsonuoto = studentElem.text().toUInt()== 1;
            std::string nomeistruttorepiscina = nomeistruttorepiscinaElem.text().toStdString();
            unsigned short int scadenzaPiscinaGiorno = static_cast<unsigned int>(scadenzaPiscinaGiornoElem.text().toInt());
            unsigned short int scadenzaPiscinaMese = static_cast<unsigned int>(scadenzaPiscinaMeseElem.text().toInt());
            unsigned short int scadenzaPiscinaAnno = static_cast<unsigned int>(scadenzaPiscinaAnnoElem.text().toInt());
            bool scheda = studentElem.text().toUInt()== 1;
            std::string nomeistruttorepalestra = nomeistruttorepalestraElem.text().toStdString();
            unsigned short int scadenzaPalestraGiorno = static_cast<unsigned int>(scadenzaPalestraGiornoElem.text().toInt());
            unsigned short int scadenzaPalestraMese = static_cast<unsigned int>(scadenzaPalestraMeseElem.text().toInt());
            unsigned short int scadenzaPalestraAnno = static_cast<unsigned int>(scadenzaPalestraAnnoElem.text().toInt());

            res = new vip(nome, cognome, dataNascitaGiorno, dataNascitaMese, dataNascitaAnno,codicefiscale,luogodN,residenza,via,numvia,numerotel,mail,student,corsonuoto,nomeistruttorepiscina,scadenzaPiscinaGiorno,scadenzaPiscinaMese,scadenzaPiscinaAnno,scheda,nomeistruttorepalestra,scadenzaPalestraGiorno,scadenzaPalestraMese,scadenzaPalestraAnno);

        } else {
            continue;
        }

        datiTotali->aggiungiDavanti(res);
    }

}

QStringList model::getCampiCliente(const unsigned int indice) const
{
    QStringList tmp;
    cliente * clienteTmp = static_cast<cliente*>(&(*(datiTotali->prendiNodoIndice(indice)))); //capire se è corretto inserire static cast o no!
    tmp.push_back(QString::fromStdString(clienteTmp->getnome()));
    tmp.push_back(QString::fromStdString(clienteTmp->getcognome()));
    tmp.push_back(QString::fromStdString(clienteTmp->getcodfiscale()));
    tmp.push_back(QString::fromStdString(clienteTmp->getluogo()));
    tmp.push_back(QString::fromStdString(clienteTmp->getres()));
    tmp.push_back(QString::fromStdString(clienteTmp->getvia()));
    tmp.push_back(QString::number(clienteTmp->getnum()));
    tmp.push_back(QString::fromStdString(clienteTmp->getnumerotel()));
    tmp.push_back(QString::fromStdString(clienteTmp->getmail()));
    tmp.push_back(clienteTmp->getDataN().toString());
    tmp.push_back(clienteTmp->getstudent()? "true":"false");


    if(dynamic_cast<vip*>(&(*(datiTotali->prendiNodoIndice(indice))))){

        tmp.push_back(dynamic_cast<vip*>(&(*(datiTotali->prendiNodoIndice(indice))))->getDataPiscina().toString());
        tmp.push_back(QString::fromStdString(dynamic_cast<vip*>(&(*(datiTotali->prendiNodoIndice(indice))))->getnomeistruttorepiscina()));
        tmp.push_back(dynamic_cast<vip*>(&(*(datiTotali->prendiNodoIndice(indice))))->iscorsonuoto()? "true":"false");
        tmp.push_back(dynamic_cast<vip*>(&(*(datiTotali->prendiNodoIndice(indice))))->getDataPalestra().toString());
        tmp.push_back(QString::fromStdString(dynamic_cast<vip*>(&(*(datiTotali->prendiNodoIndice(indice))))->getnomeistruttorepalestra()));
        tmp.push_back(dynamic_cast<vip*>(&(*(datiTotali->prendiNodoIndice(indice))))->isscheda()? "true":"false");
        tmp.push_back("true");
        tmp.push_back("true");

    }

   else if(dynamic_cast<piscina*>(&(*(datiTotali->prendiNodoIndice(indice))))){

       tmp.push_back(dynamic_cast<piscina*>(&(*(datiTotali->prendiNodoIndice(indice))))->getDataPiscina().toString());
       tmp.push_back(QString::fromStdString(dynamic_cast<piscina*>(&(*(datiTotali->prendiNodoIndice(indice))))->getnomeistruttorepiscina()));
       tmp.push_back(dynamic_cast<piscina*>(&(*(datiTotali->prendiNodoIndice(indice))))->iscorsonuoto()? "true":"false");
       tmp.push_back(QDate().toString());
       tmp.push_back(QString::fromStdString(""));
       tmp.push_back("false");
       tmp.push_back("true");
       tmp.push_back("false");

   }
   else if(dynamic_cast<palestra*>(&(*(datiTotali->prendiNodoIndice(indice))))){

       tmp.push_back(QDate().toString());
       tmp.push_back(QString::fromStdString(""));
       tmp.push_back("false");
       tmp.push_back(dynamic_cast<palestra*>(&(*(datiTotali->prendiNodoIndice(indice))))->getDataPalestra().toString());
       tmp.push_back(QString::fromStdString(dynamic_cast<palestra*>(&(*(datiTotali->prendiNodoIndice(indice))))->getnomeistruttorepalestra()));
       tmp.push_back(dynamic_cast<palestra*>(&(*(datiTotali->prendiNodoIndice(indice))))->isscheda()? "true":"false");
       tmp.push_back("false");
       tmp.push_back("true");

       }
//    else
//        tmp.push_back("null");
   return tmp;
}

QStringList model::getListaClientiFiltrata(const QString filter, QMap<unsigned int, unsigned int>& indexMapper) const
{
    QStringList ret;
    QString cliente; //era etichetta
    QRegExp regex(filter,Qt::CaseInsensitive, QRegExp::Wildcard); //sta pescando i dati filtrati da qui, forse non serve datiFiltrati come container! regexp fa pattern matching! CAPIRE SE è POSSIBILE USARLO PERCHè è UNA CLASSE DI QT NEL MODEL! Però in teoria sì perchè non è una cosa grafica
    auto it=datiTotali->inizio();
    unsigned int count=0;
    if(!datiTotali->isEmpty()){ //NON SO SE SIA GIUSTO COSì IS EMPTY PER COM'é IMPLEMENTATO DENTRO A CONTAINER!
        while(it!=datiTotali->fine()){
            cliente = (QString::fromStdString((*(*it)).getnome() + " " + (*(*it)).getcognome()) + " ");
            if(cliente.contains(regex)){
                indexMapper.insert((uint)ret.count(),count);
//                if(dynamic_cast<const Consumable*>(&(*(*it)))) CAPIRE SE POTREBBE SERVIRE PER QUALCOSA QUESTO DYNAMIC CAST
//                    cliente += (QString::fromStdString(dynamic_cast<const Consumable*>(&(*(*it)))->getColorName()));
                ret.push_back(cliente);
            }
            count++;
            ++it;
        }
    }

    return ret;
}

void model::rimuoviCliente(const unsigned int i)
{
    datiTotali->rimuoviIndice(i); //era removeOneAtIndex
    emit clienteRimosso();
}

deepPointer<cliente> model::mostraCliente(const unsigned int i)
{
    deepPointer<cliente> clienteDaVisualizzare;
    clienteDaVisualizzare = (datiTotali->prendiNodoIndice(i));
    return clienteDaVisualizzare;
}



//void addClientWindow::confirm() COPIA DA CANCELLARE!
//{
//    QStringList *tmp = new QStringList();
//    0tmp->push_back(nomeLineEdit->text());
//    1tmp->push_back(cognomeLineEdit->text());
//    2tmp->push_back(codFiscLineEdit->text());
//    3tmp->push_back(ldnLineEdit->text());
//    4tmp->push_back(residenzaLineEdit->text());
//    5tmp->push_back(viaLineEdit->text());
//    6tmp->push_back(numeroviaLineEdit->text()); //guardare come si chiamerà di preciso
//    7tmp->push_back(telefonoLineEdit->text());
//    8tmp->push_back(mailLineEdit->text());
//    9tmp->push_back(dateNascita->date().toString());
//    10tmp->push_back(studenteCheckbox->isChecked()? "true":"false");
//    11tmp->push_back(dateScadPiscina->date().toString());
//    12tmp->push_back(nomeIstruttorePiscinaEdit->text());
//    13tmp->push_back(corsoNuotoCheckbox->isChecked()? "true":"false");
//    14tmp->push_back(dateScadPalestra->date().toString());
//    15tmp->push_back(nomeIstruttorePalestraEdit->text());
//    16tmp->push_back(schedaPalestraCheckbox->isChecked()? "true":"false");
//    emit inviaStringaCliente(*tmp); //era sendItemsDetails
//    this->close();
//}

void model::aggNelContainer(const QStringList e) //bisogna mettere C invece di E come lettera! (c di cliente invece di e di etichetta)
{   //PASSIAMO UN CHECKBOX FLEGGATO SE è STATO SELEZIONATO UNO SPECIFICO ABBONAMENTO PISCINA PALESTRA O VIP, IN BASE A QUELLO CAPIAMO CHE TIPO è
    //modificato = true; commentato per segfault
    //if(e.at(0)!=""){ mettere come controllo se serve!!!
        deepPointer<cliente> cliente;
        QDate dataNascitaTmp = QDate::fromString(e.at(9));
        //è da fare l'inserimento nel container pescando i dati del model!!!
        if (e.at(17) == "true" && e.at(18) == "true") { //VIP
            QDate dataScadPiscinaTmp = QDate::fromString(e.at(11));
            QDate dataScadPalestraTmp = QDate::fromString(e.at(14));
            cliente = new vip(e.at(0).toStdString(),e.at(1).toStdString(),dataNascitaTmp.year(),dataNascitaTmp.month(),dataNascitaTmp.day(),e.at(2).toStdString(), e.at(3).toStdString(),e.at(4).toStdString(),e.at(5).toStdString(),e.at(6).toUInt(),e.at(7).toStdString(),e.at(8).toStdString(),e.at(10)=="true" ? true:false,e.at(13)=="true" ? true:false,e.at(12).toStdString(),dataScadPiscinaTmp.year(),dataScadPiscinaTmp.month(),dataScadPiscinaTmp.day(),e.at(16)=="true" ? true:false,e.at(15).toStdString(),dataScadPalestraTmp.year(),dataScadPalestraTmp.month(),dataScadPalestraTmp.day());
        }
        else if(e.at(17) == "true" && e.at(18) == "false"){ // piscina, sistemare controllo piscina bisogna mettere if esiste data scadenza
            QDate dataScadPiscinaTmp = QDate::fromString(e.at(11));
            cliente = new piscina(e.at(0).toStdString(),e.at(1).toStdString(),dataNascitaTmp.year(),dataNascitaTmp.month(),dataNascitaTmp.day(),e.at(2).toStdString(), e.at(3).toStdString(),e.at(4).toStdString(),e.at(5).toStdString(),e.at(6).toUInt(),e.at(7).toStdString(),e.at(8).toStdString(),e.at(10)=="true" ? true:false,e.at(13)=="true" ? true:false,e.at(12).toStdString(),dataScadPiscinaTmp.year(),dataScadPiscinaTmp.month(),dataScadPiscinaTmp.day());
        }
        else if (e.at(17) == "false" && e.at(18) == "true") { //palestra, mettere solo else senza controllo se viene fatto in fase di input(confirm qdialog)
            QDate dataScadPalestraTmp = QDate::fromString(e.at(14));
            cliente = new palestra(e.at(0).toStdString(),e.at(1).toStdString(),dataNascitaTmp.year(),dataNascitaTmp.month(),dataNascitaTmp.day(),e.at(2).toStdString(), e.at(3).toStdString(),e.at(4).toStdString(),e.at(5).toStdString(),e.at(6).toUInt(),e.at(7).toStdString(),e.at(8).toStdString(),e.at(10)=="true" ? true:false,e.at(16)=="true" ? true:false,e.at(15).toStdString(),dataScadPalestraTmp.year(),dataScadPalestraTmp.month(),dataScadPalestraTmp.day());
        }
        datiTotali->aggiungiDavanti(cliente); //capire se mettere pushinorder o riordinarli col filtraggio
        //resetfiltro(); //mettere in ordine col filtraggio, bisognerà sistemare la sua implementazione!!! capire se serve perchè abbiamo implementato il filtraggio di gotta
    //}

        emit clienteAggiunto();
}

void model::modificaItem(const unsigned int indice, const QStringList e)               //è una copia di aggNelContainer a cui cambia qualcosina minuscola
{
    deepPointer<cliente> cliente;
    QDate dataNascitaTmp = QDate::fromString(e.at(9));
    //è da fare l'inserimento nel container pescando i dati del model!!!
    if (e.at(17) == "true" && e.at(18) == "true") { //VIP
        QDate dataScadPiscinaTmp = QDate::fromString(e.at(11));
        QDate dataScadPalestraTmp = QDate::fromString(e.at(14));
        cliente = new vip(e.at(0).toStdString(),e.at(1).toStdString(),dataNascitaTmp.year(),dataNascitaTmp.month(),dataNascitaTmp.day(),e.at(2).toStdString(), e.at(3).toStdString(),e.at(4).toStdString(),e.at(5).toStdString(),e.at(6).toUInt(),e.at(7).toStdString(),e.at(8).toStdString(),e.at(10)=="true" ? true:false,e.at(13)=="true" ? true:false,e.at(12).toStdString(),dataScadPiscinaTmp.year(),dataScadPiscinaTmp.month(),dataScadPiscinaTmp.day(),e.at(16)=="true" ? true:false,e.at(15).toStdString(),dataScadPalestraTmp.year(),dataScadPalestraTmp.month(),dataScadPalestraTmp.day());
    }
    else if(e.at(17) == "true" && e.at(18) == "false"){ // piscina, sistemare controllo piscina bisogna mettere if esiste data scadenza
        QDate dataScadPiscinaTmp = QDate::fromString(e.at(11));
        cliente = new piscina(e.at(0).toStdString(),e.at(1).toStdString(),dataNascitaTmp.year(),dataNascitaTmp.month(),dataNascitaTmp.day(),e.at(2).toStdString(), e.at(3).toStdString(),e.at(4).toStdString(),e.at(5).toStdString(),e.at(6).toUInt(),e.at(7).toStdString(),e.at(8).toStdString(),e.at(10)=="true" ? true:false,e.at(13)=="true" ? true:false,e.at(12).toStdString(),dataScadPiscinaTmp.year(),dataScadPiscinaTmp.month(),dataScadPiscinaTmp.day());
    }
    else if (e.at(17) == "false" && e.at(18) == "true") { //palestra, mettere solo else senza controllo se viene fatto in fase di input(confirm qdialog)
        QDate dataScadPalestraTmp = QDate::fromString(e.at(14));
        cliente = new palestra(e.at(0).toStdString(),e.at(1).toStdString(),dataNascitaTmp.year(),dataNascitaTmp.month(),dataNascitaTmp.day(),e.at(2).toStdString(), e.at(3).toStdString(),e.at(4).toStdString(),e.at(5).toStdString(),e.at(6).toUInt(),e.at(7).toStdString(),e.at(8).toStdString(),e.at(10)=="true" ? true:false,e.at(16)=="true" ? true:false,e.at(15).toStdString(),dataScadPalestraTmp.year(),dataScadPalestraTmp.month(),dataScadPalestraTmp.day());
    }
    datiTotali->rimpiazzaFinale (indice, cliente);
}
