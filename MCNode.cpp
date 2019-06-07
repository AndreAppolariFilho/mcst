//
// Created by dev04 on 6/7/19.
//

#include "MCNode.h"
MCNode::MCNode(State state):state(state), parent(NULL),number_of_visits(0){

}
MCNode::MCNode(State state, MCNode * parent):state(state),parent(parent),number_of_visits(0){
    this->untried_actions = state.get_legal_actions();
}

std::vector<TicTacTurn> MCNode::get_untried_actions(){
    return this->untried_actions;
}
int MCNode::get_number_of_visits(){
    return this->number_of_visits;
}
bool MCNode::is_fully_expanded(){
    return this->untried_actions.size() == 0;
}