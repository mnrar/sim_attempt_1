#include <iostream>
#include "rect.cpp"
#include "physicsBody.cpp"
#include "scene.cpp"

int Thing::id_gen = 1;
int Component::id_gen = 1;

int main(){
 //   Thing::setupThing();
    Rectangle* rect = new Rectangle(12, 16);
    rect->print();

  //  std::cout<<"Adding physics  to this rect:"<<std::endl;

    //PhysicsBody rect_pb(rect, 3); 
    std::cout<<"Making a scene: "<<std::endl;

    Scene scene(53);
    scene.addThing(new Rectangle(15, 19, 20, 30));
    scene.addComponent(new PhysicsBody(rect, 5));
    scene.display();
    scene.update();
    scene.display();
}