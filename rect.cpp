#include "rect.hpp"

#include <iostream>
#include "transform.hpp"

Rectangle::Rectangle(double x, double y, double width, double height):Thing(x, y){
    std::cout<<"rectangle constructor"<<std::endl;
    this->width = width;
    this->height = height;
}

void Rectangle::update(){
    std::cout<<"update called on this rect: "<<(this->id)<<std::endl;
    for(auto component : this->components){
        component->update();
    }
}

void Rectangle::display(){
    Transform* transform = static_cast<Transform*>(this->components[0]);
    std::cout<<"Rectangle:\n";
    std::cout<<"ID : "<<(this->id)<<"\n";
    std::cout<<"X: "<<transform->getX() << ", Y: "<<transform->getY()<<std::endl;
    std::cout<<"width : "<<(this->width)<<", height: "<<(this->height)<<std::endl;
}

void Rectangle::displayShort(){
    std::cout<<"( Rectangle, ID: "<<(this->id)<<")";
}

std::string Rectangle::description(){
    return "Rectangle, ID = " + std::to_string(this->id) + ".\n"
            + ".\nWidth: " + std::to_string(this->width) + ", Height: " + std::to_string(this->height) + ".\n";
}

std::string Rectangle::descriptionShort(){
    return "( Rectangle, ID: " + std::to_string(this->id) + ")";
}

std::string Rectangle::className(){
    return "Rectangle";
}