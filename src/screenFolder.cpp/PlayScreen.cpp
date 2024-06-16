#include "screenFolder.h/PlayScreen.h"

PlayScreen::PlayScreen()
	:view(sf::FloatRect(0, 0, 400, 300))
{
    //m_pauseButton = std::make_shared<PauseButton>(sf::Vector2f(50, 50), "Pause");

    if (!m_backgroundTexture.loadFromFile("playBackground.png"))
    {
    }
    m_backgroundSprite.setTexture(m_backgroundTexture);
}



GameState* PlayScreen::isStateChanged()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) 
        {
            m_window.close();
        }
        if (event.type == sf::Event::MouseButtonReleased) 
        {
            if (event.mouseButton.button == sf::Mouse::Left) 
            {
               
               if (m_pauseButton->isMouseOver(m_window)) {
                   return (m_pauseButton->onClick());   
               }
                
            }
        }
    }
    return nullptr;
}