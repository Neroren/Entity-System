#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "Vector3D.h"
#include "Enumerators.h"

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

    void setWorldID(int id);
    int getWorldID();

    void destroy();

  protected:
    EntityType type;
    unsigned int id;
    std::string name;
    Vector3D location;
    int worldID;

  private:
};

#endif // ENTITY_H
