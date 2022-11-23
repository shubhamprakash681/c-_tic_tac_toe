#include<iostream>
using namespace std;

class TicTacToe {
    private:
    char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    char player = 'X';
    int currentChoice = -1;
    int row = -1, col = -1;
    bool draw = true;

    public:
    // function to print welcome note to the screen
    void printWelcomeNote() {
        cout<<"---------Tic Tac Toe Game---------"<<endl;
        cout<<"-----------For 2 Players-----------\n\n";
    }

    // function to render the current board layout to the screen
    void printBoard() {
        cout<<"\nPLAYER - 1 [X]\t PLAYER - 2 [O]\n";
        cout<<"\t     |     |     \n";
        cout<<"\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<" \n";
        cout<<"\t_____|_____|_____\n";
        cout<<"\t     |     |     \n";
        cout<<"\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<" \n";
        cout<<"\t_____|_____|_____\n";
        cout<<"\t     |     |     \n";
        cout<<"\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<" \n";
        cout<<"\t     |     |     \n";
    }

    // function to simulate a move for the current player
    void turn() {
        if (player == 'X') {
            cout<<"\nPlayer 1 [X] turn. Enter a grid number: ";
        }else if (player == 'O') {
            cout<<"\nPlayer 2 [O] turn. Enter a grid number: ";
        }
        
        cin>>currentChoice;
        // cout<<"CurrentChoice: "<<currentChoice<<endl;

        // grid no. to row, col conversion using switch-case
        switch (currentChoice) {
            case 1: {
                row = 0;
                col = 0;
                break;
            }
            case 2: {
                row = 0;
                col = 1;
                break;
            }
            case 3: {
                row = 0;
                col = 2;
                break;
            }

            case 4: {
                row = 1;
                col = 0;
                break;
            }
            case 5: {
                row = 1;
                col = 1;
                break;
            }
            case 6: {
                row = 1;
                col = 2;
                break;
            }

            case 7: {
                row = 2;
                col = 0;
                break;
            }
            case 8: {
                row = 2;
                col = 1;
                break;
            }
            case 9: {
                row = 2;
                col = 2;
                break;
            }

            default: {
                cout<<"\nInvalid Grid Entered\n";
                cout<<"Try Again!!\n";

                turn();
            }
        }

        // making actual move according to the current player
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            switch (player) {
                case 'X': {
                    board[row][col] = 'X';
                    player = 'O';
                    break;
                }
                case 'O': {
                    board[row][col] = 'O';
                    player = 'X';
                    break;
                }
                default: {
                    cout<<"\nError!!\n";
                    cout<<"Try Again!!\n";

                    turn();
                }
            }
        }else {
            // cout<<"Here, "<<"player= "<<player<<" currentChoice= "<<currentChoice<<endl;
            cout<<"\nGrid already filled\n";
            cout<<"Please Try Again!!\n";

            turn();
        }

        // printing current board layout after each move
        printBoard();
    }

    // function to check if all grids has been changed or not
    bool isAllGridFilled() {
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if ((board[i][j] != 'X') && (board[i][j] != 'O')) {
                    return false;
                }
            }
        }

        return true;
    }

    // function that checks if any of the condition satisfies for wining
    // if so, returns the winning player name
    char gameWon() {
        for (int i=0; i<3; i++) {
            // win condition for row
            if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
                draw = false;
                switch (board[i][0]) {
                    case 'X':
                        return 'X';
                    case 'O':
                        return 'O';

                    default:
                        return 'N';
                }
            }
        }


        // win condition for column
        for (int i=0; i<3; i++) {
            if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
                draw = false;
                switch (board[0][i]) {
                    case 'X':
                        return 'X';
                    case 'O':
                        return 'O';

                    default:
                        return 'N';
                }
            }
        }

        // win condition for diag 1:
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            draw = false;
            switch (board[0][0]) {
                case 'X':
                    return 'X';
                case 'O':
                    return 'O';

                default:
                    return 'N';
            }
        }

        // win condition for diag 2:
        if(board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            draw = false;
            switch (board[0][2]) {
                case 'X':
                    return 'X';
                case 'O':
                    return 'O';

                default:
                    return 'N';
            }
        }
        

        // return 'N' if no condition satisfies
        return 'N';
    }

    bool getDraw() {
        return draw;
    }
};

int main() {
    // object initialisation
    TicTacToe ticTacToe;

    ticTacToe.printWelcomeNote();
    ticTacToe.printBoard();

    // run until all grid has not been modified
    // or any winner has not been declared
    while (!ticTacToe.isAllGridFilled()) {
        ticTacToe.turn();
        if (ticTacToe.gameWon() == 'X') {
            cout<<"\nPlayer 1 [X] win\n";
            break;
        }else if (ticTacToe.gameWon() == 'O') {
            cout<<"\nPlayer 2 [O] win\n";
            break;
        }
    }
    
    // print DRAW message in case of match tie
    if (ticTacToe.getDraw()) {
        cout<<"Game Draw!!\n";
    }
    
    return 0;
}