//
// Created by dev04 on 6/6/19.
//

#include "TicTacToeState.h"
#include <cstdio>
TicTacToeState::TicTacToeState():State(1){
    printf("teste");
    this->players = 2;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = 0;
        }
    }
}

TicTacToeState::TicTacToeState(int board[3][3], int next_turn):State(next_turn){

    this->players = 2;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            this->board[i][j] = board[i][j];
        }
    }
}

int TicTacToeState::game_result(){
    for(int i = 0; i < 3;i++) {
        if (this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2]) {
            //Computer wins
            if (this->board[i][1] == 0)
                return 1;
            //Computer loses
            if (this->board[i][1] == 1)
                return -1;
        }
    }

    for(int j = 0; j < 3;j++) {
        if (this->board[0][j] == this->board[1][j] && this->board[1][j] == this->board[2][j]) {
            //Computer wins
            if (this->board[1][j] == 0)
                return 1;
            //Computer loses
            if (this->board[1][j] == 1)
                return -1;
        }
    }

    if(this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2])
    {
        //Computer wins
        if (this->board[1][1] == 0)
            return 1;
        //Computer loses
        if (this->board[1][1] == 1)
            return -1;
    }

    if(this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0])
    {
        //Computer wins
        if (this->board[1][1] == 0)
            return 1;
        //Computer loses
        if (this->board[1][1] == 1)
            return -1;
    }

    return 0;

}

bool TicTacToeState::finished(){
    for(int i = 0; i < 3;i++) {
        if (this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2]) {
            return false;
        }
    }

    for(int j = 0; j < 3;j++) {
        return false;
    }

    if(this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2])
    {
        return false;
    }

    if(this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0])
    {
        return false;
    }

    return true;

}
State TicTacToeState::move(TicTacTurn m){
    int new_board[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            new_board[i][j] = this->board[i][j];
        }
    }
    new_board[m.get_y()][m.get_x()] = m.get_next_to_move();
    int next_to_move = (m.get_next_to_move()+1) % this->players;
    return TicTacToeState(new_board, next_to_move);
}
void TicTacToeState::print_state(){
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ",&board[i][j]);
        }
        printf("\n");
    }
}
std::vector<TicTacTurn> TicTacToeState::get_legal_actions(){
    std::vector<TicTacTurn> legal_actions;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == 0)
            {
                TicTacTurn turn = TicTacTurn(j,i, this->next_to_move);
                legal_actions.push_back(turn);
            }
        }
    }
    return legal_actions;

}