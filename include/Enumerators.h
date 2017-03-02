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
        std::string s;
        switch (type) {
        default:
        case ENTITY:
            s = "ENTITY";
            break;
        case LIVINGENTITY:
            s = "LIVINGENTITY";
            break;
        case PLAYER:
            s = "PLAYER";
            break;
        case MONSTER:
            s = "MONSTER";
            break;
        }
        return s;
    }

};

#endif // ENUMERATORS_H
