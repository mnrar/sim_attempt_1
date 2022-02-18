#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "thing.hpp"
#include "rect_collider.hpp"

class Scene{
    private: 
    int id;
    std::vector<Thing*> things;

    public:
    Scene(int id);

    void addThing(Thing* thing);

    void update();

    void display();

    void checkCollisions();
};

#endif