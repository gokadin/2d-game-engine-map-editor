#include <iostream>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>
#include "GridRenderer.h"

GridRenderer::GridRenderer(GameState &state):
        Renderer(state), shouldWrite(false), shouldErase(false)
{
    if (!m_tileTexture.loadFromFile("../assets/tiles/tile.png"))
    {
        std::cout << "Could not load tile texture." << std::endl;
    }
    m_tileSprite.setTexture(m_tileTexture);

    if (!m_hoverTexture.loadFromFile("../assets/tiles/hover_" + std::to_string(NODE_SIZE) + ".png"))
    {
        std::cout << "Could not load tile texture." << std::endl;
    }
    m_hoverSprite.setTexture(m_hoverTexture);

    m_tile.setFillColor(sf::Color::Blue);
    m_tile.setSize(sf::Vector2f(NODE_SIZE, NODE_SIZE));

    for (int i = 0; i < MAP_WIDTH / GRID_WIDTH; i++)
    {
        std::vector<int> row;
        for (int j = 0; j < MAP_HEIGHT / GRID_WIDTH; j++)
        {
            row.push_back(0);
        }
        grid.push_back(row);
    }
}

void GridRenderer::update()
{

}

void GridRenderer::draw(sf::RenderWindow *window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

    int tx = mousePos.x + state.map.x - MAP_WIDTH / 2 + GRID_WIDTH;
    int ty = mousePos.y + state.map.y;
    float mouseCartX = (2.0f * ty + tx) / 4.0f;
    float mouseCartY = (2.0f * ty - tx) / 4.0f;
    int mouseI = (int)floor(mouseCartX / NODE_SIZE);
    int mouseJ = (int)floor(mouseCartY / NODE_SIZE);

    std::cout << mouseI << " " << mouseJ << std::endl;

    for (int i = 0; i < MAP_WIDTH / GRID_WIDTH; i++)
    {
        for (int j = 0; j < MAP_HEIGHT / GRID_WIDTH; j++)
        {
            int x = i * NODE_SIZE;
            int y = j * NODE_SIZE;
            m_tileSprite.setPosition(toIsometric(x, y, state.map.x - MAP_WIDTH / 2 + GRID_WIDTH, state.map.y));
            window->draw(m_tileSprite);

            if (grid[i][j] > 0 || (mouseI == i && mouseJ == j))
            {
                m_hoverSprite.setPosition(toIsometric(x, y, state.map.x - MAP_WIDTH / 2 + GRID_WIDTH, state.map.y));
                window->draw(m_hoverSprite);
            }

            if (mouseI == i && mouseJ == j)
            {
                if (shouldWrite && grid[i][j] == 0)
                {
                    grid[i][j] = 1;
                }
                else if (shouldErase && grid[i][j] != 0)
                {
                    grid[i][j] = 0;
                }
            }
        }
    }
}

void GridRenderer::process(action_types type, sf::Event &event)
{
    switch (type)
    {
        case action_types::MOUSE_BUTTON_PRESSED:
            if (event.mouseButton.button == sf::Mouse::Button::Left)
            {
                shouldWrite = true;
            }
            else if (event.mouseButton.button == sf::Mouse::Button::Right)
            {
                shouldErase = true;
            }
            break;
        case action_types::MOUSE_BUTTON_RELEASED:
            shouldWrite = false;
            shouldErase = false;
            break;
        case action_types::CHARACTER_MOVE_DOWN:
            if (event.key.code == sf::Keyboard::P)
            {
                write();
            }
            break;
    }
}

void GridRenderer::write()
{
    std::vector<std::string> lines;
    for (int i = 0; i < MAP_WIDTH / GRID_WIDTH; i++)
    {
        std::string line = "";
        for (int j = 0; j < MAP_HEIGHT / GRID_WIDTH; j++)
        {
            if (grid[i][j] == 0)
            {
                line += "0,";
            }
            else
            {
                line += "1,";
            }
        }
        lines.push_back(line.substr(0, line.size() - 1));
    }

    std::ofstream outfile("../generated/bounds", std::fstream::out);
    for (int i = 0; i < lines.size(); i++)
    {
        outfile << lines[i] << std::endl;
    }

    outfile.close();
}

sf::Vector2f GridRenderer::toIsometric(float x, float y)
{
    return toIsometric(x, y, 0, 0);
}

sf::Vector2f GridRenderer::toIsometric(float x, float y, float offsetX, float offsetY)
{
    return sf::Vector2f(((2 * x - 2 * y) - NODE_SIZE * 2) - offsetX, (x + y) - offsetY);
}
