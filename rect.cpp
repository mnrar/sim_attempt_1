#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "thing.cpp"

class Rectangle : public Thing{
    private:
    int x;
    int y;
    int width;
    int height;

    public:
    Rectangle(int x = 100, int y = 100, int width = 50, int height = 50):Thing(x, y){
        std::cout<<"rectangle constructor"<<std::endl;
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    void display(){
        print();
    }

    void update(){
        std::cout<<"updtae called on this rect: "<<(this->id)<<std::endl;
    }

    void print(){
        std::cout<<"Rectangle:\n";
        std::cout<<"top left corner at: ("<<(this->x)<<", "<<(this->y)<<")\n";
        std::cout<<"width : "<<(this->width)<<", height: "<<(this->height)<<std::endl;
    }
};

#endif