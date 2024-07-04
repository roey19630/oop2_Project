#include "Objects.h/BigSlowEnemyObject.h"


//----------------------------------------------------------------------------
bool BigSlowEnemyObject::m_registerit = FactoryObject::registerit(ENEMY_1_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<BigSlowEnemyObject>(pos); });
//------------------------------------------------------
BigSlowEnemyObject::BigSlowEnemyObject(const sf::Vector2f& initPosition)
    :BaseEnemyObject(initPosition,40,35,30)
{
    m_speed = 2.0;

    defaultFrames = { getFrame(0, 0) };
    leftFrames = { getFrame(1, 0), getFrame(1, 1), getFrame(1, 2), getFrame(1, 3) };
    rightFrames = { getFrame(2, 0), getFrame(2, 1), getFrame(2, 2), getFrame(2, 3) };
    downFrames = { getFrame(0, 0), getFrame(0, 1), getFrame(0, 2), getFrame(0, 3) };
    upFrames = { getFrame(3, 0), getFrame(3, 1), getFrame(3, 2), getFrame(3, 3) };

    currentFrames = &defaultFrames;
    m_objectSprite.setTextureRect((*currentFrames)[0]);

}
//------------------------------------------------------
void BigSlowEnemyObject::animate(float deltaTime)
{
}
//------------------------------------------------------
void BigSlowEnemyObject::resetSprite(int num)
{
}
//------------------------------------------------------
sf::IntRect BigSlowEnemyObject::getFrame(int row, int col)
{
    return sf::IntRect(col * BIG_ENEMY_SPRITE_WIDTH, row * BIG_ENEMY_SPRITE_HEIGHT, BIG_ENEMY_SPRITE_WIDTH, BIG_ENEMY_SPRITE_HEIGHT);
}
//-----------------------------------------------------
//------------------------------------------------------
void BigSlowEnemyObject::draw(sf::RenderWindow* window) const
{
    BaseObject::draw(window);
    m_lives.draw(window);
}
//------------------------------------------------------
