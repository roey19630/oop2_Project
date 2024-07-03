
#include "Objects.h/BallsWeaponObject.h"

BallsWeaponObject::BallsWeaponObject()
{
    m_fireRate = 1.0f;
}


void BallsWeaponObject::shoot(FlashlightObject flashlight)
{
    sf::Vector2f start = flashlight.getShape().getPoint(0);
    sf::Vector2f vertex1 = flashlight.getShape().getPoint(1);
    sf::Vector2f vertex2 = flashlight.getShape().getPoint(2);

    for (int i = 0; i < 5; ++i) {
        float t = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        sf::Vector2f randomPoint = vertex1 + t * (vertex2 - vertex1);
        auto bullet = std::make_unique<BulletObject>(start);
        bullet->setTarget(randomPoint);
        m_bullets.push_back(std::move(bullet));

    }
}