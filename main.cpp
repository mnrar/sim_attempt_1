#include <iostream>
#include <string>
#include "rect.hpp"
#include "physicsBody.hpp"
#include "scene.hpp"

int main(){
    Rectangle* rect1 = new Rectangle(12, 16);
    rect1->displayShort();

    // Rectangle* rect2 = new Rectangle(15, 19, 20, 30);
    // rect2->displayShort();

    // PhysicsBody* pb_for_2 = new PhysicsBody(5);
    // rect2->addComponent(pb_for_2);

    std::cout<<"Making a scene: "<<std::endl;

    rect1->setSpeedX(1);
    rect1->setSpeedY(2);

    rect1->addComponent(new PhysicsBody(5));
    rect1->addComponent(new RectangleCollider(static_cast<Transform*>(rect1->getTransform())));

    Rectangle* rect2 = new Rectangle(63, 25);
    rect2->addComponent(new PhysicsBody(5));
    rect2->addComponent(new RectangleCollider(static_cast<Transform*>(rect2->getTransform())));

    Scene scene(53);
    scene.addThing(rect1);
    scene.addThing(rect2);
    do{
        scene.update();
        scene.display();
        std::cout<<"---------------------------";
    }while(std::cin.get() == '\n');
}