#ifndef LIVINGENTITY_H
#define LIVINGENTITY_H

#include "Entity.h"
#include "Enumerators.h"

class LivingEntity : public Entity {
  public:
    LivingEntity();
    LivingEntity(int id, std::string name, int health = 100, int armor = 100, float speed = 1.0f);
    virtual ~LivingEntity();

    /**
     *  @brief Sets the entity's health.
     *  @param health Health amount.
     *
     *  Any value between 0 to MAX_HEALTH, values outside this range are
     *  clamped.
     */
    void setHealth(int health);
    int getHealth();

    /**
     *  @brief Sets maximum health.
     *  @param health Max health amount.
     *
     *  Not an absolute max health limit, only what the health should
     *  regenerate to when at 100% health. This allows health to be above
     *  the max limit for a short time.
     */
    void setMaxHealth(int health);
    int getMaxHealth();

    /**
     *  @brief Sets the entity's armor.
     *  @param armor Armor amount.
     *
     *  Any value between 0 to MAX_ARMOR, values outside this range are
     *  clamped.
     */
    void setArmor(int armor);
    int getArmor();

    void setSpeed(float speed);
    float getSpeed();

    /**
     *  @brief Damages the entity by specified amount.
     *  @param amount Damage amount.
     *
     *  First damages armor, then health.
     */
    void damage(int amount);

    /**
     *  @brief Kills the entity.
     *
     *  Sets the health and armor to 0. Note this does not remove the entity, it is
     *  up to the world to delete the entity object.
     */
    void kill();

    /**
     *  @brief Checks to see whether the entity is dead.
     *  @return bool True if entity is dead, false otherwise.
     */
    bool isDead();

  protected:
    int health, maxHealth, armor;
    float speed;

  private:
    /**
     *  @brief Clamps value between lower and upper bounds.
     *  @param value Number to clamp.
     *  @param lower Lower bounds.
     *  @param upper Upper bounds.
     *  @return The clamped value in the type provided.
     */
    template <typename T> T clamp(const T& value, const T& lower, const T& upper);
};

#endif // LIVINGENTITY_H
