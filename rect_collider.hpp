#ifndef RECT_COLLIDER_H
#define RECT_COLLIDER_H

#include "physicsBody.hpp"
#include "transform.hpp"
#include "thing.hpp"
#include "classInfo.hpp"

class RectangleCollider : public Component{
    private:
    double height;
    double width;
    double e_value{1};
    Transform* transform;
    PhysicsBody* physicsBody;

    public:
    RectangleCollider(Transform* transform, double height = 50, double width = 50);

    void update();

    void set_e_value(double e);

    virtual std::string className();

    void detectCollision(Thing* thing);

    void setPhysicsBody(PhysicsBody* pb);
};

#endif