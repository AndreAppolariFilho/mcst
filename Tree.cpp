//
// Created by dev04 on 6/6/19.
//

#include "Tree.h"
#include <cstdio>
#include <cmath>

Tree::Tree(MCNode * node){
    this->node = node;
}

MCNode * Tree::best_action(int simulations_number){

    MCNode * v;
    int reward;

    for(int i = 0; i < simulations_number; i++)
    {
        v = this->select();
        v = this->tree_policy();
        reward = v->rollout();
        v->backpropagate(reward);
    }
    /*for(int i = 0; i < this->node->children.size(); i++)
    {
        printf("%f\n",this->node->children[i]->q());

        printf("\n");
    }*/
    return this->node->get_best_child(0.);
}

MCNode * Tree::select(){
    MCNode * current_node = this->node;
    while(current_node->is_fully_expanded() and current_node->contains_child())
        current_node = this->node->get_best_child(sqrt(2));
    return current_node;
}

MCNode * Tree::tree_policy(){
    MCNode * current_node = this->node;
    while(!current_node->is_fully_expanded())
    {
        return current_node->expand();
        /*
        if(!current_node->is_fully_expanded())
            return
        else
            current_node = current_node->get_best_child(1.4);
        */
    }
    return current_node;
}

