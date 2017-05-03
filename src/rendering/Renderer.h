#ifndef SFMLDEMO_DRAWABLE_H
#define SFMLDEMO_DRAWABLE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../states/GameState.h"
#include "../actions/ActionTypes.h"

class Renderer
{
public:
    Renderer(GameState& state):
            state(state)
    {}

    virtual void draw(sf::RenderWindow *window) = 0;
    virtual void update() = 0;
    virtual void process(action_types type, sf::Event& event) = 0;

protected:
    GameState& state;
};

#endif //SFMLDEMO_DRAWABLE_H
