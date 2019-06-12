#include <iostream>
#include "MCNode.h"
#include "TicTacToeState.h"
#include "Tree.h"
int main() {

    int board[3][3] = {
            {0,0,0},
            {0,0,0},
            {0,0,0}
    };

    TicTacToeState state = TicTacToeState(board,0);
    MCNode * root = new MCNode(state, NULL);
    Tree tree = Tree(root);
    MCNode * best_action = tree.best_action(1000);
    best_action->print_state();
    return 0;
}