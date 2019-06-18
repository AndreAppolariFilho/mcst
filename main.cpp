#include "MCNode.h"
#include "TicTacToeState.h"
#include "Tree.h"
#include <cstdio>
int main() {

    int board[3][3] = {
            {-1,-1,-1},
            {-1,-1,-1},
            {-1,-1,-1}
    };

    TicTacToeState state = TicTacToeState(board,0);
    printf("%d\n",state.get_legal_actions().size());
    MCNode * root = new MCNode(state);
    while(!root->is_terminal()) {
        state = root->get_state();
        state.next_to_move = 0;
        root->set_state(state);
        Tree tree = Tree(root);
        root = tree.best_action(100);

        printf("Play of O\n");
        state = root->get_state();
        root->print_state();

        if(root->get_state().finished()) break;

        printf("Play of X\n");
        state = root->get_state();
        state.next_to_move = 1;
        root->set_state(state);
        Tree tree1 = Tree(root);
        root = tree1.best_action(1000);
        root->print_state();
        if(root->get_state().finished()) break;

    }

    return 0;
}