#include "transform.hpp"

#include <iostream>

Transform::Transform(double x, double y){
    this->x = x;
    this->y = y;
}

void Transform::update(){
    std::cout<<"update called on transform : "<<(this->id)<<std::endl;
    double dt = 0.02;

    double dx = speedX * dt;
    double dy = speedY * dt;

    move(dx, dy);
}

void Transform::move(double dx, double dy){
    this->x += dx;
    this->y += dy;
}

void Transform::setX(double x){
    this->x = x;
}

void Transform::setY(double y){
    this->y = y;
}

double Transform::getX(){
    return this->x;
}

double Transform::getY(){
    return this->y;
}

std::string Transform::className(){
    return "Transform";
}

void Transform::setSpeedX(double s){
    this->speedX = s;
}

void Transform::setSpeedY(double s){
    this->speedY = s;
}

double Transform::getSpeedX(){
    return this->speedX;
}

double Transform::getSpeedY(){
    return this->speedY;
}