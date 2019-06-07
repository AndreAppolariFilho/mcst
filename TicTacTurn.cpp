//
// Created by dev04 on 6/7/19.
//

#include "TicTacTurn.h"
TicTacTurn::TicTacTurn(int x, int y, int next_to_move){
    this->x = x;
    this->y = y;
    this->next_to_move = next_to_move;
}
int TicTacTurn::get_x(){
    return this->x;
}
int TicTacTurn::get_y(){
    return this->y;
}
int TicTacTurn::get_next_to_move(){
    return this->next_to_move;
}