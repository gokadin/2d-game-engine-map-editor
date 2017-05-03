#include <iostream>
#include "MapUpdater.h"

MapUpdater::MapUpdater(GameState& state):
        Updater(state)
{}

void MapUpdater::update()
{
    move();
}

void MapUpdater::move()
{
    moveUp();
    moveDown();
    moveRight();
    moveLeft();
}

void MapUpdater::moveUp()
{
    if (!state.character.isMovingUp || state.character.isMovingDown)
    {
        return;
    }

    state.map.y -= state.character.moveSpeed;
}

void MapUpdater::moveDown()
{
    if (!state.character.isMovingDown || state.character.isMovingUp)
    {
        return;
    }

    state.map.y += state.character.moveSpeed;
}

void MapUpdater::moveRight()
{
    if (!state.character.isMovingRight || state.character.isMovingLeft)
    {
        return;
    }

    state.map.x += state.character.moveSpeed;
}

void MapUpdater::moveLeft()
{
    if (!state.character.isMovingLeft || state.character.isMovingRight)
    {
        return;
    }

    state.map.x -= state.character.moveSpeed;
}