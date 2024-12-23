
#include "Buttons.h/StartGameCommand.h"
#include "Buttons.h/InstructionsCommand.h"
#include "Buttons.h/ExitCommand.h"
#include "Buttons.h/ResumeGameCommand.h"
#include "Buttons.h/Button.h"
#include"Utilities.h"

#include "screenFolder.h/PauseState.h"
#include <iostream>


PausePage::PausePage(sf::RenderWindow* window)
    : GameState(window, PLAY_WINDOW_WIDTH, PLAY_WINDOW_HEIGHT)

{

    setObjTexture(PAUSE_SCREEN_OBJ);
    setScale(PAUSE_SCREEN_OBJ);

    std::unique_ptr<CommandButton> resumeCmd = std::make_unique<StartGameCommand>();
    std::unique_ptr<CommandButton> instCmd = std::make_unique<InstructionsCommand>();
    std::unique_ptr<CommandButton> exitCmd = std::make_unique<ExitCommand>();

    m_buttons.push_back(std::make_unique<Button>(std::move(resumeCmd), RESUME_GAME_BUTTON_OBJ,400, 300));
    m_buttons.push_back(std::make_unique<Button>(std::move(instCmd), INSTRUCTION_BUTTON_OBJ, 400, 400));
    m_buttons.push_back(std::make_unique<Button>(std::move(exitCmd), EXIT_BUTTON_OBJ, 400, 500));

}

PausePage::~PausePage()
{
}

void PausePage::draw()
{
    m_window->setTitle("Pause");
    m_window->setSize(m_windowSize);
    m_window->draw(m_backGroundSprite);

    for (auto& button : m_buttons) {
        button->draw(m_window);
    }
}

void PausePage::update(float deltatime)
{
}


std::shared_ptr<GameState> PausePage::isStateChanged(sf:: Event event)
{
    if (event.type == sf::Event::Closed) {
        m_window->close();
    }
    if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            for (auto& button : m_buttons) {
                if (button->isMouseOver(m_window)) {
                    StateOptions state = button->click();
                    if (state == StateOptions::Exit)
                    {
                        m_window->close();
                    }
                    return m_states[state];
                }
            }
        }
    }

    return nullptr;
}
