#include "PlayerObject.h"
//------------------------------------------------
//constant ans enum
const int PLAYER_SPRITE_WIDTH = 64;
const int PLAYER_SPRITE_HEIGHT = 96;
const int PLAYER_SPRITES_PER_ROW = 4;
const int PLAYER_SPRITES_PER_COLUMN = 4;
const float PLAYER_MOVE_SPEED = 0.1f;
//------------------------------------------------
//c-tor
PlayerObject::PlayerObject()
{
    if (!m_texture.loadFromFile("Player.png"))
    {
        // error loading message
    }

    m_sprite.setTexture(m_texture);
    m_sprite.setScale(1.0f, 1.0f);

    defaultFrames = { getFrame(0, 0) };
    leftFrames = { getFrame(1, 0), getFrame(1, 1), getFrame(1, 2), getFrame(1, 3) };
    rightFrames = { getFrame(2, 0), getFrame(2, 1), getFrame(2, 2), getFrame(2, 3) };
    downFrames = { getFrame(0, 0), getFrame(0, 1), getFrame(0, 2), getFrame(0, 3) };
    upFrames = { getFrame(3, 0), getFrame(3, 1), getFrame(3, 2), getFrame(3, 3) };

    currentFrames = &defaultFrames;

    m_sprite.setTextureRect((*currentFrames)[0]);
    m_x = 100.f;
    m_y = 100.f;
    spriteIndex = 0;
    isMoving = false;
}
//------------------------------------------------


void PlayerObject::update(float deltaTime) {
    handleInput();
    animate(deltaTime);
    m_sprite.setPosition(m_x, m_y);
}
//------------------------------------------------


void PlayerObject::draw(sf::RenderWindow& m_window) {
    m_window.draw(m_sprite);
}
//------------------------------------------------

sf::IntRect PlayerObject::getFrame(int row, int col) {
    return sf::IntRect(col * PLAYER_SPRITE_WIDTH, row * PLAYER_SPRITE_HEIGHT, PLAYER_SPRITE_WIDTH, PLAYER_SPRITE_HEIGHT);
}
//------------------------------------------------

void PlayerObject::handleInput() {
    isMoving = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_x -= PLAYER_MOVE_SPEED;
        currentFrames = &leftFrames;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_x += PLAYER_MOVE_SPEED;
        currentFrames = &rightFrames;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        m_y -= PLAYER_MOVE_SPEED;
        currentFrames = &upFrames;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        m_y += PLAYER_MOVE_SPEED;
        currentFrames = &downFrames;
        isMoving = true;
    }

    if (!isMoving) {
        currentFrames = &defaultFrames;
    }
}
//------------------------------------------------

void PlayerObject::animate(float deltaTime) {
    if (clock.getElapsedTime().asSeconds() > 0.1f) {
        spriteIndex = (spriteIndex + 1) % currentFrames->size();
        m_sprite.setTextureRect((*currentFrames)[spriteIndex]);
        clock.restart();
    }
}