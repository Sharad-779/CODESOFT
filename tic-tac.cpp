#include <iostream>
#include <vector>

void printBoard(const std::vector<std::vector<char>>& board);
bool isBoardFull(const std::vector<std::vector<char>>& board);
bool checkWin(const std::vector<std::vector<char>>& board, char player);
bool makeMove(std::vector<std::vector<char>>& board, int row, int col, char player);

void printBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "  0 1 2" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            if (j < 2) std::cout << "|";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "  -----" << std::endl;
    }
}

bool isBoardFull(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool makeMove(std::vector<std::vector<char>>& board, int row, int col, char player) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}


int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';
    int row, col;
    bool validMove;
    bool gameWon = false;

    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

    while (!isBoardFull(board) && !gameWon) {
        printBoard(board);

        do {
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> row >> col;
            validMove = makeMove(board, row, col, currentPlayer);

            if (!validMove) {
                std::cout << "Invalid move. Try again." << std::endl;
            }
        } while (!validMove);

        gameWon = checkWin(board, currentPlayer);

        if (!gameWon) {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    printBoard(board);

    if (gameWon) {
        std::cout << "Player " << currentPlayer << " wins!" << std::endl;
    } else {
        std::cout << "The game is a draw!" << std::endl;
    }

    return 0;
}
