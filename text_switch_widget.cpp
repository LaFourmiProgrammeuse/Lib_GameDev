#include "text_switch_widget.h"

Text_Switch_Widget::Text_Switch_Widget()
{
    qDebug() << "Constructeur Text_Switch_Widget sans arguments";

    m_position = 0;

    font = new sf::Font;
    default_font = new sf::Font;

    if(default_font->loadFromFile("D:/Programmation/Fichier ressource(image,ect)/Police/DIMITRI_.ttf")){
        qDebug() << "Police de chemin de defaut chargée avec succès";
    }
    else{
        qCritical() << "Erreur lors du chargement de la police par defaut";

    }

    if(!m_texture_right_arrow.loadFromFile("D:/Programmation/Fichier ressource(image,ect)/Icone/Fleche droite.png")){
        qDebug() << "Erreur lors du chargement de la texture ";
    }

    if(!m_texture_left_arrow.loadFromFile("D:/Programmation/Fichier ressource(image,ect)/Icone/Fleche gauche.png")){
        qDebug() << "Erreur lors du chargement de la texture";
    }
    m_sprite_right_arrow = sf::Sprite(m_texture_right_arrow);

    m_sprite_right_arrow.setColor(sf::Color::White);
    m_sprite_right_arrow.setScale(sf::Vector2f(10, 10));

    m_sprite_left_arrow = sf::Sprite(m_texture_left_arrow);

    m_sprite_left_arrow.setColor(sf::Color::White);
    m_sprite_left_arrow.setScale(sf::Vector2f(10, 10));

}


void Text_Switch_Widget::draw(sf::RenderTarget &target, sf::RenderStates states) const{

    target.draw(m_sprite_right_arrow);
    target.draw(m_sprite_left_arrow);
    target.draw(*m_listText[m_position]);
}

void Text_Switch_Widget::setPositionList(int i){
    m_position = i;
}

int Text_Switch_Widget::getPositionList(){
    return m_position;
}

void Text_Switch_Widget::setCharacterSize(float size){
    m_character_size = size;
}

void Text_Switch_Widget::operator <<(sf::Text * text){
    m_listText.append(text);
}

void Text_Switch_Widget::Next(){

    if((m_position+1) != m_listText.size()){
        m_position++;
    }
    else{
        m_position = 0;
    }

    setPosition(pos_x, pos_y);
}

void Text_Switch_Widget::Previous(){

    if(m_position != 0){
        m_position--;
    }
    else{
        m_position = (m_listText.size()-1);
    }

    setPosition(pos_x, pos_y);
}

void Text_Switch_Widget::AddString(sf::Text *text){
    m_listText.append(text);

    text->setFont(*font);
    text->setCharacterSize(m_character_size);
}

sf::Vector2f Text_Switch_Widget::getSize(){

    setPosition(pos_x, pos_y);
    sf::Vector2f size(m_listText[m_position]->getGlobalBounds().width+26+m_sprite_left_arrow.getGlobalBounds().width+m_sprite_right_arrow.getGlobalBounds().width, m_listText[m_position]->getGlobalBounds().height);

    return size;
}

void Text_Switch_Widget::Clear(){
    m_listText.clear();
}

void Text_Switch_Widget::RemoveString(int position){
    m_listText.removeAt(position);
}

void Text_Switch_Widget::RemoveString(QString string){

    for(int i = 0; i < m_listText.size(); i++){

        if(m_listText[i]->getString() == sf::String(string.toStdString())){
            m_listText.removeAt(i);
        }
    }
}

bool Text_Switch_Widget::LoadFont(std::string file)
{
    if(font->loadFromFile(file)){
        qDebug() << "Police de chemin : " << QString::fromStdString(file) << " chargée avec succès";
    }
    else{
        qCritical() << "Erreur lors du chargement de la police de chemin : " << QString::fromStdString(file);

    }

}

void Text_Switch_Widget::setPosition(float x, float y){

    pos_x = x;
    pos_y = y;

    m_sprite_left_arrow.setScale(sf::Vector2f(m_listText[m_position]->getCharacterSize()/10, m_listText[m_position]->getCharacterSize()/10));
    m_sprite_right_arrow.setScale(sf::Vector2f(m_listText[m_position]->getCharacterSize()/10, m_listText[m_position]->getCharacterSize()/10));

    m_listText[m_position]->setPosition(x-m_listText[m_position]->getGlobalBounds().width/2, y-m_listText[m_position]->getCharacterSize()/2);

    m_sprite_left_arrow.setPosition(x-m_listText[m_position]->getGlobalBounds().width/2-13-m_sprite_left_arrow.getGlobalBounds().width, y-m_sprite_left_arrow.getGlobalBounds().height/2+3);
    m_sprite_right_arrow.setPosition(x+m_listText[m_position]->getGlobalBounds().width/2+13, y-m_sprite_right_arrow.getGlobalBounds().height/2+3);
}

bool Text_Switch_Widget::CollisionLeftArrow(float x, float y){
    return m_sprite_left_arrow.getGlobalBounds().contains(x, y);
}

bool Text_Switch_Widget::CollisionRightArrow(float x, float y){
    return m_sprite_right_arrow.getGlobalBounds().contains(x, y);
}

void Text_Switch_Widget::Update(){

    m_sprite_left_arrow.setScale(sf::Vector2f(m_listText[m_position]->getCharacterSize()/10, m_listText[m_position]->getCharacterSize()/10));
    m_sprite_right_arrow.setScale(sf::Vector2f(m_listText[m_position]->getCharacterSize()/10, m_listText[m_position]->getCharacterSize()/10));

    m_listText[m_position]->setPosition(pos_x-m_listText[m_position]->getGlobalBounds().width/2, pos_y-m_listText[m_position]->getCharacterSize()/2);

    m_sprite_left_arrow.setPosition(pos_x-m_listText[m_position]->getGlobalBounds().width/2-13-m_sprite_left_arrow.getGlobalBounds().width, pos_y-m_sprite_left_arrow.getGlobalBounds().height/2+3);
    m_sprite_right_arrow.setPosition(pos_x+m_listText[m_position]->getGlobalBounds().width/2+13, pos_y-m_sprite_right_arrow.getGlobalBounds().height/2+3);
}
