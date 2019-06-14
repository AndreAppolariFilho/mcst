#include "MCNode.h"
#include "TicTacToeState.h"
#include "Tree.h"
#include <cstdio>
int main() {

    int board[3][3] = {
            {0,-1,-1},
            {0,-1,-1},
            {-1,-1,-1}
    };

    TicTacToeState state = TicTacToeState(board,0);
    printf("%d\n",state.get_legal_actions().size());
    MCNode * root = new MCNode(state);

    Tree tree = Tree(root);
    MCNode * best_action = tree.best_action(1000);
    best_action->print_state();

    return 0;
}