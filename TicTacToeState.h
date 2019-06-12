//
// Created by dev04 on 6/6/19.
//

#ifndef MCST_TICTACTOESTATE_H
#define MCST_TICTACTOESTATE_H
#include "State.h"

class TicTacToeState : public State {
private:
    int board[3][3];

public:
    int game_result();
    bool finished();
    State move(TicTacTurn m);
    void print_state();
    std::vector<TicTacTurn> get_legal_actions();
    TicTacToeState();
    TicTacToeState(int board[3][3], int next_turn);
};


#endif //MCST_TICTACTOESTATE_H
