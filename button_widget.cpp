#include "button_widget.h"

Button_Widget::Button_Widget()
{
    qDebug() << "Constructeur ButtonWidget";

    text.setString("Default");
    text.setCharacterSize(20);
    text.setPosition(30, 30);

    font = new sf::Font;
    font_default = new sf::Font;

    if(font_default->loadFromFile("Bebas.otf")){
        qDebug() << "Font par defaut pour les boutons chargée avec succès !";
        text.setFont(*font_default);
    }
    else{
        qDebug() << "Echec lors du chargement de la font par defaut des boutons !";
    }

    highlight = false;

    color_highlight = sf::Color::White;

    hit_box.setSize(sf::Vector2f(text.getGlobalBounds().width, text.getCharacterSize()/2));

    hit_box.setFillColor(sf::Color::Transparent);

    text.setColor(sf::Color::Black);

}

Button_Widget::~Button_Widget(){

    qDebug() << "Destructeur Button_Widget";

    delete font;
    delete font_default;
}

void Button_Widget::draw(sf::RenderTarget &target, sf::RenderStates states) const{

    target.draw(hit_box);
    target.draw(text);
}

bool Button_Widget::Contains(sf::Vector2i pos){

    return hit_box.getGlobalBounds().contains(pos.x, pos.y);
}

void Button_Widget::setPosition(sf::Vector2f pos){

    //qDebug() << "Position set : " << pos.x << pos.y << pos_x << pos_y;

    pos_x = pos.x;
    pos_y = pos.y;

    hit_box.setSize(sf::Vector2f(text.getGlobalBounds().width+20, text.getCharacterSize()));
    hit_box.setPosition(pos.x-hit_box.getSize().x/2, pos.y-text.getCharacterSize()/2);

    text.setPosition(pos.x-text.getGlobalBounds().width/2, pos.y-text.getCharacterSize()/1.5);
}

sf::Vector2f Button_Widget::getPosition(){
    return text.getPosition();
}

bool Button_Widget::LoadFont(std::string file)
{
    if(font->loadFromFile(file)){
        qDebug() << "Police de chemin : " << QString::fromStdString(file) << " chargée avec succès";
    }
    else{
        qCritical() << "Erreur lors du chargement de la police de chemin : " << QString::fromStdString(file);

    }
    text.setFont(*font);
}

void Button_Widget::setHighlight(int character_size, sf::Color color){

    //qDebug() << "h" << highlight;

    //On verifie que le bouton ne soit pas déjà grossis
    if(highlight == true){
        return;
    }
    else{
        //On set la value highlight a true pour ne pas de nouveau highlight le bouton
        highlight = true;

        //On stocke l'ancienne taille de character pour la remettre après
        character_size_highlight = text.getCharacterSize();
        this->color_highlight = text.getColor();

        //On grossis le bouton
        text.setCharacterSize(character_size);
        text.setColor(color);

        //Et on le re-positionne
        setPosition(sf::Vector2f(pos_x, pos_y));

    }

}

void Button_Widget::unHighlight(){

        highlight = false;

        //On de-grossis/de-colore le bouton
        text.setCharacterSize(character_size_highlight);
        text.setColor(color_highlight);

        //Et on le re-positionne
        setPosition(sf::Vector2f(pos_x, pos_y));

}

void Button_Widget::setCharacterSize(int size){

    text.setCharacterSize(size);
    character_size_highlight = size;
}

void Button_Widget::setOutlineColor(sf::Color color){
    hit_box.setOutlineColor(color);
}

void Button_Widget::setOutlineThickness(float thickness){
    hit_box.setOutlineThickness(thickness);
}

void Button_Widget::setFilledColor(sf::Color color){
    hit_box.setFillColor(color);
}

void Button_Widget::setString(sf::String string){
    text.setString(string);
}

void Button_Widget::setTextColor(sf::Color color){
    text.setColor(color);
    color_highlight = color;
}

sf::FloatRect Button_Widget::getGlobalBounds(){
    return text.getGlobalBounds();
}

sf::String Button_Widget::getString(){
    return text.getString();
}

void Button_Widget::setFont(sf::Font &font){
    this->font = &font;
    text.setFont(font);
}

