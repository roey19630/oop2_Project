#pragma once

#include "Objects.h/MovingObject.h"
#include "FactoryObject.h"
#include "FlashlightObject.h"

class PlayerObject : public MovingObject
{
public:
    //c-tor
    PlayerObject(const sf::Vector2f& pos);

    void update(float deltaTime, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    virtual void move(float deltaTime);

private:
    //member of the texture of the player

    float m_x, m_y;
    sf::Clock clock;
    FlashlightObject m_flashlight;

    std::vector<sf::IntRect> defaultFrames;
    std::vector<sf::IntRect> leftFrames;
    std::vector<sf::IntRect> rightFrames;
    std::vector<sf::IntRect> downFrames;
    std::vector<sf::IntRect> upFrames;
    std::vector<sf::IntRect>* currentFrames;

    void handleInput();
    static bool m_registerit;
};
