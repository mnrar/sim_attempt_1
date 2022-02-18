#include "physicsBody.hpp"

#include <iostream>

PhysicsBody::PhysicsBody(double mass):Component(){
    this->mass = mass;
    std::cout<<"We have a new physics body with mass "<<(this->mass)<<std::endl;
}

void PhysicsBody::update(){
    std::cout<<"update called on physics body"<<(this->id)<<std::endl;
}

std::string PhysicsBody::className(){
    return "PhysicsBody";
}

void PhysicsBody::setMass(double mass){
    this->mass = mass;
}

double PhysicsBody::getMass(){
    return this->mass;
}