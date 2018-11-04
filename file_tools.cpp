#include "file_tools.h"

File_Tools::File_Tools(QString path_file)
{
    qDebug() << "Contructeur File_Tools";

    file = new QFile(path_file);
    if(file->open(QIODevice::ReadWrite)){
        qDebug() << "Fichier de chemin : " << path_file << "ouvert avec succes !";
    }
    else{
        qDebug() << "Echec lors de l'ouverture du fichier de chemin : " << path_file;
    }
}

File_Tools::File_Tools(){
    qDebug() << "Constructeur File_Tools sans arguments";
}

File_Tools::~File_Tools()
{
    file->close();
    delete file;

    qDebug() << "Destructeur File_Tools";
}

QString File_Tools::getValueFromAttribute(QString attribute_to_found){

    file->seek(0);

    QString attribute = "";
    QString value = "";

    bool b_attribute = false;
    bool b_value = false;

    while(!file->atEnd()){

        QString character = file->read(1);

        //qDebug() << character;

        if(character == "#" && b_attribute == false){
            b_attribute = true;
        }
        else if(character == ":" && b_attribute == true){
            b_attribute = false;
            b_value = true;
        }
        else if(character == ";" && b_value){

            b_attribute = false;
            b_value = false;

            if(attribute == attribute_to_found){
                return value;
            }

            attribute = "";
            value = "";
        }
        else if(character == " "){

        }
        else if(b_attribute == true){
            attribute+=character;
        }
        else if(b_value == true){
            value+=character;
        }
    }
}

void File_Tools::setValueFromAttribute(QString attribute_to_found, QString value_to_set){

    file->seek(0);

    QString text_to_fill = "";

    QString attribute = "";
    QString value = "";

    bool b_attribute = false;
    bool b_value = false;
    bool b_value_set = false;

    while(!file->atEnd()){

        QString character = file->read(1);

        qDebug() << character << value << attribute << attribute_to_found;

        if(character == "#" && b_attribute == false){
            b_attribute = true;

            text_to_fill+=character;

            attribute = "";
            value = "";
        }
        else if(character == ":" && b_attribute == true){
            b_attribute = false;
            b_value = true;

            text_to_fill+=character;
        }
        else if(character == ";" && b_value == true){

            b_attribute = false;
            b_value = false;

            text_to_fill+=character;

        }
        else if(character == " "){
            text_to_fill+=character;
        }
        else if(b_attribute == true){

            attribute+=character;
            text_to_fill+=character;

        }
        else if(b_value == true){

            if(attribute == attribute_to_found && b_value_set == false){
                text_to_fill+=value_to_set;
                b_value_set = true;
            }
            else if(attribute == attribute_to_found && b_value_set == true){

            }
            else{
                text_to_fill+=character;
                value+=character;
            }
        }
    }

    qDebug() << text_to_fill;

    if(!file->remove()){
        qDebug() << "Erreur lors de la supression du fichier " << file->fileName();
    }

    if(!file->open(QIODevice::ReadWrite)){
        qDebug() << "Erreur lors de l'ouverture du fichier " << file->fileName();
    }

    QTextStream file_text_stream(file);
    file_text_stream << text_to_fill;
}

void File_Tools::setFile(QString path_file){

    file = new QFile(path_file);
    if(file->open(QIODevice::ReadWrite)){
        qDebug() << "Fichier de chemin : " << path_file << "ouvert avec succes !";
    }
    else{
        qDebug() << "Echec lors de l'ouverture du fichier de chemin : " << path_file;
    }
}


