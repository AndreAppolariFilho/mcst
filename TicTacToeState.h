//
// Created by dev04 on 6/6/19.
//

#ifndef MCST_TICTACTOESTATE_H
#define MCST_TICTACTOESTATE_H
#include "State.h"

class TicTacToeState : public State {
    int game_result();
    bool finished();
    State move(TicTacTurn m);
    std::vector<TicTacTurn> get_legal_actions();
};


#endif //MCST_TICTACTOESTATE_H
