#include "rect_collider.hpp"

#include <iostream>

RectangleCollider::RectangleCollider(Transform* transform, double height, double width){
    this->e_value = 1;
    this->height = height;
    this->width = width;
    this->transform = transform;
}

void RectangleCollider::update(){
    std::cout<<"Update called on rect_collider"<<std::endl;
}

void RectangleCollider::set_e_value(double e){
    this->e_value = e;
}

std::string RectangleCollider::className(){
    return "RectangleCollider";
}

void RectangleCollider::setPhysicsBody(PhysicsBody* pb){
    this->physicsBody = pb;
}

void RectangleCollider::detectCollision(Thing* thing){
    RectangleCollider* otherColl = static_cast<RectangleCollider*>(thing->getCollider());
    double m2 = static_cast<PhysicsBody*>(thing->getPhysicsBody())->getMass();
    double m1 = this->physicsBody->getMass();

    double x1 = this->transform->getX();
    double y1 = this->transform->getY();
    double x2 = otherColl->transform->getX();
    double y2 = otherColl->transform->getY();

    double x_overlap = (this->width + otherColl->width)/2 - std::abs(x1 - x2);
    double y_overlap = (this->height + otherColl->height)/2 - std::abs(y1 -y2);

    bool collision = (x_overlap > 0 && y_overlap > 0);

    if(collision)std::cout<<"..^8**76..\nCOLLISSION"<<std::endl;

    // std::cout<<"debug: \nx1: "<<x1<<", x2: "<<x2<<"\ny1: "<<y1<<", y2: "<<y2<<std::endl;
    // std::cout<<"x_ol: "<<x_overlap<<", y-ol: "<<y_overlap<<std::endl;

    //from top or bottom
    if(collision && x_overlap > y_overlap)
    {
        double u1 = this->transform->getSpeedY();
        double u2 = otherColl->transform->getSpeedY();
        double newYSpeed = ( u1 * (m1 - e_value*m2) + m2 * u2 * (1+e_value) ) / (m1 + m2);
        double otherNewYSpeed = ( u2 * (m2 - e_value*m1) + m1 * u1 * (1+e_value) ) / (m1 + m2);
        // std::cout<<"old y speeds: "<<u1<<", "<<u2<<std::endl;

        // std::cout<<"new y speeds: "<<newYSpeed<<", "<<otherNewYSpeed<<std::endl;

        otherColl->transform->setSpeedY(otherNewYSpeed);
        this->transform->setSpeedY(newYSpeed);
    }
    //from sides
    else if(collision){
        double u1 = this->transform->getSpeedX();
        double u2 = otherColl->transform->getSpeedX();
        double newXSpeed = ( u1 * (m1 - e_value*m2) + m2 * u2 * (1+e_value) ) / (m1 + m2);
        double otherNewXSpeed = ( u2 * (m2 - e_value*m1) + m1 * u1 * (1+e_value) ) / (m1 + m2);
// std::cout<<"old x speeds: "<<u1<<", "<<u2<<std::endl;
//         std::cout<<"new x speeds: "<<newXSpeed<<", "<<otherNewXSpeed<<std::endl;

        otherColl->transform->setSpeedX(otherNewXSpeed);
        this->transform->setSpeedX(newXSpeed);
    }

    if(collision){
        this->transform->update();
        otherColl->transform->update();
    }
}