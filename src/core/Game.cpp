#include "Game.h"

Game::Game(int screenWidth, int screenHeight)
{
    dataProvider = new DataProvider(state, screenWidth, screenHeight);
    dataProvider->load();
    actionDispatcher = new ActionDispatcher(state);
    updateDispatcher = new UpdateDispatcher(state);
    renderDispatcher = new RenderDispatcher(state);
    inputManager = new InputManager(actionDispatcher);
}

Game::~Game()
{
    delete dataProvider;
    delete inputManager;
    delete actionDispatcher;
    delete updateDispatcher;
    delete renderDispatcher;
}

void Game::processEvent(sf::Event event)
{
    inputManager->processEvent(event);

    switch (event.type)
    {
        case sf::Event::MouseButtonPressed:
            renderDispatcher->process(action_types::MOUSE_BUTTON_PRESSED, event);
            break;
        case sf::Event::MouseButtonReleased:
            renderDispatcher->process(action_types::MOUSE_BUTTON_RELEASED, event);
        case sf::Event::KeyPressed:
            renderDispatcher->process(action_types::CHARACTER_MOVE_DOWN, event);
            break;
    }
}

void Game::update()
{
    updateDispatcher->update();
    renderDispatcher->update();
}

void Game::draw(sf::RenderWindow *window)
{
    renderDispatcher->render(window);
}
