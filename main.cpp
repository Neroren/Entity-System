#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <boost/thread/thread.hpp>

#include "LivingEntity.h"
#include "World.h"

#define MEM_LEAK // Comment out to prevent memory leak testing

World* world;
int threadCount = 6;

void memleak() {
    int counter = 0;
    const int entsToCreate = 5000000 / threadCount;
    const int entsToRemove = 500000 / threadCount;

    printf("STARTING MEMORY HERE\n");

    while(true) {
        LivingEntity* worldent = (LivingEntity*) world->createEntity(LIVINGENTITY);
        worldent->setName("newname");

        counter++;
        if(counter == entsToCreate) {
            printf("FULL MEMORY HERE - Containing %d entities\n", world->getEntityCount());
            //system("pause");
            for(int i = 0; i < entsToRemove; ++i) {
                world->removeEntityByID(i);
                //LivingEntity* test = new LivingEntity();
                //world->insertEntity(test);
            }
            printf("Removed %d entities - Containing %d entities\n", entsToRemove, world->getEntityCount());
            return;
            system("pause");
            world->removeAllEntities();
            printf("EMPTY MEMORY HERE - Containing %d entities\n", world->getEntityCount());
            system("pause");
            counter = 0;
        }
    }
}

int main () {
    world = new World();
    world->setWorldName("Earth");

    #ifdef MEM_LEAK
    boost::thread_group threads;
    for(int i = 0; i < threadCount; ++i) {
        threads.create_thread(memleak);
    }
    threads.join_all();
    return 0;
    #endif // MEM_LEAK

    LivingEntity* worldent = (LivingEntity*) world->createEntity(LIVINGENTITY);
    worldent->setName("this is a test");
    world->createEntity();
    world->createEntity(PLAYER);
    world->createEntity(MONSTER);
    world->createEntity(ENTITY);
    world->createEntity(LIVINGENTITY);
    world->removeEntity(1000);
    world->removeEntityByID(30); // Will give a not found error
    world->createEntity(LIVINGENTITY);
    world->createEntity(LIVINGENTITY);

    LivingEntity* lara = new LivingEntity();

    lara->setName("Lara Croft");
    lara->setLocation(Vector3D(1.25f, 95.54f, 5.35468f));
    lara->setHealth(250);
    lara->setMaxHealth(250);
    lara->setArmor(100);
    lara->setSpeed(5.0f);
    world->insertEntity(lara); // Insert Lara into world, now managed by world class
    lara->setArmor(10);
    world->printAllEntities();
    //printf("Name: %s\nID: %d\nHealth: %d\nArmor: %d\nSpeed: %f\n", test->getName().c_str(), test->getID(), test->getHealth(), test->getArmor(), test->getSpeed());
    LivingEntity* test_world = (LivingEntity*) world->getEntityByID(8);
    printf("Name: %s\nID: %d\nHealth: %d\nArmor: %d\nSpeed: %f\n", test_world->getName().c_str(), test_world->getID(), test_world->getHealth(), test_world->getArmor(), test_world->getSpeed());

    LivingEntity* test2 = new LivingEntity(1, "Lara Croft 2", 500, 200);

    printf("\nName: %s\nID: %d\nHealth: %d\nArmor: %d\nSpeed: %f\n", test2->getName().c_str(), test2->getID(), test2->getHealth(), test2->getArmor(), test2->getSpeed());
    test2->damage(300);
    printf("\nTook 300 damage! New stats:\nHealth: %d\nArmor: %d\n", test2->getHealth(), test2->getArmor());

    threads.join_all();
    delete world;
    return 0;
}
