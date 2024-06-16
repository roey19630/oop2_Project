#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
//#include "PauseButton.h"
#include "screenFolder.h/GameState.h"
#include "Board.h"
#include"BaseButton.h"

class PlayState : public GameState
{
public:
    PlayState();
    void draw() override;
    void update() override;
    GameState* isStateChanged() override;

private:

    //std::shared_ptr<PauseButton> m_pauseButton;
    sf::RenderWindow m_window;
    sf::View view;
    //Board m_board;


    sf::Sprite m_backgroundSprite;
    sf::Texture m_backgroundTexture;
};