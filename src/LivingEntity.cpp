#include "LivingEntity.h"

#define MAX_HEALTH 1000
#define MAX_ARMOR 1000

LivingEntity::LivingEntity() {
    setType(LIVINGENTITY);
    setName("LivingEntity");
    setHealth(100);
    setMaxHealth(100);
    setArmor(0);
    setSpeed(1.0f);
    inv = 0;
}

LivingEntity::LivingEntity(int id, std::string name, int health, int armor, float speed) {
    setID(id);
    setName(name);
    setHealth(health);
    setMaxHealth(health);
    setArmor(armor);
    setSpeed(speed);
    inv = 0;
}

LivingEntity::~LivingEntity() {
    removeInventory();
}

template <typename T>
T LivingEntity::clamp(const T& value, const T& lower, const T& upper) {
    return std::max(lower, std::min(value, upper));
}

void LivingEntity::setHealth(int health) {
    this->health = clamp(health, 0, MAX_HEALTH);
}

int LivingEntity::getHealth() {
    return this->health;
}

void LivingEntity::setMaxHealth(int health) {
    this->maxHealth = clamp(health, 0, MAX_HEALTH);
}

int LivingEntity::getMaxHealth() {
    return this->maxHealth;
}

void LivingEntity::setArmor(int armor) {
    this->armor = clamp(armor, 0, MAX_ARMOR);
}

int LivingEntity::getArmor() {
    return this->armor;
}

void LivingEntity::setupInventory() {
    this->inv = new Inventory();
}

void LivingEntity::removeInventory() {
    if(inv != 0)
        delete inv;
}

void LivingEntity::setInventory(Inventory* inv) {
    this->inv = inv;
}

Inventory* LivingEntity::getInventory() {
    return this->inv;
}

void LivingEntity::setSpeed(float speed) {
    this->speed = std::max(0.0f, speed);
}

float LivingEntity::getSpeed() {
    return this->speed;
}

void LivingEntity::damage(int amount) {
    // Armor will take the hit first, then health
    int armorDamage, healthDamage;

    armorDamage = getArmor() - amount;
    setArmor(armorDamage);

    if (armorDamage < 0) {
        healthDamage = getHealth() + armorDamage;
        setHealth(healthDamage);
    }
}

void LivingEntity::kill() {
    setHealth(0);
    setArmor(0);
    destroy();
    // TODO: Delete the object without using "delete this" as there is no
    // guarantee that it was allocated with new
    // UPDATE: World now handles deletion
}

bool LivingEntity::isDead() {
    return (getHealth() == 0);
}
