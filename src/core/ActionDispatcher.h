#ifndef SFMLDEMO_ACTIONDISPATCHER_H
#define SFMLDEMO_ACTIONDISPATCHER_H

#include <vector>
#include <SFML/Window/Event.hpp>
#include "../actions/ActionTypes.h"
#include "../reducers/Reducer.h"

class ActionDispatcher
{
public:
    ActionDispatcher(GameState& state);
    ~ActionDispatcher();

    void dispatch(action_types type);
    void dispatch(action_types type, sf::Event& event);

private:
    GameState& state;
    std::vector<Reducer *> reducers;
};

#endif //SFMLDEMO_ACTIONDISPATCHER_H
