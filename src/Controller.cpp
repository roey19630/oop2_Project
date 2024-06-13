
#include "Controller.h"

Controller::Controller()
	:m_window(sf::VideoMode(800,600), "Brawl Stars",
		sf::Style::Close | sf::Style::Titlebar)
{
	m_currentScreen = new Menu();
}

void Controller::run() {
    sf::Clock clock;

	while (m_window.isOpen())
	{
        float deltaTime = clock.restart().asSeconds();
		m_window.events();
		m_window.display();
		m_window.clear();

		GameState* nextScreen = m_currentScreen->isStateChanged();
		if (nextScreen)
		{
			m_currentScreen = nextScreen;
    }
		m_currentScreen->update();
		m_currentScreen->draw();
}

void Controller::update(float deltaTime) {
    m_playerObject.update(deltaTime);
}

void Controller::render() {
    m_window.clear();
    m_playerObject.draw(m_window);
    m_window.display();
}