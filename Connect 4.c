//      Presented By  Zeyad Mohamed Ahmed    &&     Ahmed Anwar Ahmed 

#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 7

char board[ROWS][COLS];

// Function to initialize the game board
void BuiltBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the game board
void displayBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("-----------------------------\n");
}

// Function to check if a player has won

int checkWin(char player) {

    // Check horizontally
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player &&
                board[i][j + 1] == player &&
                board[i][j + 2] == player &&
                board[i][j + 3] == player) {
                return 1; // Winning condition
            }
        }
    }

    // Check vertically
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == player &&
                board[i + 1][j] == player &&
                board[i + 2][j] == player &&
                board[i + 3][j] == player) {
                return 1; // Winning condition
            }
        }
    }

    // Check diagonally (positive slope)
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player &&
                board[i + 1][j + 1] == player &&
                board[i + 2][j + 2] == player &&
                board[i + 3][j + 3] == player) {
                return 1; // Winning condition
            }
        }
    }

    // Check diagonally (negative slope)
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 3; j < COLS; j++) {
            if (board[i][j] == player &&
                board[i + 1][j - 1] == player &&
                board[i + 2][j - 2] == player &&
                board[i + 3][j - 3] == player) {
                return 1; // Winning condition
            }
        }
    }

    return 0; // No winning condition
}

// Function to place a piece on the board
void placePiece(int column, char player) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][column] == ' ') {
            board[i][column] = player;
            return;
        }
    }
}



// Function to play against AI
void playAgainstAI() {
    // Your AI game logic here
    printf("Playing against AI\n");
    int currentPlayer = 1; // Player 1 starts
    int column;

    do {
        if (currentPlayer == 1) {
            displayBoard();
            printf("Player 1, enter a column (0-6): ");
            scanf("%d", &column);
        }
        else {
            // AI's turn - choose a random valid move
            column = rand() % COLS;
        }

        if (column < 0 || column >= COLS || board[0][column] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        placePiece(column, (currentPlayer == 1) ? 'X' : 'O');

        if (checkWin((currentPlayer == 1) ? 'X' : 'O')) {
            displayBoard();
            if (currentPlayer == 1)
                printf("Player 1 wins!\n");
            else
                printf("AI wins!\n");
            break;
        }

        currentPlayer = 3 - currentPlayer; // Switch player (1 to 2, 2 to 1)
    } while (1); // Infinite loop, game ends with a break statement

}

int main() {
    int choice;

    printf("Welcome to the Game!\n");
    printf("Choose an option:\n");
    printf("1. Play against AI\n");
    printf("2. Play against another player\n");

    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    BuiltBoard();

    if (choice == 1) {
        playAgainstAI();
    }
    else if (choice == 2) {
        int currentPlayer = 1; // Player 1 starts
        int column;

        do {
            displayBoard();
            printf("Player %d, enter a column (0-6): ", currentPlayer);
            scanf("%d", &column);

            if (column < 0 || column >= COLS || board[0][column] != ' ') {
                printf("Invalid move. Try again.\n");
                continue;
            }

            placePiece(column, (currentPlayer == 1) ? 'X' : 'O');

            if (checkWin((currentPlayer == 1) ? 'X' : 'O')) {
                displayBoard();
                printf("Player %d wins!\n", currentPlayer);
                break;
            }

            currentPlayer = 3 - currentPlayer; // Switch player (1 to 2, 2 to 1)
        } while (1); // Infinite loop, game ends with a break statement
    }
    else {
        printf("Invalid choice. Exiting the game.\n");
    }

    return 0;
}