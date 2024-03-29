//
// Created by dev04 on 6/7/19.
//

#include "MCNode.h"
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cfloat>

MCNode::MCNode(TicTacToeState state):state(state), parent(NULL),number_of_visits(0){
    this->wins = 0;
    if(this->untried_actions.size() == 0)
        this->untried_actions = state.get_legal_actions();

}
MCNode::MCNode(TicTacToeState state, MCNode * parent):state(state),parent(parent),number_of_visits(0){
    this->wins = 0;
    if(this->untried_actions.size() == 0)
        this->untried_actions = state.get_legal_actions();
}

std::vector<TicTacTurn> MCNode::get_untried_actions(){
    return this->untried_actions;
}
void MCNode::set_state(TicTacToeState state){
    this->state = state;
}
TicTacToeState MCNode::get_state(){
    return this->state;
}
int MCNode::get_number_of_visits(){
    return this->number_of_visits;
}
bool MCNode::is_fully_expanded(){
    return this->untried_actions.size() == 0;
}

double MCNode::ucb(double c_param){
    int father_visits = 1;
    if(this->parent){
        father_visits = this->parent->get_number_of_visits();
    }
    double exploration = (this->q()/(this->get_number_of_visits()*1.0));
    double exploitation = sqrt((2.0*log(  father_visits * 1.0 ) / (this->get_number_of_visits())));
    return  exploration + c_param * exploitation;
}

MCNode * MCNode::get_best_child(double c_param){

    MCNode * max = this->children[0];
    for(int i = 0; i < this->children.size(); i++){
        if(this->children[i]->ucb(c_param) > max->ucb(c_param)){
            max = this->children[i];
        }

    }
    return max;
}
double MCNode::q(){
    return this->wins;

}
bool MCNode::contains_child(){
    return this->children.size() != 0;
}
TicTacTurn MCNode::rollout_policy(std::vector<TicTacTurn> possible_actions){
    srand(time(NULL));
    int size = possible_actions.size();
    int index =  rand() % size;
    return possible_actions[index];

}
int MCNode::rollout(){
    TicTacToeState current_state = this->state;
    while (!current_state.finished()){

        std::vector<TicTacTurn> possible_moves = current_state.get_legal_actions();
        TicTacTurn action = this->rollout_policy(possible_moves);
        current_state = current_state.move(action);
        //printf("%f\n",current_state.game_result());


    }
    //
    //current_state.print_state();
    //printf("\n");


    return current_state.game_result();
}

MCNode * MCNode::expand(){

    srand(time(NULL));
    int size = this->untried_actions.size();
    int index =  rand() % size;

    TicTacTurn action = this->untried_actions[index];
    this->untried_actions.erase(this->untried_actions.begin()+index,this->untried_actions.begin()+index+1);
    TicTacToeState next_state = this->state.move(action);
    MCNode * child = new MCNode(next_state, this);
    this->children.push_back(child);
    return child;

}

void MCNode::print_state(){
    state.print_state();
}
bool MCNode::is_terminal(){
    return this->state.finished();
}
void MCNode::backpropagate(double win){
    this->wins+=win;
    this->number_of_visits+=1;
    if(this->parent){
        this->parent->backpropagate(win);
    }

}