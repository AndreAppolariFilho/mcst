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

    TicTacToeState state;
    int number_of_visits;
    double wins;
    int loses;

    double ucb(double c_param);
    TicTacTurn rollout_policy(std::vector<TicTacTurn> possible_actions);
public:
    MCNode * parent;
    std::vector<MCNode * > children;
    MCNode(TicTacToeState state);
    MCNode(TicTacToeState state, MCNode * parent);
    std::vector<TicTacTurn> get_untried_actions();
    double q();
    int get_number_of_visits();
    bool is_fully_expanded();
    bool contains_child();
    MCNode * get_best_child(double c_param);
    int rollout();
    void print_state();
    void backpropagate(double win);
    MCNode * expand();

};


#endif //MCST_MCNODE_H
