#ifndef SFMLDEMO_RENDERDISPATCHER_H
#define SFMLDEMO_RENDERDISPATCHER_H

#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../states/GameState.h"
#include "../rendering/renderers/MapRenderer.h"
#include "../rendering/renderers/CharacterRenderer.h"
#include "../rendering/renderers/GridRenderer.h"

class RenderDispatcher
{
public:
    RenderDispatcher(GameState& state):
            state(state)
    {
        renderers.push_back(new MapRenderer(state));
        renderers.push_back(new CharacterRenderer(state));
        renderers.push_back(new GridRenderer(state));
    }

    ~RenderDispatcher()
    {
        for (Renderer *renderer : renderers)
        {
            renderer = NULL;
            delete renderer;
        }
        renderers.clear();
    }

    void update()
    {
        for (int i = 0; i < renderers.size(); i++)
        {
            renderers[i]->update();
        }
    }

    void process(action_types type, sf::Event& event)
    {
        for (int i = 0; i < renderers.size(); i++)
        {
            renderers[i]->process(type, event);
        }
    }

    void render(sf::RenderWindow *window)
    {
        for (int i = 0; i < renderers.size(); i++)
        {
            renderers[i]->draw(window);
        }
    }

private:
    GameState& state;
    std::vector<Renderer *> renderers;
};

#endif //SFMLDEMO_RENDERDISPATCHER_H
