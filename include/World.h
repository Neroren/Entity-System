#ifndef WORLD_H
#define WORLD_H

#include "LivingEntity.h"
#include "Monster.h"
#include "Enumerators.h"
#include <vector>

class World {
  public:
    World();
    virtual ~World();

    /**
     *  @brief Creates an Entity in the world of type entityType.
     *
     *  @param entityType EntityType to create. Defaults to ENTITY if not specified.
     *  @return Entity* The created entity, ready to be manipulated.
     */
    Entity* createEntity(EntityType entityType = ENTITY);

    /**
     *  @brief Inserts an existing Entity into the world
     *  @param ent Entity* to insert.
     *
     *  This does not move the entity, it only copies it. Make sure to dispose of the
     *  original entity once it has been copied.
     */
    void insertEntity(Entity* ent);

    /**
     *  @brief Removes an Entity from the world using their slot ID in the world.
     *  @param index Slot ID.
     */
    void removeEntity(unsigned int index);

    /**
     *  @brief Removes an Entity from the world using their Entity ID in the world.
     *  @param id Entity ID to search and remove.
     *
     *  Refrain from using this as it is more resource intensive than removing by index.
     *  Note that this is the ONLY way to remove an entity by their identifier and
     *  removing an entity by index will not guarantee which entity is removed.
     */
    void removeEntityByID(unsigned int id);

    /**
     *  @brief Prints all entities in the world to console. Helpful for debugging.
     */
    void printAllEntities();

    /**
     *  @brief Removes all Entities in the world.
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
