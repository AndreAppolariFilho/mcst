//
// Created by dev04 on 6/7/19.
//

#ifndef MCST_MCNODE_H
#define MCST_MCNODE_H

#include "TicTacTurn.h"
#include "TicTacToeState.h"
#include <vector>

class MCNode {
private:
    std::vector<TicTacTurn> untried_actions;
    MCNode * parent;
    TicTacToeState state;
    int number_of_visits;
    int wins;
    int loses;
    std::vector<MCNode * > children;
    double ucb(int c_param);
    TicTacTurn rollout_policy(std::vector<TicTacTurn> possible_actions);
public:
    MCNode(TicTacToeState state);
    MCNode(TicTacToeState state, MCNode * parent);
    std::vector<TicTacTurn> get_untried_actions();
    int q();
    int get_number_of_visits();
    bool is_fully_expanded();
    MCNode * get_best_child(int c_param);
    int rollout();
    void print_state();
    void backpropagate(bool win);
    MCNode * expand();

};


#endif //MCST_MCNODE_H
