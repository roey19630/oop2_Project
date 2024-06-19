#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

const int NUMBER_OF_OBJECTS = 18;

enum Object_ID {
    CLOCK_OBJ,
    INSTRUCTION_PAGE_1_OBJ,
    INSTRUCTION_PAGE_2_OBJ,
    MENU_BACK_GROUND_OBJ,
    NEW_GAME_BUTTON_OBJ,
    EXIT_BUTTON_OBJ,
    INSTRUCTION_BUTTON_OBJ,
    PAUSE_BUTTON_OBJ, 
    BRICK_WALL_OBJ,
    BUSH_OBJ,
    POISON_OBJ,
    PLAYER_OBJ,
    ENEMY_1_OBJ,
    ENEMY_2_OBJ,
    TREES_OBJ,
    WEAPON_1_OBJ,
    WEAPON_2_OBJ,
    WEAPON_3_OBJ,
};

class TextureHandler
{
public:
    TextureHandler();

    static TextureHandler& getInstance();

    sf::Texture* getObjTexture(Object_ID name);

    //sf::Font getFont() const;

    ~TextureHandler();

private:

    std::string m_imgNames[NUMBER_OF_OBJECTS] = {
        "clock.png",            "instruction1.png",  "instruction2.png",
        "menuBackGround.png",   "newGameButon.png",  "exitButton.png",
        "instructionButton.png","pauseButton.png",   "brickWall.png",
        "bush.png",             "poison.png",        "player.png",
        "enemy1.png",           "enemy2.png",        "trees.png",
        "weapon1.png",          "weapon2.png",       "weapon3.png" };

    sf::Texture m_textures[NUMBER_OF_OBJECTS];
    //sf::Font m_font;
};