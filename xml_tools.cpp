#include "xml_tools.h"

Xml_Tools::Xml_Tools()
{
    qDebug() << "Constructeur Xml_Tools sans arguments";
}

Xml_Tools::Xml_Tools(QString path_file)
{
    //qDebug() << "Constructeur Xml_Tools avec le fichier xml";

    qDebug() << path_file;

    xml_file = new QFile(path_file);

    if(xml_file->open(QIODevice::ReadWrite)){
        qDebug() << "Fichier xml ouvert avec succès";
    }
    else{
        qDebug() << "Erreur lors de l'ouverture du fichier xml";

        xml_file->close();
        //return;
    }

    xml_document = QDomDocument("xml");

    if(xml_document.setContent(xml_file)){
        qDebug() << "Fichier xml associé avec succès";
    }
    else{
        qDebug() << "Erreur lors de l'assiociation du fichier xml";

        xml_file->close();
        //return;
    }

    document_element = xml_document.documentElement();
}

QString Xml_Tools::getValueFromXmlFile(QString attribute){

    for(QDomNode n = document_element.firstChild(); !n.isNull(); n = n.nextSibling()){

        qDebug() << n.nodeName();

        if(n.nodeName() == attribute){
            return n.childNodes().item(0).nodeName();
        }
    }
}

bool Xml_Tools::setValueFromXmlFile(QString attribute, QString value){

    for(QDomNode n = document_element.firstChild(); !n.isNull(); n = n.nextSibling()){

        qDebug() << n.nodeName();
        if(n.nodeName() == attribute){
            n.setNodeValue(value);
            return true;
        }
    }
    return false;
}

void Xml_Tools::setFile(QString path_file){

    qDebug() << path_file;

    xml_file = new QFile(path_file);

    if(xml_file->open(QIODevice::ReadWrite)){
        qDebug() << "Fichier xml ouvert avec succès";
    }
    else{
        qDebug() << "Erreur lors de l'assiociation du fichier xml";

        xml_file->close();
        return;
    }

    xml_document = QDomDocument("xml");

    if(xml_document.setContent(xml_file)){
        qDebug() << "Fichier xml associé avec succès";
    }
    else{
        qDebug() << "Erreur lors de l'assiociation du fichier xml";

        xml_file->close();
        return;
    }

    document_element = xml_document.documentElement();
}
