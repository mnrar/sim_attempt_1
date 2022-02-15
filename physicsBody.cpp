#ifndef PHYSICSBODY_H
#define PHYSICSBODY_H

#include <iostream>
#include "component.cpp"

class PhysicsBody : public Component{
    private:
    int acc_due_to_gravity{-10};
    int mass{1};
    int force_horizontal{0};
    int force_vertical{0};
    bool gravity{0};

    public:
    PhysicsBody(Thing* thing, int mass = 1):Component(thing){
        this->mass = mass;
        std::cout<<"We have a new physics body with mass "<<(this->mass)<<std::endl;
    }

    void update(){
        std::cout<<"update called on physics body"<<(this->id)<<std::endl;
    }

};

#endif