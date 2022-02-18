#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "component.hpp"
#include "classInfo.hpp"

class Transform : public Component{
    private:
    double x;
    double y;

    double speedX;
    double speedY;

    public:
    Transform(double x = 0, double y = 0);

    void update();

    void move(double dx, double dy);

    void setX(double x);
    void setY(double y);

    double getX();
    double getY();

    void setSpeedX(double speedX);
    void setSpeedY(double speedY);

    double getSpeedX();
    double getSpeedY();

    std::string className();

};

#endif