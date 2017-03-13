#include "Entity.h"

Entity::Entity() {
    setType(ENTITY);
    setID(0);
    setName("Entity");
    setLocation(Vector3D(0.0f, 0.0f, 0.0f));
    setWorldID(0);
}

Entity::~Entity() {
}

void Entity::setType(EntityType type) {
    this->type = type;
}

EntityType Entity::getType() {
    return this->type;
}

void Entity::setID(unsigned int id) {
    this->id = id;
}

unsigned int Entity::getID() {
    return this->id;
}

void Entity::setName(std::string name) {
    this->name = name;
}

std::string Entity::getName() {
    return this->name;
}

void Entity::setLocation(Vector3D vec3d) {
    this->location = vec3d;
}

Vector3D Entity::getLocation() {
    return this->location;
}

void Entity::setWorldID(int id) {
    this->worldID = id;
}

int Entity::getWorldID() {
    return this->worldID;
}

void Entity::destroy() {
    // TODO
    return;
}
