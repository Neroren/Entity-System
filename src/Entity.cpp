#include "Entity.h"
#include "World.h"

Entity::Entity() {
    setType(ENTITY);
    setID(0);
    setName("Entity");
    setLocation(Vector3D(0.0f, 0.0f, 0.0f));
    setWorld(0);
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

void Entity::setWorld(World* world) {
    this->world = world;
}

void Entity::moveToWorld(World* world) {
    if (!world || getWorld() == world) // Do nothing if moving to current world
        return;

    if (getWorld()) // If entity is currently in a world, then:
        getWorld()->withdrawEntity(this); // Withdraw entity from old world

    world->insertEntity(this); // Insert entity into new world
}

World* Entity::getWorld() {
    return this->world;
}

void Entity::remove() {
    if (!getWorld())
        return;

    getWorld()->removeEntity(this);
}
