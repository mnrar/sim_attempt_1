#include "scene.hpp"

#include <iostream>
#include <vector>


Scene::Scene(int id){
    this->id = id;
    things = std::vector<Thing*>();
}

void Scene::addThing(Thing* thing){
    std::cout<<"adding "<<(thing->descriptionShort())<<" to the scene"<<std::endl;
    things.push_back(thing);
}

void Scene::update(){
    std::cout<<"Updating scene: "<<id<<std::endl;
    for(auto t : things)t->update();

    checkCollisions();
}

void Scene::display(){
    std::cout<<"Things: \n";
    for(auto t : things){
        t->display();
    }
}

void Scene::checkCollisions(){
    std::vector<bool> eligible(this->things.size(), false);

    for(int i = 0; i < things.size(); i++){
        eligible[i] = ( things[i]->hasPhysics() && things[i]->hasCollider() );
    }

    for(int i =0; i < things.size(); i++){
        if(!eligible[i])continue;
        for(int j = i+1; j < things.size(); j++){
            if(!eligible[j])continue;
            std::cout<<"collission possible"<<std::endl;
            static_cast<RectangleCollider*>(things[i]->getCollider())->detectCollision(things[j]);
        }
    }
}