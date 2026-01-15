#include <iostream>
#include <vector>

// Function to print the Tic Tac Toe board
void print_board(const std::vector<char>& board) {
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << std::endl;
}

// Function to check if a player has won
bool check_win(const std::vector<char>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i * 3] == player && board[i * 3 + 1] == player && board[i * 3 + 2] == player) {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) {
            return true;
        }
    }
    // Check diagonals
    if (board[0] == player && board[4] == player && board[8] == player) {
        return true;
    }
    if (board[2] == player && board[4] == player && board[6] == player) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool check_draw(const std::vector<char>& board) {
    for (char cell : board) {
        if (cell != 'X' && cell != 'O') {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char current_player = 'X';
    int move;

    while (true) {
        std::cout << std::endl;
        print_board(board);
        std::cout << "Player " << current_player << ", enter your move (1-9): ";
        std::cin >> move;

        if (move < 1 || move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O') {
            std::cout << "Invalid move. Try again." << std::endl;
            continue;
        }

        board[move - 1] = current_player;

        if (check_win(board, current_player)) {
            std::cout << std::endl;
            print_board(board);
            std::cout << "Player " << current_player << " wins!" << std::endl;
            break;
        }

        if (check_draw(board)) {
            std::cout << std::endl;
            print_board(board);
            std::cout << "It's a draw!" << std::endl;
            break;
        }

        current_player = (current_player == 'X') ? 'O' : 'X';
    }

    return 0;
}
