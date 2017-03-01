#include "World.h"
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include "Vector3D.h"

//#define DEBUG // Comment out to debug or switch project build target to Debug, also makes program faster (no need to print text)
#ifdef DEBUG
#define DEBUG_PRINT printf
#else
#define DEBUG_PRINT(...)
#endif

World::World() {
    setWorldID(0);
    setWorldName("world");
    entityCounter = 0;
}

World::~World() {
    removeAllEntities();
}

std::string IntToString(int number) {
    std::ostringstream oss;
    oss<< number;
    return oss.str();
}

void World::setWorldID(int id) {
    this->worldID = id;
}

int World::getWorldID() {
    return this->worldID;
}

void World::setWorldName(std::string name) {
    this->worldName = name;
}

std::string World::getWorldName() {
    return this->worldName;
}

Entity* World::createEntity(EntityType entityType) {
    Entity* entity;
    if (entityType == ENTITY)
        entity = new Entity();
    if (entityType == LIVINGENTITY)
        entity = new LivingEntity();

    vec.push_back(entity);

    int entitySlot = vec.size() - 1;
    vec[entitySlot]->setName("entity_" + IntToString(entityCounter));
    vec[entitySlot]->setID(entityCounter);

    Vector3D loc = vec[entitySlot]->getLocation();

    DEBUG_PRINT("Created entity %s (%.2f, %.2f, %.2f), current amount: %d\n", vec[entitySlot]->getName().c_str(), loc.x, loc.y, loc.z, vec.size());
    entityCounter++;

    return entity;
}

void World::insertEntity(LivingEntity* ent) {
    bool newID = false;
    LivingEntity* entity = ent;

    if (!entity->getID()) {
        entity->setID(entityCounter);
        newID = true;
    }

    vec.push_back(entity);

    int entitySlot = vec.size() - 1;
    Vector3D loc = vec[entitySlot]->getLocation();

    DEBUG_PRINT("Inserted entity %s (%.2f, %.2f, %.2f), current amount: %d\n", vec[entitySlot]->getName().c_str(), loc.x, loc.y, loc.z, vec.size());
    if(newID)
        DEBUG_PRINT("Inserted entity had no ID, so the ID %d has been assigned to it\n", entity->getID());
    entityCounter++; // TODO set accessors and mutators for entityCounter so that added entities ID's don't collide with existing ones

    return;
}

void World::removeEntity(unsigned int index) {
    if(index > vec.size() || index < 0) {
        printf("removeEntity: Out of bounds. Ranges are from 0 to %d\n", vec.size());
        return;
    }
    DEBUG_PRINT("Removed entity in world named %s", vec[index]->getName().c_str());
    delete vec[index];
    vec.erase(vec.begin() + index);
    DEBUG_PRINT(", current amount: %d\n", vec.size());
}

void World::removeEntityByID(unsigned int id) {
    for(size_t i = 0; i < vec.size(); i++) {
        if(vec[i]->getID() == id) {
            delete vec[i];
            vec.erase(vec.begin() + i);
            DEBUG_PRINT("Removed entity in world with ID %d, current amount: %d\n", id, vec.size());
            return;
        }
    }
    printf("Entity by ID %d could not be found\n", id);
}

void World::printAllEntities() {
    printf("[W-ID]\tID\tNAME\t\tTYPE\n");
    for(size_t i = 0; i < vec.size(); i++) {
        printf("[%d]\t%d\t%s\t%s\n", i, vec[i]->getID(), vec[i]->getName().c_str(), (vec[i]->getType() == ENTITY) ? "ENTITY" : "LIVINGENTITY");
    }
}

void World::removeAllEntities() {
    for (size_t i = 0; i < vec.size(); i++) {
        delete vec[i];
    }
    entityCounter = 0;
    vec.clear();
}
