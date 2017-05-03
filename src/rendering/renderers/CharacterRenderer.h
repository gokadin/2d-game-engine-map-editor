#ifndef SFMLDEMO_CHARACTERRENDERER_H
#define SFMLDEMO_CHARACTERRENDERER_H

#include <SFML/Graphics/Shape.hpp>
#include "../Renderer.h"

class CharacterRenderer : public Renderer
{
public:
    CharacterRenderer(GameState& state);

    void draw(sf::RenderWindow *window);
    void update();
    void process(action_types type, sf::Event& event);
};

#endif //SFMLDEMO_CHARACTERRENDERER_H
