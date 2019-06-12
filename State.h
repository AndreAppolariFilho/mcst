//
// Created by dev04 on 6/6/19.
//

#ifndef MCST_STATE_H
#define MCST_STATE_H
#include "TicTacTurn.h"
#include <vector>

class State {
protected:
    int next_to_move;
    int players;
public:
    State(){}
    State(int next_to_move);
    virtual int game_result();
    virtual bool finished();
    virtual State move(TicTacTurn m);
    virtual std::vector<TicTacTurn> get_legal_actions();

};


#endif //MCST_STATE_H
