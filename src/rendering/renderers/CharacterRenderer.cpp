#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "CharacterRenderer.h"

CharacterRenderer::CharacterRenderer(GameState& state):
        Renderer(state)
{}

void CharacterRenderer::draw(sf::RenderWindow *window)
{
    sf::RectangleShape rect(sf::Vector2f(state.character.boxWidth, state.character.boxHeight));
    rect.setFillColor(sf::Color(255, 0, 0));
    rect.setPosition(sf::Vector2f(state.config.cx - state.character.boxWidth, state.config.cy - state.character.boxHeight));

    window->draw(rect);
}

void CharacterRenderer::update()
{

}

void CharacterRenderer::process(action_types type, sf::Event &event)
{

}
