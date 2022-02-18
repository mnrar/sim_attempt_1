#ifndef PHYSICSBODY_H
#define PHYSICSBODY_H

#include "component.hpp"
#include "classInfo.hpp"

class PhysicsBody : public Component{
    private:
    double acc_due_to_gravity{-10};
    double mass{1};
    double force_horizontal{0};
    double force_vertical{0};
    bool gravity{0};

    public:
    PhysicsBody(double mass = 1);

    void update();

    virtual std::string className();

    void setMass(double mass);
    double getMass();

};

#endif