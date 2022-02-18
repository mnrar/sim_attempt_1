#include "component.hpp"

#include <iostream>

int Component::id_gen = 1;

Component::Component(){
    this->id = id_gen;
    id_gen++;
}

void Component::update(){
    std::cout<<"update called on component: "<<(this->id)<<std::endl;
}

std::string Component::className(){
    return "Component";
}
