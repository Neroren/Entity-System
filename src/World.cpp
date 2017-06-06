#include "World.h"

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
    oss << number;
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
    switch (entityType) {
    default:
        printf("createEntity(): EntityType not valid, defaulting to Entity\n");
    case ENTITY:
        entity = new Entity();
        break;

    case LIVINGENTITY:
        entity = new LivingEntity();
        break;

    case MONSTER:
        entity = new Monster();
        break;
    }

    //vec[entitySlot]->setName("entity_" + IntToString(entityCounter));
    entity->setID(entityCounter);
    entity->setWorld(this);
    {
        scoped_lock lock(mutex);
        ents.push_back(entity);
        entityCounter++;
    }

    Vector3D loc = entity->getLocation();
    DEBUG_PRINT("Created entity %s (%.2f, %.2f, %.2f), current amount: %d\n", entity->getName().c_str(), loc.x, loc.y, loc.z, ents.size());

    return entity;
}

void World::insertEntity(Entity* entity) {
    bool newID = false;
    entity->setWorld(this);

    {
        scoped_lock lock(mutex);

        if (!entity->getID()) {
            entity->setID(entityCounter);
            entityCounter++; // TODO set accessors and mutators for entityCounter so that added entities ID's don't collide with existing ones
            newID = true;
        }

        ents.push_back(entity);
    }
    entity->setWorldID(getWorldID());
    Vector3D loc = entity->getLocation();

    DEBUG_PRINT("Inserted entity %s (%.2f, %.2f, %.2f), current amount: %d\n", entity->getName().c_str(), loc.x, loc.y, loc.z, ents.size());
    if(newID)
        DEBUG_PRINT("Inserted entity had no ID, so the ID %d has been assigned to it\n", entity->getID());
}

void World::removeEntity(unsigned int index) {
    if(index > ents.size() || index < 0) {
        printf("removeEntity(): Out of bounds. Ranges are from 0 to %d\n", ents.size());
        return;
    }
    Entity* entity = ents[index];
    DEBUG_PRINT("Removed entity in world named %s", entity->getName().c_str());
    {
        scoped_lock lock(mutex);
        delete entity;
        ents.erase(ents.begin() + index);
void World::removeEntity(Entity* entity) {
    for (size_t i = 0; i < getEntityCount(); ++i) {
        if (entity == ents[i]) {
            scoped_lock lock(mutex);
            ents.erase(ents.begin() + i);
            delete entity;
            DEBUG_PRINT("Removed entity from world \"%s\", ID: %d\n", getWorldName().c_str(), getWorldID());
            return;
        }
    }

    printf("removeEntity(): Entity could not be found in world\n");
}

void World::removeEntityByID(unsigned int id) {
    for(size_t i = 0; i < ents.size(); ++i) {
        Entity* entity = ents[i];
        if(entity->getID() == id) {
            scoped_lock lock(mutex);
            delete entity;
            ents.erase(ents.begin() + i);
            DEBUG_PRINT("Removed entity in world with ID %d, current amount: %d\n", id, ents.size());
            return;
        }
    }
    printf("removeEntityByID(): Entity by ID %d could not be found\n", id);
}

Entity* World::getEntityByID(unsigned int id) {
    size_t size = getEntityCount();

    for (size_t i = 0; i < size; ++i) {
        Entity* entity = ents[i];

        if (entity->getID() == id) {
            DEBUG_PRINT("getEntityByID(): Found entity in world with ID %d\n", id);
            return entity;
        }
    }
    printf("getEntityByID(): Entity by ID %d could not be found\n", id);
    return 0;
}

void World::printAllEntities() {
    printf("\n--- All Entities in world \"%s\" (ID: %d), %d total entities ---\n", getWorldName().c_str(), getWorldID(), getEntityCount());
    printf("[INDEX]\tID\tNAME\t\tTYPE\n");
    size_t size = getEntityCount();

    for (size_t i = 0; i < size; ++i) {
        Entity* entity = ents[i];
        printf("[%d]\t%d\t%s\t%s\n", i, entity->getID(), entity->getName().c_str(), Enumerators::toString(entity->getType()).c_str());
    }

    printf("---------------------------------------------------------------\n\n");
}

void World::removeAllEntities() {
    scoped_lock lock(mutex);

    for (size_t i = 0; i < getEntityCount(); ++i) {
        delete ents[i];
    }

    entityCounter = 0;
    ents.clear();
}

// Only removes the entity from world without deleting
void World::withdrawEntity(Entity* entity) {
    for (size_t i = 0; i < getEntityCount(); ++i) {
        if (entity == ents[i]) {
            scoped_lock lock(mutex);
            ents.erase(ents.begin() + i);
            DEBUG_PRINT("Withdrew entity \"%s\" from world \"%s\", ID: %d\n", entity->getName().c_str(), getWorldName().c_str(), getWorldID());
            return;
        }
    }

    printf("withdrawEntity(): Entity could not be found in world\n");
}

unsigned int World::getEntityCount() {
    return ents.size();
}
