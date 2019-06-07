//
// Created by dev04 on 6/7/19.
//

#ifndef MCST_TICTACTURN_H
#define MCST_TICTACTURN_H


class TicTacTurn {
private:
    int x, y, next_to_move;
public:
    TicTacTurn(int x, int y, int next_to_move);
    int get_x();
    int get_y();
    int get_next_to_move();

};


#endif //MCST_TICTACTURN_H
