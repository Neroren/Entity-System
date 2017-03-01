#include "LivingEntity.h"
#include "Enumerators.h"
#include <vector>

#ifndef WORLD_H
#define WORLD_H

class World {
  public:
    World();
    virtual ~World();

    /**
     *  @brief Creates an Entity in the world of type entityType.
     *
     *  @param entityType EntityType to create.
     *  @return Entity* The created entity, ready to be manipulated.
     */
    Entity* createEntity(EntityType entityType);

    /**
     *  @brief Inserts an existing Entity into the world
     *  @param ent LivingEntity* to insert.
     */
    void insertEntity(LivingEntity* ent);

    /**
     *  @brief Removes an Entity from the world using their slot ID in the world.
     *  @param index Slot ID.
     */
    void removeEntity(unsigned int index);

    /**
     *  @brief Removes an Entity from the world using their Entity ID in the world.
     *  @param id Entity ID to search and remove.
     */
    void removeEntityByID(unsigned int id);

    /**
     *  @brief Sets the entity's health.
     *  @param health Health amount.
     *
     *  Any value between 0 to MAX_HEALTH, values outside this range are
     *  clamped.
     */
    void printAllEntities();

    /**
     *  @brief Removes all Entities in the world.
     *  @param health Health amount.
     *
     *  This deletes all entities, resets the vector containing all of their pointers,
     *  and resets the entity counter to 0. Essentially emptying the world.
     */
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
