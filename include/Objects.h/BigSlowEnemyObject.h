#pragma once
#include "BaseEnemyObject.h"
#include "PlayerLives.h"

class BigSlowEnemyObject : public BaseEnemyObject
{
public:
    BigSlowEnemyObject(const sf::Vector2f& initPosition);

    void draw(sf::RenderWindow*) const override;
private:
    static bool m_registerit;
    PlayerLives m_lives;
};