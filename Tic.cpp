#include <iostream>

class TicTacToe {
private:
    char board[3][3];

public:
    TicTacToe() {

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
    }

    void startGame() {

        displayBoard();
        
        int player = 1;
        char mark;

        do {
            player = (player % 2) ? 1 : 2;
            mark = (player == 1) ? 'X' : 'O';

            std::cout << "Jucatorul " << player << ", introdu cords (linie si coloana): ";
            int row, col;
            std::cin >> row >> col;

            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
                std::cout << "NT . Mai incearca\n";
                continue;
            }

            board[row - 1][col - 1] = mark;
            displayBoard();
            player++;
        } while (!cineCastiga() && !tablaPlina());

        if (cineCastiga()) {
            std::cout << "Jucatorul " << (--player % 2 + 1) << " a castigat!\n";
        } else {
            std::cout << "Jocul s-a incheiat cu scorul!\n";
        }
    }

private:
    void displayBoard() {
        std::cout << "Tabla de joc:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << board[i][j];
                if (j < 2) std::cout << " | ";
            }
            std::cout << std::endl;
            if (i < 2) std::cout << "---------\n";
        }
        std::cout << std::endl;
    }

    bool tablaPlina() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    bool cineCastiga() {
        for (int i = 0; i < 3; i++) {

            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') return true;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') return true;
        }


        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') return true;

        return false;
    }
};

int main() {
    TicTacToe joc;
    joc.startGame();
    return 0;
}
