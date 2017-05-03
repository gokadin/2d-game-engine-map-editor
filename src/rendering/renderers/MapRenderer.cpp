#include "MapRenderer.h"

MapRenderer::MapRenderer(GameState& state):
        Renderer(state)
{
    if (!texture.loadFromFile(state.map.texture))
    {
        std::cout << "ERROR WITH TEXTURE" << std::endl;
    }

    sprite.setTexture(texture);
    updateView();
}

void MapRenderer::draw(sf::RenderWindow *window)
{
    updateView();

    window->draw(sprite);
}

void MapRenderer::updateView()
{
    int x = state.map.x;
    int y = state.map.y;

    sprite.setTextureRect(sf::IntRect(x, y, state.config.width, state.config.height));
}

void MapRenderer::update()
{

}

void MapRenderer::process(action_types type, sf::Event &event)
{

}
