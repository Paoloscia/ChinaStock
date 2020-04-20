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

}

