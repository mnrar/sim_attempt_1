#ifndef COMPONENT_H
#define COMPONENT_H

#include "thing.cpp"

class Component{
    protected: 
    Thing* thing;
    int id;

    private:
    static int id_gen;

    protected:
    Component(Thing* thing){
        std::cout<<"Making a component for "<<thing->idDesc()<<std::endl;
        this->thing = thing;
        this->id = id_gen;
        id_gen++;
    }

    public:
    virtual void update(){
        std::cout<<"update called on component: "<<(this->id)<<std::endl;
    }
};

#endif