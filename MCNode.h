//
// Created by dev04 on 6/7/19.
//

#ifndef MCST_MCNODE_H
#define MCST_MCNODE_H

#include "TicTacTurn.h"
#include "State.h"
#include <vector>

class MCNode {
private:
    std::vector<TicTacTurn> untried_actions;
    MCNode * parent;
    State state;
    int number_of_visits;
public:
    MCNode(State state);
    MCNode(State state, MCNode * parent);
    std::vector<TicTacTurn> get_untried_actions();
    virtual int q() = 0;
    int get_number_of_visits();
    bool is_fully_expanded();

};


#endif //MCST_MCNODE_H
