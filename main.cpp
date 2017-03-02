#include <iostream>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include "LivingEntity.h"
#include "World.h"

//#define MEM_LEAK // Comment out to prevent memory leak testing

int main () {
    World* world = new World();
    world->setWorldName("Earth");
    LivingEntity* worldent = (LivingEntity*) world->createEntity(LIVINGENTITY);
    worldent->setName("this is a test");
    world->createEntity();
    world->createEntity(PLAYER);
    world->createEntity(MONSTER);
    world->createEntity(ENTITY);
    world->createEntity(LIVINGENTITY);
    world->removeEntity(1000);
    //world->removeEntityByID(30); // Will give a not found error
    world->createEntity(LIVINGENTITY);
    world->createEntity(LIVINGENTITY);
    #ifdef MEM_LEAK
    int counter = 0;
    delete world;

    printf("STARTING MEMORY HERE\n");
    system("pause");
    world = new World();
    while(true) {
        LivingEntity* worldent = (LivingEntity*) world->createEntity(LIVINGENTITY);
        //worldent->setName("newname");

        counter++;
        if(counter == 1000000) {
            printf("FULL MEMORY HERE\n");
            system("pause");
            //world->printAllEntities();
            world->removeAllEntities();
            delete world;
            printf("EMPTY MEMORY HERE\n");
            world = new World();
            system("pause");
            counter = 0;
        }
    }
    #endif // MEM_LEAK

    LivingEntity* test = new LivingEntity();

    test->setName("Lara Croft");
    //test->setID(0);
    test->setLocation(Vector3D(1.25f, 95.54f, 5.35468f));
    test->setHealth(250);
    test->setMaxHealth(250);
    test->setArmor(100);
    test->setSpeed(5.0f);
    world->insertEntity(test); // Insert Lara into world, now managed by world class
    world->printAllEntities();
    printf("Name: %s\nID: %d\nHealth: %d\nArmor: %d\nSpeed: %f\n", test->getName().c_str(), test->getID(), test->getHealth(), test->getArmor(), test->getSpeed());

    LivingEntity* test2 = new LivingEntity(1, "Lara Croft 2", 500, 200);

    printf("\nName: %s\nID: %d\nHealth: %d\nArmor: %d\nSpeed: %f\n", test2->getName().c_str(), test2->getID(), test2->getHealth(), test2->getArmor(), test2->getSpeed());
    test2->damage(300);
    printf("\nTook 300 damage! New stats:\nHealth: %d\nArmor: %d", test2->getHealth(), test2->getArmor());
    delete world;
    return 0;
}
