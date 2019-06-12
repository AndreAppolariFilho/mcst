//
// Created by dev04 on 6/6/19.
//

#include "Tree.h"
#include <cstdio>
Tree::Tree(MCNode * node){
    this->node = node;
}

MCNode * Tree::best_action(int simulations_number){

    MCNode * v;
    int reward;

    for(int i = 0; i < simulations_number; i++)
    {
        v = this->tree_policy();
        reward = v->rollout();
        if(reward > 0)
        {
            v->backpropagate(true);
        }
        else
        {
            v->backpropagate(false);
        }
    }
    return v->get_best_child(0.);
}

MCNode * Tree::tree_policy(){
    MCNode * current_node = this->node;
    while(!current_node->is_fully_expanded())
    {
        if(!current_node->is_fully_expanded())
            return current_node->expand();
        else
            current_node = current_node->get_best_child(1.4);
    }
    return current_node;
}

