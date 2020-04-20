#include "model.h"

model::model(QString path) : path(path),datiTotali(new Container<cliente*>()),datiFiltrati(new Container<cliente*>()),modificato(false)
{
    //carica(path); era load
    resetfiltro();
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

void model::aggiungiOggetto(cliente * cliente)
{
    modificato = true;
    datiTotali->aggiungiDavanti(cliente);
    resetfiltro();

}

void model::salva()
{
//    modificato = false;
//    QFile file(path);
//    file.open(QIODevice::WriteOnly | QIODevice::Text);

//    QXmlStreamWriter xw(&file);
//    xw.setAutoFormatting(true);
//    xw.writeStartDocument();
//    xw.writeStartElement("Clienti");
//    for (auto it = datiTotali->inizio(); it != datiTotali->fine(); ++it) {

//        cliente *cliente = *it;
//        xw.writeStartElement("cliente");


//        if (dynamic_cast<SharedRoom *>(cliente) != nullptr) {
//            auto shared = static_cast<SharedRoom *>(cliente);

//            xw.writeAttribute("type", "SharedRoom");
//            xw.writeTextElement("NBeds", QString::number(shared->getNBeds()));
//            xw.writeTextElement("PricePerBed", QString::number(shared->getPricePerBed()));

//        } else if (dynamic_cast<PrivateRoom *>(cliente)) {
//            if (dynamic_cast<HotelRoom *>(cliente)) {
//                auto hotel = static_cast<HotelRoom *>(cliente);

//                xw.writeAttribute("type", "HotelRoom");
//                xw.writeStartElement("HotelInfo");
//                xw.writeTextElement("HotelName", QString::fromStdString(hotel->getHotelName()));
//                xw.writeTextElement("Tax", QString::number(hotel->getTax()));
//                xw.writeTextElement("HotelStar", QString::number(hotel->getStars()));
//                xw.writeEndElement();

//            } else {
//                xw.writeAttribute("type", "PrivateRoom");
//            }
//            auto privateRoom = static_cast<PrivateRoom *>(cliente);
//            xw.writeStartElement("Rooms");

//            auto roomlist = privateRoom->getRooms();
//            for (auto rit = roomlist.begin(); rit != roomlist.end(); ++rit) {
//                xw.writeStartElement("Room");

//                xw.writeTextElement("NBeds", QString::number((*rit).getNBeds()));
//                xw.writeTextElement("Price", QString::number((*rit).getPrice()));
//                xw.writeTextElement("Quantity", QString::number((*rit).getQuantity()));

//                xw.writeEndElement();
//            }
//            xw.writeEndElement();
//        } else if (dynamic_cast<AllHouse *>(cliente)) {
//            auto allhouse = static_cast<AllHouse *>(cliente);
//            xw.writeAttribute("type", "AllHouse");
//            xw.writeTextElement("Price", QString::number(allhouse->getPrice()));
//            xw.writeTextElement("Mq", QString::number(allhouse->getMq()));
//            xw.writeTextElement("Floors", QString::number(allhouse->getNFloors()));
//            xw.writeTextElement("NBeds", QString::number(allhouse->getNBeds()));
//            xw.writeTextElement("CleaningPrice", QString::number(allhouse->getCleaningPrice()));
//            xw.writeTextElement("CanTakeOnCleaning", QString::number(allhouse->getCanGuestTakeOnCleaning()));

//        }

//        xw.writeStartElement("BaseInfo");
//        xw.writeTextElement("Id", QString::fromStdString(cliente->getId()));
//        xw.writeTextElement("Name", QString::fromStdString(cliente->getName()));
//        xw.writeTextElement("City", QString::fromStdString(cliente->getCity()));
//        xw.writeTextElement("Address", QString::fromStdString(cliente->getAddress()));
//        xw.writeTextElement("Description", QString::fromStdString(cliente->getDescription()));

//        xw.writeStartElement("Services");

//        for (auto x = cliente->getServices().begin(); x != cliente->getServices().end(); ++x) {
//            xw.writeTextElement("Service", QString::number(*x));
//        }
//        xw.writeEndElement();

//        xw.writeEndElement();

//        xw.writeEndElement();


//    }
//    xw.writeEndElement();
//    xw.writeEndDocument();

//    file.close();
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

        QDomNode baseInfo = clienteNode.firstChildElement("BaseInfo"); //dopo guardare come lo chiameremo su salva!

        QDomElement nomeElem = baseInfo.firstChildElement("nome");
        QDomElement cognomeElem = baseInfo.firstChildElement("cognome");
        QDomElement dataNascitaGiornoElem = baseInfo.firstChildElement("dataNascitaGiorno"); //pesco i tre interi della data per ricreare la QDate
        QDomElement dataNascitaMeseElem = baseInfo.firstChildElement("dataNascitaMese");
        QDomElement dataNascitaAnnoElem = baseInfo.firstChildElement("dataNascitaAnno");
        QDomElement codicefiscaleElem = baseInfo.firstChildElement("codicefiscale");
        QDomElement luogodNElem = baseInfo.firstChildElement("luogodN");
        QDomElement residenzaElem = baseInfo.firstChildElement("residenza");
        QDomElement viaElem = baseInfo.firstChildElement("via");
        QDomElement numviaElem = baseInfo.firstChildElement("numvia");
        QDomElement numerotelElem = baseInfo.firstChildElement("numerotel");
        QDomElement mailElem = baseInfo.firstChildElement("mail");
        QDomElement studentElem = baseInfo.firstChildElement("student");

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
            QDomElement scadenzaPiscinaGiornoElem = baseInfo.firstChildElement("scadenzaPiscinaGiorno");
            QDomElement scadenzaPiscinaMeseElem = baseInfo.firstChildElement("scadenzaPiscinaMese");
            QDomElement scadenzaPiscinaAnnoElem = baseInfo.firstChildElement("scadenzaPiscinaAnno");
            bool corsonuoto = studentElem.text().toUInt()== 1;
            std::string nomeistruttorepiscina = nomeistruttorepiscinaElem.text().toStdString();
            unsigned short int scadenzaPiscinaGiorno = static_cast<unsigned int>(scadenzaPiscinaGiornoElem.text().toInt());
            unsigned short int scadenzaPiscinaMese = static_cast<unsigned int>(scadenzaPiscinaMeseElem.text().toInt());
            unsigned short int scadenzaPiscinaAnno = static_cast<unsigned int>(scadenzaPiscinaAnnoElem.text().toInt());

            res = new piscina(nome, cognome, dataNascitaGiorno, dataNascitaMese, dataNascitaAnno,codicefiscale,luogodN,residenza,via,numvia,numerotel,mail,student,corsonuoto,nomeistruttorepiscina,scadenzaPiscinaGiorno,scadenzaPiscinaMese,scadenzaPiscinaAnno);


        } else if (elemType == "Palestra") {
            QDomElement schedaElem = clienteElem.firstChildElement("scheda");
            QDomElement nomeistruttorepalestraElem = clienteElem.firstChildElement("nomeistruttorepalestra");
            QDomElement scadenzaPalestraGiornoElem = baseInfo.firstChildElement("scadenzaPalestraGiorno");
            QDomElement scadenzaPalestraMeseElem = baseInfo.firstChildElement("scadenzaPalestraMese");
            QDomElement scadenzaPalestraAnnoElem = baseInfo.firstChildElement("scadenzaPalestraAnno");
            bool scheda = studentElem.text().toUInt()== 1;
            std::string nomeistruttorepalestra = nomeistruttorepalestraElem.text().toStdString();
            unsigned short int scadenzaPalestraGiorno = static_cast<unsigned int>(scadenzaPalestraGiornoElem.text().toInt());
            unsigned short int scadenzaPalestraMese = static_cast<unsigned int>(scadenzaPalestraMeseElem.text().toInt());
            unsigned short int scadenzaPalestraAnno = static_cast<unsigned int>(scadenzaPalestraAnnoElem.text().toInt());

            res = new palestra(nome, cognome, dataNascitaGiorno, dataNascitaMese, dataNascitaAnno,codicefiscale,luogodN,residenza,via,numvia,numerotel,mail,student,scheda,nomeistruttorepalestra,scadenzaPalestraGiorno,scadenzaPalestraMese,scadenzaPalestraAnno);


        } else if (elemType == "Vip") {

            QDomElement corsonuotoElem = clienteElem.firstChildElement("corsonuoto");
            QDomElement nomeistruttorepiscinaElem = clienteElem.firstChildElement("nomeistruttorepiscina");
            QDomElement scadenzaPiscinaGiornoElem = baseInfo.firstChildElement("scadenzaPiscinaGiorno");
            QDomElement scadenzaPiscinaMeseElem = baseInfo.firstChildElement("scadenzaPiscinaMese");
            QDomElement scadenzaPiscinaAnnoElem = baseInfo.firstChildElement("scadenzaPiscinaAnno");
            QDomElement schedaElem = clienteElem.firstChildElement("scheda");
            QDomElement nomeistruttorepalestraElem = clienteElem.firstChildElement("nomeistruttorepalestra");
            QDomElement scadenzaPalestraGiornoElem = baseInfo.firstChildElement("scadenzaPalestraGiorno");
            QDomElement scadenzaPalestraMeseElem = baseInfo.firstChildElement("scadenzaPalestraMese");
            QDomElement scadenzaPalestraAnnoElem = baseInfo.firstChildElement("scadenzaPalestraAnno");
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

