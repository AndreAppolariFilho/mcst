//
// Created by dev04 on 6/6/19.
//

#ifndef MCST_TICTACTOESTATE_H
#define MCST_TICTACTOESTATE_H

#include "TicTacTurn.h"
#include <vector>

class TicTacToeState{
private:
    int board[3][3];

    int players;
public:
    int next_to_move;
    double game_result();
    bool finished();
    TicTacToeState move(TicTacTurn m);
    void print_state();
    std::vector<TicTacTurn> get_legal_actions();
    TicTacToeState();
    TicTacToeState(int board[3][3], int next_turn);
};


#endif //MCST_TICTACTOESTATE_H
