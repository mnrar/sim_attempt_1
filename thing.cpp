#include "thing.hpp"

#include <iostream>
#include <string>
#include <vector>
#include "component.hpp"
#include "transform.hpp"
#include "rect_collider.hpp"

int Thing::id_gen = 1;  

Thing::Thing(){
    this->giveId();
    this->components.push_back(new Transform());
}

Thing::Thing(double x, double y){
    this->giveId();
    this->components.push_back(new Transform(x, y));
}

void Thing::giveId(){
    this->id = id_gen;
    Thing::id_gen++;
}

void Thing::display(){
    std::cout<<"Thing:\n ID : "<<(this->id)<<std::endl;
}

void Thing::displayShort(){
    std::cout<<"(Thing, id: "<<(this->id)<<")";
}

void Thing::update(){
    std::cout<<"Update called on thing: "<<(this->id)<<std::endl;
    for(auto component : components){
        component->update();
    }
}

std::string Thing::description(){
    return "A thing with id : " + std::to_string(this->id) + ")\n";
}

std::string Thing::descriptionShort(){
    return "(Thing, ID : " + std::to_string(this->id) + ")";
}

void Thing::addComponent(Component* component){
    this->components.push_back(component);

    if(component->className() == "PhysicsBody" && this->hasCollider()){
        static_cast<RectangleCollider*>(this->getCollider())->setPhysicsBody(static_cast<PhysicsBody*>(component));
    }

    if(component->className() == "RectangleCollider" && this->hasPhysics()){
        static_cast<RectangleCollider*>(component)->setPhysicsBody(static_cast<PhysicsBody*>(this->getPhysicsBody()));
    }
}

bool Thing::hasPhysics(){
    for(auto component : components){
        if(component->className() == "PhysicsBody")return true;
    }
    return false;
}

bool Thing::hasCollider(){
    for(auto component : components){
        if(component->className() == "RectangleCollider")return true;
    }
    return false;
}

Component* Thing::getCollider(){
    for(auto component : components){
        if(component->className() == "RectangleCollider")return component;
    }
    return NULL;
}

Component* Thing::getPhysicsBody(){
    for(auto component : components){
        if(component->className() == "PhysicsBody")return component;
    }
    return NULL;      
}

Component* Thing::getTransform(){
    for(auto component : components){
        if(component->className() == "Transform")return component;
    }
    return NULL;      
}

void Thing::setSpeedX(double xs){
    Transform* transform = static_cast<Transform*>(components[0]);
    transform->setSpeedX(xs);
}

void Thing::setSpeedY(double ys){
    Transform* transform = static_cast<Transform*>(components[0]);
    transform->setSpeedY(ys);
}