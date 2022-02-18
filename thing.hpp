#ifndef THING_H
#define THING_H 

#include <string>
#include <vector>
#include "component.hpp"

class Thing{
    private:
    static int id_gen;

    protected:
    int id;
    std::vector<Component*> components;

    public:
    Thing();

    Thing(double x, double y);

    void giveId();

    virtual void display();

    virtual void update();

    virtual void displayShort();

    virtual std::string description();

    virtual std::string descriptionShort();

    void addComponent(Component*);

    bool hasPhysics();
    bool hasCollider();

    Component* getCollider();
    Component* getTransform();
    Component* getPhysicsBody();

    void setSpeedX(double xs);
    void setSpeedY(double ys);

};

#endif