#ifndef ENTITY_H
#define ENTITY_H

#include <string>

#include "Enumerators.h"
#include "Vector3D.h"

class World; // Forward declaration for setWorld and getWorld;

class Entity {
  public:
    Entity();
    virtual ~Entity();

    void setType(EntityType type);
    EntityType getType();

    void setID(unsigned int id);
    unsigned int getID();

    void setName(std::string name);
    std::string getName();

    void setLocation(Vector3D vec3d);
    Vector3D getLocation();

    void setWorld(World* world);
    void moveToWorld(World* world);
    World* getWorld();

    void remove();

  protected:
    EntityType type;
    unsigned int id;
    std::string name;
    Vector3D location;
    World* world;

  private:
};

#endif // ENTITY_H
