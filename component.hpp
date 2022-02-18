#ifndef COMPONENT_H
#define COMPONENT_H

#include "classInfo.hpp"
#include <string>

class Component : public ClassInfo{
    protected: 
    int id;

    private:
    static int id_gen;

    protected:
    Component();

    public:
    virtual void update();

    virtual std::string className();
};

#endif