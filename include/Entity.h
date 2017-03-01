#include <string>
#include "Vector3D.h"

#ifndef ENTITY_H
#define ENTITY_H

class Entity {
  public:
    Entity();
    virtual ~Entity();

    void setID(unsigned int id);
    unsigned int getID();

    void setName(std::string name);
    std::string getName();

    void setLocation(Vector3D vec3d);
    Vector3D getLocation();

    void destroy();

  protected:
    int id;
    std::string name;
    Vector3D location;

  private:
};

#endif // ENTITY_H
