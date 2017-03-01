#include "LivingEntity.h"
#include "Enumerators.h"
#include <vector>

#ifndef WORLD_H
#define WORLD_H

class World {
  public:
    World();
    virtual ~World();

    Entity* createEntity(EntityType entityType);
    void insertEntity(LivingEntity* ent);
    void removeEntity(unsigned int index);
    void removeEntityByID(unsigned int id);

    void printAllEntities();
    void removeAllEntities();

    void setWorldID(int id);
    int getWorldID();

    void setWorldName(std::string name);
    std::string getWorldName();

  protected:

  private:
    int worldID, entityCounter;
    std::string worldName;
    std::vector<Entity*> vec;
};

#endif // WORLD_H
