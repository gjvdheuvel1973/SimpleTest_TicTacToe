#include <iostream> // For input and output operations (like std::cout and std::cin)
#include <vector>   // For using the std::vector container to represent the board

/**
 * @brief Prints the Tic Tac Toe board to the console.
 * @param board A constant reference to the vector representing the game board.
 */
void print_board(const std::vector<char>& board) {
    // Print the board in a 3x3 grid format
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << std::endl;
}

/**
 * @brief Checks if the specified player has won the game.
 * @param board A constant reference to the vector representing the game board.
 * @param player The character representing the current player ('X' or 'O').
 * @return True if the player has won, false otherwise.
 */
bool check_win(const std::vector<char>& board, char player) {
    // Check all three rows for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i * 3] == player && board[i * 3 + 1] == player && board[i * 3 + 2] == player) {
            return true;
        }
    }
    // Check all three columns for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) {
            return true;
        }
    }
    // Check the two diagonals for a win
    if (board[0] == player && board[4] == player && board[8] == player) {
        return true;
    }
    if (board[2] == player && board[4] == player && board[6] == player) {
        return true;
    }
    // If no winning condition is met, return false
    return false;
}

/**
 * @brief Checks if the game has ended in a draw.
 * @param board A constant reference to the vector representing the game board.
 * @return True if the game is a draw, false otherwise.
 */
bool check_draw(const std::vector<char>& board) {
    // A draw occurs if all cells are filled and no one has won.
    // This function checks if any cell is still a number (not 'X' or 'O').
    for (char cell : board) {
        if (cell != 'X' && cell != 'O') {
            return false; // Found an empty cell, so it's not a draw yet
        }
    }
    // If no empty cells are found, the game is a draw
    return true;
}

/**
 * @brief The main function where the game is executed.
 */
int main() {
    // Initialize the board with numbers 1-9 representing the positions
    std::vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char current_player = 'X'; // 'X' always starts the game
    int move;                  // Variable to store the player's chosen position

    // The main game loop, which continues until there is a win or a draw
    while (true) {
        // Clear the screen or add space for better readability
        std::cout << std::endl;
        // Display the current board
        print_board(board);
        // Prompt the current player for their move
        std::cout << "Player " << current_player << ", enter your move (1-9): ";
        std::cin >> move;

        // Validate the move: check if it's within the 1-9 range and if the spot is already taken
        if (move < 1 || move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O') {
            std::cout << "Invalid move. Try again." << std::endl;
            continue; // Skip the rest of the loop and ask for input again
        }

        // Place the player's mark on the board (subtract 1 because vector is 0-indexed)
        board[move - 1] = current_player;

        // Check if the current player has won
        if (check_win(board, current_player)) {
            std::cout << std::endl;
            print_board(board); // Show the final board
            std::cout << "Player " << current_player << " wins!" << std::endl;
            break; // Exit the game loop
        }

        // Check if the game is a draw (only if no one has won)
        if (check_draw(board)) {
            std::cout << std::endl;
            print_board(board); // Show the final board
            std::cout << "It's a draw!" << std::endl;
            break; // Exit the game loop
        }

        // Switch turns to the other player
        current_player = (current_player == 'X') ? 'O' : 'X';
    }

    // Return 0 to indicate successful execution
    return 0;
}
