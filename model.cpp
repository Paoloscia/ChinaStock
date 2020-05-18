#include "model.h"
model::model(QString path) : path(path),datiTotali(new Container<deepPointer<cliente>>()),datiFiltrati(new Container<deepPointer<cliente>>()),modificato(false)
{
    carica(path);
    resetfiltro();
}

model::~model()
{
    datiTotali->clear();
    datiFiltrati->clear();
    delete datiTotali;
    delete datiFiltrati;
}

void model::resetfiltro()
{
    emit resetColoreFiltroM();
    datiFiltrati->clear();
    for(auto it = datiTotali->inizio();it!=datiTotali->fine();++it)
    {
        datiFiltrati->aggInOrdine(*it);
    }
}

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
            xw.writeTextElement("corsonuoto", QString::number(clientevip->iscorsonuoto()));
            xw.writeTextElement("nomeistruttorepiscina", QString::fromStdString(clientevip->getnomeistruttorepiscina()));
            xw.writeTextElement("scadenzapiscinagiorno", QString::number(clientevip->getGiornoPiscina()));
            xw.writeTextElement("scadenzapiscinamese", QString::number(clientevip->getMesePiscina()));
            xw.writeTextElement("scadenzapiscinaanno", QString::number(clientevip->getAnnoPiscina()));
            xw.writeTextElement("scheda", QString::number(clientevip->isscheda()));
            xw.writeTextElement("nomeistruttorepalestra", QString::fromStdString(clientevip->getnomeistruttorepalestra()));
            xw.writeTextElement("scadenzapalestragiorno", QString::number(clientevip->getGiornoPalestra()));
            xw.writeTextElement("scadenzapalestramese", QString::number(clientevip->getMesePalestra()));
            xw.writeTextElement("scadenzapalestraanno", QString::number(clientevip->getAnnoPalestra()));
        }
        else if (dynamic_cast<piscina *>(cliente) != nullptr) {
            auto clientepiscina = dynamic_cast<piscina *>(cliente);

            xw.writeAttribute("type", "Piscina");
            xw.writeTextElement("corsonuoto", QString::number(clientepiscina->iscorsonuoto()));
            xw.writeTextElement("nomeistruttorepiscina", QString::fromStdString(clientepiscina->getnomeistruttorepiscina()));
            xw.writeTextElement("scadenzapiscinagiorno", QString::number(clientepiscina->getGiornoPiscina()));
            xw.writeTextElement("scadenzapiscinamese", QString::number(clientepiscina->getMesePiscina()));
            xw.writeTextElement("scadenzapiscinaanno", QString::number(clientepiscina->getAnnoPiscina()));
        }

        else if (dynamic_cast<palestra *>(cliente) != nullptr){
            auto clientepalestra = dynamic_cast<palestra *>(cliente);

            xw.writeAttribute("type", "Palestra");
            xw.writeTextElement("scheda", QString::number(clientepalestra->isscheda()));
            xw.writeTextElement("nomeistruttorepalestra", QString::fromStdString(clientepalestra->getnomeistruttorepalestra()));
            xw.writeTextElement("scadenzapalestragiorno", QString::number(clientepalestra->getGiornoPalestra()));
            xw.writeTextElement("scadenzapalestramese", QString::number(clientepalestra->getMesePalestra()));
            xw.writeTextElement("scadenzapalestraanno", QString::number(clientepalestra->getAnnoPalestra()));
        }

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
        xw.writeTextElement("numvia", QString::fromStdString(cliente->getnum()));
        xw.writeTextElement("numerotel", QString::fromStdString(cliente->getnumerotel()));
        xw.writeTextElement("mail", QString::fromStdString(cliente->getmail()));
        xw.writeTextElement("student", QString::number(cliente->getstudent()));
        xw.writeEndElement();
        xw.writeEndElement();
    }

    xw.writeEndElement();
    xw.writeEndDocument();

    file.close();
}

bool model::getModificato() const
{
    return modificato;
}

void model::carica(QString path)
{
    string tmp = path.toStdString();

    QFile file(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QDomDocument r;
    r.setContent(&file);

    QDomNodeList clienti = r.elementsByTagName("cliente");
    for (int i = 0; i < clienti.size(); i++) {
        cliente *res = nullptr;
        QDomNode clienteNode = clienti.item(i);
        QDomElement clienteElem = clienteNode.toElement();

        QDomNode clienteInfo = clienteNode.firstChildElement("clienteInfo");

        QDomElement nomeElem = clienteInfo.firstChildElement("nome");
        QDomElement cognomeElem = clienteInfo.firstChildElement("cognome");
        QDomElement dataNascitaGiornoElem = clienteInfo.firstChildElement("giornoN");
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
        int dataNascitaGiorno = (dataNascitaGiornoElem.text().toInt());
        int dataNascitaMese = (dataNascitaMeseElem.text().toInt());
        int dataNascitaAnno = (dataNascitaAnnoElem.text().toInt());
        std::string codicefiscale = codicefiscaleElem.text().toStdString();
        std::string luogodN = luogodNElem.text().toStdString();
        std::string residenza = residenzaElem.text().toStdString();
        std::string via = viaElem.text().toStdString();
        std::string numvia = numviaElem.text().toStdString();
        std::string numerotel = numerotelElem.text().toStdString();
        std::string mail = mailElem.text().toStdString();
        bool student = studentElem.text().toUInt() == 1;

        auto elemType = clienteElem.attribute("type");
        if (elemType == "Piscina") {
            QDomElement corsonuotoElem = clienteElem.firstChildElement("corsonuoto");
            QDomElement nomeistruttorepiscinaElem = clienteElem.firstChildElement("nomeistruttorepiscina");
            QDomElement scadenzaPiscinaGiornoElem = clienteElem.firstChildElement("scadenzapiscinagiorno");
            QDomElement scadenzaPiscinaMeseElem = clienteElem.firstChildElement("scadenzapiscinamese");
            QDomElement scadenzaPiscinaAnnoElem = clienteElem.firstChildElement("scadenzapiscinaanno");
            bool corsonuoto = corsonuotoElem.text().toUInt()== 1;
            std::string nomeistruttorepiscina = nomeistruttorepiscinaElem.text().toStdString();
            int scadenzaPiscinaGiorno = (scadenzaPiscinaGiornoElem.text().toInt());
            int scadenzaPiscinaMese = (scadenzaPiscinaMeseElem.text().toInt());
            int scadenzaPiscinaAnno = (scadenzaPiscinaAnnoElem.text().toInt());
            res = new piscina(nome, cognome,dataNascitaAnno, dataNascitaMese, dataNascitaGiorno,codicefiscale,luogodN,residenza,via,numvia,numerotel,mail,student,corsonuoto,nomeistruttorepiscina,scadenzaPiscinaAnno,scadenzaPiscinaMese,scadenzaPiscinaGiorno);


        } else if (elemType == "Palestra") {
            QDomElement schedaElem = clienteElem.firstChildElement("scheda");
            QDomElement nomeistruttorepalestraElem = clienteElem.firstChildElement("nomeistruttorepalestra");
            QDomElement scadenzaPalestraGiornoElem = clienteElem.firstChildElement("scadenzapalestragiorno");
            QDomElement scadenzaPalestraMeseElem = clienteElem.firstChildElement("scadenzapalestramese");
            QDomElement scadenzaPalestraAnnoElem = clienteElem.firstChildElement("scadenzapalestraanno");
            bool scheda = schedaElem.text().toUInt()== 1;
            std::string nomeistruttorepalestra = nomeistruttorepalestraElem.text().toStdString();
            int scadenzaPalestraGiorno = (scadenzaPalestraGiornoElem.text().toInt());
            int scadenzaPalestraMese = (scadenzaPalestraMeseElem.text().toInt());
            int scadenzaPalestraAnno = (scadenzaPalestraAnnoElem.text().toInt());

            res = new palestra(nome, cognome, dataNascitaAnno, dataNascitaMese, dataNascitaGiorno,codicefiscale,luogodN,residenza,via,numvia,numerotel,mail,student,scheda,nomeistruttorepalestra,scadenzaPalestraAnno,scadenzaPalestraMese,scadenzaPalestraGiorno);


        } else if (elemType == "Vip") {

            QDomElement corsonuotoElem = clienteElem.firstChildElement("corsonuoto");
            QDomElement nomeistruttorepiscinaElem = clienteElem.firstChildElement("nomeistruttorepiscina");
            QDomElement scadenzaPiscinaGiornoElem = clienteElem.firstChildElement("scadenzapiscinagiorno");
            QDomElement scadenzaPiscinaMeseElem = clienteElem.firstChildElement("scadenzapiscinamese");
            QDomElement scadenzaPiscinaAnnoElem = clienteElem.firstChildElement("scadenzapiscinaanno");
            QDomElement schedaElem = clienteElem.firstChildElement("scheda");
            QDomElement nomeistruttorepalestraElem = clienteElem.firstChildElement("nomeistruttorepalestra");
            QDomElement scadenzaPalestraGiornoElem = clienteElem.firstChildElement("scadenzapalestragiorno");
            QDomElement scadenzaPalestraMeseElem = clienteElem.firstChildElement("scadenzapalestramese");
            QDomElement scadenzaPalestraAnnoElem = clienteElem.firstChildElement("scadenzapalestraanno");
            bool corsonuoto = corsonuotoElem.text().toUInt()== 1;
            std::string nomeistruttorepiscina = nomeistruttorepiscinaElem.text().toStdString();
            int scadenzaPiscinaGiorno = (scadenzaPiscinaGiornoElem.text().toInt());
            int scadenzaPiscinaMese = (scadenzaPiscinaMeseElem.text().toInt());
            int scadenzaPiscinaAnno = (scadenzaPiscinaAnnoElem.text().toInt());
            bool scheda = schedaElem.text().toUInt()== 1;
            std::string nomeistruttorepalestra = nomeistruttorepalestraElem.text().toStdString();
            int scadenzaPalestraGiorno = (scadenzaPalestraGiornoElem.text().toInt());
            int scadenzaPalestraMese = (scadenzaPalestraMeseElem.text().toInt());
            int scadenzaPalestraAnno = (scadenzaPalestraAnnoElem.text().toInt());

            res = new vip(nome, cognome, dataNascitaAnno, dataNascitaMese, dataNascitaGiorno,codicefiscale,luogodN,residenza,via,numvia,numerotel,mail,student,corsonuoto,nomeistruttorepiscina,scadenzaPiscinaAnno,scadenzaPiscinaMese,scadenzaPiscinaGiorno,scheda,nomeistruttorepalestra,scadenzaPalestraAnno,scadenzaPalestraMese,scadenzaPalestraGiorno);

        } else {
            continue;
        }

        datiTotali->aggInOrdine(res);
    }

}

QStringList model::getCampiCliente(const unsigned int indice) const
{
    QStringList tmp;
    deepPointer<cliente> clienteTmp = datiFiltrati->prendiNodoIndice(indice);
    tmp.push_back(QString::fromStdString(clienteTmp->getnome()));
    tmp.push_back(QString::fromStdString(clienteTmp->getcognome()));
    tmp.push_back(QString::fromStdString(clienteTmp->getcodfiscale()));
    tmp.push_back(QString::fromStdString(clienteTmp->getluogo()));
    tmp.push_back(QString::fromStdString(clienteTmp->getres()));
    tmp.push_back(QString::fromStdString(clienteTmp->getvia()));
    tmp.push_back(QString::fromStdString(clienteTmp->getnum()));
    tmp.push_back(QString::fromStdString(clienteTmp->getnumerotel()));
    tmp.push_back(QString::fromStdString(clienteTmp->getmail()));
    tmp.push_back(clienteTmp->getDataN().toString());
    tmp.push_back(clienteTmp->getstudent()? "true":"false");

    if(dynamic_cast<vip*>(&(*(clienteTmp))) != nullptr){
        auto clientevip = dynamic_cast<vip*>(&(*(clienteTmp)));
        tmp.push_back(clientevip->getDataPiscina().toString());
        tmp.push_back(QString::fromStdString(clientevip->getnomeistruttorepiscina()));
        tmp.push_back(clientevip->iscorsonuoto()? "true":"false");
        tmp.push_back(clientevip->getDataPalestra().toString());
        tmp.push_back(QString::fromStdString(clientevip->getnomeistruttorepalestra()));
        tmp.push_back(clientevip->isscheda()? "true":"false");
        tmp.push_back("true");
        tmp.push_back("true");
    }
    else if(dynamic_cast<piscina*>(&(*(clienteTmp))) != nullptr){
        auto clientepis = dynamic_cast<piscina*>(&(*(clienteTmp)));
        tmp.push_back(clientepis->getDataPiscina().toString());
        tmp.push_back(QString::fromStdString(clientepis->getnomeistruttorepiscina()));
        tmp.push_back(clientepis->iscorsonuoto()? "true":"false");
        tmp.push_back("Non abbonato");
        tmp.push_back("Non abbonato");
        tmp.push_back("Non abbonato");
        tmp.push_back("true");
        tmp.push_back("false");
    }
    else if(dynamic_cast<palestra*>(&(*(clienteTmp))) != nullptr){
        auto clientepal = dynamic_cast<palestra*>(&(*(clienteTmp)));
        tmp.push_back("Non abbonato");
        tmp.push_back("Non abbonato");
        tmp.push_back("Non abbonato");
        tmp.push_back(clientepal->getDataPalestra().toString());
        tmp.push_back(QString::fromStdString(clientepal->getnomeistruttorepalestra()));
        tmp.push_back(clientepal->isscheda()? "true":"false");
        tmp.push_back("false");
        tmp.push_back("true");
    }
    return tmp;
}

QStringList model::getListaClientiFiltrata(const QString filter, QMap<unsigned int, unsigned int>& indexMapper) const
{
    QStringList ret;
    QString cliente;
    QRegExp regex(filter,Qt::CaseInsensitive, QRegExp::Wildcard);
    auto it=datiFiltrati->inizio();
    unsigned int count=0;
    if(!datiFiltrati->isEmpty()){
        while(it!=datiFiltrati->fine()){
            cliente = (QString::fromStdString((*(*it)).getnome() + " " + (*(*it)).getcognome()));
            if(cliente.contains(regex)){
                indexMapper.insert((uint)ret.count(),count);

                ret.push_back(cliente);
            }
            count++;
            ++it;
        }
    }

    return ret;
}

QStringList model::getListaClientiCsv() const
{
    QStringList ret;
    QString datiCliente;
    auto it=datiTotali->inizio();
    if(!datiTotali->isEmpty()){
        while(it!=datiTotali->fine()){
            datiCliente = (QString::fromStdString((*(*it)).getnome() + "," + (*(*it)).getcognome()+ "," + (*(*it)).getcodfiscale()+ "," + (*(*it)).getluogo()+ "," + (*(*it)).getres()+ "," + (*(*it)).getvia()+ "," + (*(*it)).getnum()+ "," + (*(*it)).getmail())) +","+(*(*it)).getDataN().toString("dd/MM/yyyy");
            if ((*(*it)).getstudent()) datiCliente = datiCliente +",Sì";
            else datiCliente = datiCliente +",No";
            cliente* cliente = *it;
            if (dynamic_cast<vip*>(cliente) != nullptr){
                auto clientevip = dynamic_cast<vip *>(cliente);
                datiCliente = datiCliente +","+clientevip->getDataPiscina().toString("dd/MM/yyyy")+","+QString::fromStdString(clientevip->getnomeistruttorepiscina());
                if (clientevip->iscorsonuoto()) datiCliente = datiCliente +",Sì";
                else datiCliente = datiCliente +",No";
                datiCliente = datiCliente +","+clientevip->getDataPalestra().toString("dd/MM/yyyy")+","+QString::fromStdString(clientevip->getnomeistruttorepalestra());
                if (clientevip->isscheda()) datiCliente = datiCliente +",Sì";
                else datiCliente = datiCliente +",No";
            }
            else if (dynamic_cast<piscina*>(cliente) != nullptr){
                auto clientepis = dynamic_cast<piscina *>(cliente);
                datiCliente = datiCliente +","+clientepis->getDataPiscina().toString("dd/MM/yyyy")+","+QString::fromStdString(clientepis->getnomeistruttorepiscina());
                if (clientepis->iscorsonuoto()) datiCliente = datiCliente +",Sì";
                else datiCliente = datiCliente +",No";
                datiCliente = datiCliente + ",non abbonato,non abbonato,non abbonato";
            }
            else if (dynamic_cast<palestra*>(cliente) != nullptr){
                auto clientepal = dynamic_cast<palestra *>(cliente);
                datiCliente = datiCliente + ",non abbonato,non abbonato,non abbonato";
                datiCliente = datiCliente +","+clientepal->getDataPalestra().toString("dd/MM/yyyy")+","+QString::fromStdString(clientepal->getnomeistruttorepalestra());
                if (clientepal->isscheda()) datiCliente = datiCliente +",Sì";
                else datiCliente = datiCliente +",No";

            }

            ret.push_back(datiCliente);
            ++it;
        }
    }
    return ret;
}

QStringList model::getListaClientiPDF() const
{
    QStringList ret;
    QString datiCliente;
    for(auto it=datiTotali->inizio();it!=datiTotali->fine() && !datiTotali->isEmpty();++it)
    {
        datiCliente =(QString::fromStdString(("N:" +(*(*it)).getnome() + " C: " + (*(*it)).getcognome()+ " CF: " + (*(*it)).getcodfiscale())));
        ret.push_back(datiCliente);

    }

    return ret;

}void model::rimuoviCliente(const unsigned int i)
{
    modificato=true;
    if (datiTotali->prendiNodoIndice(i) == datiFiltrati->prendiNodoIndice(i))
        datiTotali->rimuoviIndice(i);
    else
    {
        const unsigned int iTmp = datiTotali->trovaIndiceNodo(datiFiltrati->prendiNodoIndice(i));
        datiTotali->rimuoviIndice(iTmp);
    }
    resetfiltro();
    emit clienteRimosso();

}

deepPointer<cliente> model::mostraCliente(const unsigned int i) const
{
    deepPointer<cliente> clienteDaVisualizzare;
    clienteDaVisualizzare = (datiFiltrati->prendiNodoIndice(i));
    return clienteDaVisualizzare;
}

deepPointer<cliente> model::mostraClientePDF(const unsigned int i) const
{
    deepPointer<cliente> clienteDaStampare;
    clienteDaStampare = (datiFiltrati->prendiNodoIndice(i));
    return clienteDaStampare;
}

void model::filterPiscina()
{
    datiFiltrati->clear();
    for (auto it = datiTotali->inizio(); it != datiTotali->fine(); ++it) {
        cliente* cliente = *it;
        if (dynamic_cast<piscina*>(cliente) != nullptr){
            datiFiltrati->aggInOrdine(*it);
        }
    }
}

void model::filterPalestra()
{
    datiFiltrati->clear();
    for (auto it = datiTotali->inizio(); it != datiTotali->fine(); ++it) {
        cliente* cliente = *it;
        if (dynamic_cast<palestra*>(cliente) != nullptr){
            datiFiltrati->aggInOrdine(*it);
        }
    }
}

void model::filterMaggiorenne()
{
    datiFiltrati->clear();
    for(auto it = datiTotali->inizio(); it!= datiTotali->fine(); ++it){
        cliente* cliente = *it;
        int year = QDate::currentDate().year();
        int month = QDate::currentDate().month();
        int day = QDate:: currentDate().day();
        if(year-cliente->getAnnoN() > 18)
            datiFiltrati->aggInOrdine(*it);
        else
            if(year-cliente->getAnnoN() == 18 && cliente->getMeseN() <= month)
            {
                if(cliente->getMeseN() < month)
                    datiFiltrati->aggInOrdine(*it);

                if(cliente->getMeseN() == month && cliente->getGiornoN() <= day)
                    datiFiltrati->aggInOrdine(*it);
            }


    }
}

void model::filterMinorenne()
{
    datiFiltrati->clear();
    for(auto it = datiTotali->inizio(); it!= datiTotali->fine(); ++it){
        cliente* cliente = *it;
        int year = QDate::currentDate().year();
        int month = QDate::currentDate().month();
        int day = QDate:: currentDate().day();
        if(year-cliente->getAnnoN() < 18)
            datiFiltrati->aggInOrdine(*it);
        else
            if(year-cliente->getAnnoN() == 18 && cliente->getMeseN() >= month)
            {
                if(cliente->getMeseN() > month)
                    datiFiltrati->aggInOrdine(*it);

                if(cliente->getMeseN() == month && cliente->getGiornoN() > day)
                    datiFiltrati->aggInOrdine(*it);
            }


    }
}

void model::filterStudente()
{
    datiFiltrati->clear();
    for(auto it = datiTotali->inizio(); it!= datiTotali->fine(); ++it){
        cliente* cliente = *it;
        if(cliente->getstudent() == true)
            datiFiltrati->aggInOrdine(*it);

    }

}

void model::filterVip()
{
    datiFiltrati->clear();
    for (auto it = datiTotali->inizio(); it != datiTotali->fine(); ++it) {
        cliente* cliente = *it;
        if (dynamic_cast<vip*>(cliente) != nullptr){
            datiFiltrati->aggInOrdine(*it);
        }
    }
}



void model::filterCorsoPiscina()
{
    datiFiltrati->clear();
    for (auto it = datiTotali->inizio(); it != datiTotali->fine(); ++it) {
        cliente* cliente = *it;
        if (dynamic_cast<piscina*>(cliente) != nullptr){
            piscina* x = dynamic_cast<piscina*>(cliente);
            if(x->iscorsonuoto())
                datiFiltrati->aggInOrdine(*it);
        }
    }
}

void model::filterSchedaPalestra()
{
    datiFiltrati->clear();
    for (auto it = datiTotali->inizio(); it != datiTotali->fine(); ++it) {
        cliente* cliente = *it;
        if (dynamic_cast<palestra*>(cliente) != nullptr){
            palestra* x = dynamic_cast<palestra*>(cliente);
            if(x->isscheda())
                datiFiltrati->aggInOrdine(*it);

        }
    }
}

void model::aggNelContainer(const QStringList c)
{
    modificato=true;
    deepPointer<cliente> cliente;
    QDate dataNascitaTmp = QDate::fromString(c.at(9));
    if (c.at(17) == "true" && c.at(18) == "true") {
        QDate dataScadPiscinaTmp = QDate::fromString(c.at(11));
        QDate dataScadPalestraTmp = QDate::fromString(c.at(14));
        cliente = new vip(c.at(0).toStdString(),c.at(1).toStdString(),dataNascitaTmp.year(),dataNascitaTmp.month(),dataNascitaTmp.day(),c.at(2).toStdString(), c.at(3).toStdString(),c.at(4).toStdString(),c.at(5).toStdString(),c.at(6).toStdString(),c.at(7).toStdString(),c.at(8).toStdString(),c.at(10)=="true" ? true:false,c.at(13)=="true" ? true:false,c.at(12).toStdString(),dataScadPiscinaTmp.year(),dataScadPiscinaTmp.month(),dataScadPiscinaTmp.day(),c.at(16)=="true" ? true:false,c.at(15).toStdString(),dataScadPalestraTmp.year(),dataScadPalestraTmp.month(),dataScadPalestraTmp.day());
    }
    else if(c.at(17) == "true" && c.at(18) == "false"){
        QDate dataScadPiscinaTmp = QDate::fromString(c.at(11));
        cliente = new piscina(c.at(0).toStdString(),c.at(1).toStdString(),dataNascitaTmp.year(),dataNascitaTmp.month(),dataNascitaTmp.day(),c.at(2).toStdString(), c.at(3).toStdString(),c.at(4).toStdString(),c.at(5).toStdString(),c.at(6).toStdString(),c.at(7).toStdString(),c.at(8).toStdString(),c.at(10)=="true" ? true:false,c.at(13)=="true" ? true:false,c.at(12).toStdString(),dataScadPiscinaTmp.year(),dataScadPiscinaTmp.month(),dataScadPiscinaTmp.day());
    }
    else if (c.at(17) == "false" && c.at(18) == "true") {
        QDate dataScadPalestraTmp = QDate::fromString(c.at(14));
        cliente = new palestra(c.at(0).toStdString(),c.at(1).toStdString(),dataNascitaTmp.year(),dataNascitaTmp.month(),dataNascitaTmp.day(),c.at(2).toStdString(), c.at(3).toStdString(),c.at(4).toStdString(),c.at(5).toStdString(),c.at(6).toStdString(),c.at(7).toStdString(),c.at(8).toStdString(),c.at(10)=="true" ? true:false,c.at(16)=="true" ? true:false,c.at(15).toStdString(),dataScadPalestraTmp.year(),dataScadPalestraTmp.month(),dataScadPalestraTmp.day());
    }
    datiTotali->aggInOrdine(cliente);
    resetfiltro();
    emit clienteAggiunto();
}

void model::modificaItem(const unsigned int indice, const QStringList c)
{
    modificato=true;
    deepPointer<cliente> cliente;
    QDate dataNascitaTmp = QDate::fromString(c.at(9));
    if (c.at(17) == "true" && c.at(18) == "true") {
        QDate dataScadPiscinaTmp = QDate::fromString(c.at(11));
        QDate dataScadPalestraTmp = QDate::fromString(c.at(14));
        cliente = new vip(c.at(0).toStdString(),c.at(1).toStdString(),dataNascitaTmp.year(),dataNascitaTmp.month(),dataNascitaTmp.day(),c.at(2).toStdString(), c.at(3).toStdString(),c.at(4).toStdString(),c.at(5).toStdString(),c.at(6).toStdString(),c.at(7).toStdString(),c.at(8).toStdString(),c.at(10)=="true" ? true:false,c.at(13)=="true" ? true:false,c.at(12).toStdString(),dataScadPiscinaTmp.year(),dataScadPiscinaTmp.month(),dataScadPiscinaTmp.day(),c.at(16)=="true" ? true:false,c.at(15).toStdString(),dataScadPalestraTmp.year(),dataScadPalestraTmp.month(),dataScadPalestraTmp.day());
    }
    else if(c.at(17) == "true" && c.at(18) == "false"){
        QDate dataScadPiscinaTmp = QDate::fromString(c.at(11));
        cliente = new piscina(c.at(0).toStdString(),c.at(1).toStdString(),dataNascitaTmp.year(),dataNascitaTmp.month(),dataNascitaTmp.day(),c.at(2).toStdString(), c.at(3).toStdString(),c.at(4).toStdString(),c.at(5).toStdString(),c.at(6).toStdString(),c.at(7).toStdString(),c.at(8).toStdString(),c.at(10)=="true" ? true:false,c.at(13)=="true" ? true:false,c.at(12).toStdString(),dataScadPiscinaTmp.year(),dataScadPiscinaTmp.month(),dataScadPiscinaTmp.day());
    }
    else if (c.at(17) == "false" && c.at(18) == "true") {
        QDate dataScadPalestraTmp = QDate::fromString(c.at(14));
        cliente = new palestra(c.at(0).toStdString(),c.at(1).toStdString(),dataNascitaTmp.year(),dataNascitaTmp.month(),dataNascitaTmp.day(),c.at(2).toStdString(), c.at(3).toStdString(),c.at(4).toStdString(),c.at(5).toStdString(),c.at(6).toStdString(),c.at(7).toStdString(),c.at(8).toStdString(),c.at(10)=="true" ? true:false,c.at(16)=="true" ? true:false,c.at(15).toStdString(),dataScadPalestraTmp.year(),dataScadPalestraTmp.month(),dataScadPalestraTmp.day());
    }

    if (datiTotali->prendiNodoIndice(indice) == datiFiltrati->prendiNodoIndice(indice))
        datiTotali->rimpiazzaFinale (indice, cliente);
    else
    {
        const unsigned int iTmp = datiTotali->trovaIndiceNodo(datiFiltrati->prendiNodoIndice(indice));
        datiTotali->rimpiazzaFinale (iTmp, cliente);
    }

    resetfiltro();
}
