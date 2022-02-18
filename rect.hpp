#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "thing.hpp"
#include "classInfo.hpp"

class Rectangle : public Thing, ClassInfo{
    private:
    double width;
    double height;

    public:
    Rectangle(double x = 100, double y = 100, double width = 50, double height = 50);

    void display();

    void displayShort();

    void update();

    std::string description();

    std::string descriptionShort();

    virtual std::string className();
};

#endif