#include "texture_widget.h"

Texture_Widget::Texture_Widget()
{
    qDebug() << "Constructeur Texture_Widget sans arguments";
}

Texture_Widget::Texture_Widget(std::string file)
{
    qDebug() << "Constructeur Texture_Widget avec la texture a chargée";

    LoadTexture(file);
}

void Texture_Widget::draw(sf::RenderTarget &target, sf::RenderStates states) const{

    target.draw(sprite);
    target.draw(hit_box);
}

bool Texture_Widget::getCollision(sf::Vector2i pos){

    return hit_box.getGlobalBounds().contains(pos.x, pos.y);
}

bool Texture_Widget::LoadTexture(std::string file){

    if(texture.loadFromFile(file)){
        qDebug() << "Texture de chemin : " << QString::fromStdString(file) << "chargée avec succès";
    }
    else{
        qDebug() << "Error lors du chargement de la texture de chemin : " << QString::fromStdString(file);
    }
    sprite.setTexture(texture);
}

void Texture_Widget::setHitBoxSize(float width, float height){
    hit_box.setSize(sf::Vector2f(width, height));
}

void Texture_Widget::setPosition(sf::Vector2f pos){

    sprite.setPosition(pos);
    hit_box.setPosition(pos);
}

bool Texture_Widget::Contains(sf::Vector2i pos){

    return hit_box.getGlobalBounds().contains(pos.x, pos.y);
}

void Texture_Widget::setHitBoxBorderThickness(float border_tickness){

    hit_box.setOutlineThickness(border_tickness);
}

void Texture_Widget::setHitBoxOutlineColor(sf::Color color){

    hit_box.setOutlineColor(color);
}

void Texture_Widget::setHitBoxColor(sf::Color color){

    hit_box.setFillColor(color);
}

