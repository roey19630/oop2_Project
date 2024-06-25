#pragma once
#include "screenFolder.h/GameState.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "screenFolder.h/PlayState.h"
#include "Utilities.h"

class WinScreen : public GameState {
public:
    WinScreen(sf::RenderWindow* window);
    ~WinScreen();
    void draw() override;
    void update() override;
    std::shared_ptr <GameState> isStateChanged(sf::Event event) override;

private:


    sf::Texture m_backgroundTexture;
    sf::Sprite m_backgroundSprite;

    sf::Texture m_menuButtonTexture;
    sf::Sprite m_menuButtonSprite;

    sf::Texture m_exitButtonTexture;
    sf::Sprite m_exitButtonSprite;


    std::vector<BaseButton*> m_buttons;
};
