#pragma once
#include "StaticObject.h"

class BaseWeaponObject : public StaticObject
{
public:
    BaseWeaponObject(const sf::Vector2f& initPosition);
    BaseWeaponObject();

    virtual void shoot() = 0;
    void setFireRate(float rate);
    void update(float deltaTime);

protected:
    float m_fireRate;
};