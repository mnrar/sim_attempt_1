#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <vector>
#include "thing.cpp"
#include "component.cpp"

class Scene{
    private: 
    int id;
    std::vector<Thing*> things;
    std::vector<Component*> components;

    public:
    Scene(int id){
        this->id = id;
        things = std::vector<Thing*>();
        components = std::vector<Component*>();
    }

    void addThing(Thing* thing){
        things.push_back(thing);
    }

    void addComponent(Component* component){
        components.push_back(component);
    }

    void update(){
        std::cout<<"Updating scene: "<<id<<std::endl;
        for(auto c : components)c->update();
        for(auto t : things)t->update();
    }

    void display(){
        std::cout<<"Things: \n";
        for(auto t : things){
            t->display();
        }
    }
};

#endif