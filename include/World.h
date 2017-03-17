#ifndef WORLD_H
#define WORLD_H

#include <deque>
#include <stdio.h>
#include <boost/thread.hpp>

#include "Enumerators.h"
#include "LivingEntity.h"
#include "Monster.h"
#include "Vector3D.h"

class World {
  public:
    World();
    virtual ~World();

    void setWorldID(int id);
    int getWorldID();

    void setWorldName(std::string name);
    std::string getWorldName();

    /**
     *  @brief Creates an Entity in the world of type entityType.
     *
     *  @param entityType EntityType to create. Defaults to ENTITY if not specified.
     *  @return Entity* The created entity, ready to be manipulated.
     */
    Entity* createEntity(EntityType entityType = ENTITY);

    /**
     *  @brief Inserts an existing Entity into the world
     *  @param entity Entity pointer to insert.
     *
     *  This adds the entity to the world, and does not copy it. Edits to the original
     *  entity will change the entity in the world as they are the same object.
     *  Currently, if the inserted entity has the same ID as an already existing entity,
     *  it will be kept. That means there will be two or more entities with the same ID.
     */
    void insertEntity(Entity* entity);

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

    Entity* getEntityByID(unsigned int id);

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

    int getEntityCount();

  protected:

  private:
    int worldID, entityCounter;
    std::string worldName;
    std::deque<Entity*> ents;

    boost::mutex mutex;
    typedef boost::lock_guard<boost::mutex> scoped_lock;
};

#endif // WORLD_H
