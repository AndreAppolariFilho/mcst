//
// Created by dev04 on 6/7/19.
//

#include "MCNode.h"
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>

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

double MCNode::ucb(int c_param){
    int father_visits = 0;
    if(this->parent){
        father_visits = this->parent->get_number_of_visits();
    }
    return (this->q()/(this->get_number_of_visits()*1.0)) +
    c_param * sqrt(2.0 * log( father_visits * 1.0 ) / this->q());
}

MCNode * MCNode::get_best_child(int c_param){
    MCNode * max = this->children[0];
    for(int i = 0; i < this->children.size(); i++){

        if(this->children[i]->ucb(c_param) > max->ucb(c_param)){
            max = this->children[i];
        }
    }
    return max;
}
int MCNode::q(){
    return this->wins;

}
TicTacTurn MCNode::rollout_policy(std::vector<TicTacTurn> possible_actions){
    srand(time(NULL));
    int size = possible_actions.size();
    int index =  rand() % size;
    return possible_actions[index];

}
int MCNode::rollout(){
    State current_state = this->state;
    while (!current_state.finished()){
        std::vector<TicTacTurn> possible_moves = current_state.get_legal_actions();
        TicTacTurn action = this->rollout_policy(possible_moves);
        current_state = current_state.move(action);
    }
    return current_state.game_result();
}

MCNode * MCNode::expand(){
    TicTacTurn action = this->untried_actions.back();
    this->untried_actions.pop_back();
    State next_state = this->state.move(action);
    MCNode child = MCNode(next_state, this);
    this->children.push_back(&child);
    return &child;

}
void MCNode::print_state(){
    state.print_state();
}
void MCNode::backpropagate(bool win){
    if(win){
        this->wins+=1;
    }else{
        this->loses+=1;
    }
    this->number_of_visits++;
    if(this->parent){
        this->parent->backpropagate(win);
    }

}