#ifndef ENUMERATORS_H
#define ENUMERATORS_H

#include <string>

enum EntityType {
    ENTITY,
    LIVINGENTITY,
    PLAYER,
    MONSTER
};

class Enumerators {
  public:
    static std::string toString(EntityType type) {
        switch (type) {
            default:
            case ENTITY:
                return "ENTITY";

            case LIVINGENTITY:
                return "LIVINGENTITY";

            case PLAYER:
                return "PLAYER";

            case MONSTER:
                return "MONSTER";
        }
    }

};

#endif // ENUMERATORS_H
