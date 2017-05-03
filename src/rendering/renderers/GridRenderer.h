#ifndef SFMLDEMO_GRIDRENDERER_H
#define SFMLDEMO_GRIDRENDERER_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <fstream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../Renderer.h"

/*
 * GRID_WIDTH = NODE_SIZE * 4
 * GRID_HEIGHT = NODE_SIZE * 2
 */

const int GRID_WIDTH = 32;
const int GRID_HEIGHT = 16;
const int NODE_SIZE = 8;
const int MAP_WIDTH = 3200; // must be a multiple of GRID_WIDTH
const int MAP_HEIGHT = 3200;

class GridRenderer : public Renderer
{
public:
    GridRenderer(GameState &state);

    void draw(sf::RenderWindow *window);
    void update();
    void process(action_types type, sf::Event& event);

private:
    std::vector<std::vector<int>> grid;
    sf::Texture m_tileTexture;
    sf::Sprite m_tileSprite;
    sf::RectangleShape m_tile;
    sf::Texture m_hoverTexture;
    sf::Sprite m_hoverSprite;
    bool shouldWrite;
    bool shouldErase;

    void write();
    sf::Vector2f toIsometric(float x, float y);
    sf::Vector2f toIsometric(float x, float y, float offsetX, float offsetY);
};

#endif //SFMLDEMO_GRIDRENDERER_H
