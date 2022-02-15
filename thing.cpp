#ifndef THING_H
#define THING_H 

#include <iostream>
#include <string>

// unnecessary comment

class Thing{
    private:
    static int id_gen;

    protected:
    int id;


    public:
    Thing(){
        std::cout<<"making a thing with id "<<id_gen<<std::endl;
        this->id = id_gen;
        Thing::id_gen++;
    }

    Thing(int x, int y): Thing(){
        std::cout<<"Making a thing at "<<x<<", "<<y<<std::endl;
    }

 //   static void setupThing(){
 //       Thing::id_gen = 1;
  //  }

    virtual void display(){
        std::cout<<"Heres a thing with id: "<<(this->id)<<'\n';
    }

    virtual void update(){
        std::cout<<"Update called on thing: "<<(this->id)<<std::endl;
    }

    void printShort(){
        std::cout<<"(Thing, ID: "<<this->id<<")";
    }

    std::string idDesc(){
        return "(Thing, ID : " + std::to_string(this->id) + ")";
    }


};

#endif