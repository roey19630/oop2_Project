#pragma once
#include "MovingObject.h"

class PlayerObject : public MovingObject
{
public:
    PlayerObject();
    void update(float deltaTime);
    void draw(sf::RenderWindow& m_window);

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    float m_x, m_y;
    int spriteIndex;
    bool isMoving;
    sf::Clock clock;

    std::vector<sf::IntRect> defaultFrames;
    std::vector<sf::IntRect> leftFrames;
    std::vector<sf::IntRect> rightFrames;
    std::vector<sf::IntRect> downFrames;
    std::vector<sf::IntRect> upFrames;
    std::vector<sf::IntRect>* currentFrames;

    sf::IntRect getFrame(int row, int col);
    void handleInput();
    void animate(float deltaTime);
};