#include <iostream>
#include <limits>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char player = 'X', ai = 'O';

// Display board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}


// Print board
void printBoard() {
    cout << "\n";
    for(int i = 0; i<3; i++) {
        for(int j=0;j<3;j++) {
            cout << " " << board[i][j] << " ";
            if(j<2) cout << "|";
        }
        cout << "\n";
        if(i<2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Check if moves are left
bool movesLeft() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j]!='X' && board[i][j]!='O')
                return true;
    return false;
}

// Evaluate board
int evaluate() {
    // Check rows
    for(int row=0;row<3;row++) {
        if(board[row][0]==board[row][1] && board[row][1]==board[row][2]) {
            if(board[row][0]==ai) return +10;
            else if(board[row][0]==player) return -10;
        }
    }
    // Check columns
    for(int col=0;col<3;col++) {
        if(board[0][col]==board[1][col] && board[1][col]==board[2][col]) {
            if(board[0][col]==ai) return +10;
            else if(board[0][col]==player) return -10;
        }
    }
    // Check diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) {
        if(board[0][0]==ai) return +10;
        else if(board[0][0]==player) return -10;
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) {
        if(board[0][2]==ai) return +10;
        else if(board[0][2]==player) return -10;
    }
    return 0;
}

// Minimax algorithm
int minimax(bool isMax) {
    int score = evaluate();

    if(score==10) return score;
    if(score==-10) return score;
    if(!movesLeft()) return 0;

    if(isMax) {
        int best = -1000;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(board[i][j]!='X' && board[i][j]!='O') {
                    char backup = board[i][j];
                    board[i][j] = ai;
                    best = max(best, minimax(false));
                    board[i][j] = backup;
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(board[i][j]!='X' && board[i][j]!='O') {
                    char backup = board[i][j];
                    board[i][j] = player;
                    best = min(best, minimax(true));
                    board[i][j] = backup;
                }
            }
        }
        return best;
    }
}

// Find best move for AI
pair<int,int> findBestMove() {
    int bestVal = -1000;
    pair<int,int> bestMove = {-1,-1};

    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(board[i][j]!='X' && board[i][j]!='O') {
                char backup = board[i][j];
                board[i][j] = ai;
                int moveVal = minimax(false);
                board[i][j] = backup;
                if(moveVal>bestVal) {
                    bestMove = {i,j};
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

// Player move
void playerMove() {
    int move;
    while(true) {
        cout << "Enter your move (1-9): ";
        cin >> move;
        if(cin.fail()) { cin.clear(); cin.ignore(1000,'\n'); continue; }
        if(move<1 || move>9) continue;
        int row = (move-1)/3;
        int col = (move-1)%3;
        if(board[row][col]!='X' && board[row][col]!='O') {
            board[row][col] = player;
            break;
        }
    }
}

int main() {
    cout << "Tic-Tac-Toe: You (X) vs AI (O)\n";
    printBoard();

    while(true) {
        playerMove();
        printBoard();
        if(evaluate()==-10) { cout << "You win! 🎉\n"; break; }
        if(!movesLeft()) { cout << "Draw!\n"; break; }

        cout << "AI is making a move...\n";
        pair<int,int> aiMove = findBestMove();
        board[aiMove.first][aiMove.second] = ai;
        printBoard();
        if(evaluate()==10) { cout << "AI wins! \n"; break; }
        if(!movesLeft()) { cout << "Draw!\n"; break; }
    }

    displayBoard();
    cout << "\n Gameover GGWP...";
    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get();

    return 0;
}
