#ifndef SFMLDEMO_MAPREDUCER_H
#define SFMLDEMO_MAPREDUCER_H

#include "../../states/GameState.h"
#include "../../actions/ActionTypes.h"
#include "../Reducer.h"

class MapReducer : public Reducer
{
public:
    MapReducer(GameState& state);

    void process(action_types type);
};

#endif //SFMLDEMO_MAPREDUCER_H
