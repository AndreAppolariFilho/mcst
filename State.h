//
// Created by dev04 on 6/6/19.
//

#ifndef MCST_STATE_H
#define MCST_STATE_H
#include "TicTacTurn.h"
#include <vector>

class State {
private:
    int next_to_move;
public:
    State(int next_to_move);
    virtual int game_result() = 0;
    virtual bool finished() = 0;
    virtual void move(TicTacTurn m) = 0;
    virtual std::vector<TicTacTurn> get_legal_actions() = 0;

};


#endif //MCST_STATE_H
