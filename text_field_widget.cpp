#include "text_field_widget.h"

Text_Field_Widget::Text_Field_Widget()
{
    qDebug() << "Constructeur TextField";

    font = new sf::Font;
    font_default = new sf::Font;

    has_focus = false;

    setSize(60,30);

    if(font_default->loadFromFile("Bebas.ttf")){
        qDebug() << "Font par defaut pour les boutons chargée avec succès !";
        text.setFont(*font_default);
    }
    else{
        qDebug() << "Echec lors du chargement de la font par defaut pour les boutons chargée avec succès !";
    }

    hit_box.setOutlineColor(sf::Color::White);
}

bool Text_Field_Widget::getHasFocus(){
    return has_focus;
}

void Text_Field_Widget::setHasFocus(bool has_focus){
    this->has_focus = has_focus;
}

void Text_Field_Widget::setCharacterSize(int character_size){
    text.setCharacterSize(character_size);
}

void Text_Field_Widget::setPosition(float x, float y){

    hit_box.setPosition(x/2, y/2);
}

void Text_Field_Widget::draw(sf::RenderTarget &target, sf::RenderStates states) const{

    target.draw(hit_box);
    target.draw(text);
}

bool Text_Field_Widget::LoadFont(std::string file)
{
    if(font->loadFromFile(file)){
        qDebug() << "Police de chemin : " << QString::fromStdString(file) << " chargée avec succès";
    }
    else{
        qCritical() << "Erreur lors du chargement de la police de chemin : " << QString::fromStdString(file);

    }
    text.setFont(*font);
}

void Text_Field_Widget::keyEntered(sf::Keyboard::Key key){

    if(has_focus){

    }
    else{
        return;
    }
}

int Text_Field_Widget::getSizeText(){

    return (text.getString().toAnsiString().length()*(text.getCharacterSize()/1.84));
}

void Text_Field_Widget::setSize(float width, float height){

    hit_box.setSize(sf::Vector2f(width, height));
}

void Text_Field_Widget::setOutlineColor(sf::Color color){
    hit_box.setOutlineColor(color);
}

void Text_Field_Widget::setOutlineThickness(float thickness){
    hit_box.setOutlineThickness(thickness);
}

void Text_Field_Widget::setFilledColor(sf::Color color){
    hit_box.setFillColor(color);
}

