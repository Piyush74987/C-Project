#include <stdio.h>

char board[3][3]; // 3x3 board
char player = 'X'; // Starting player
int i, j; // Declaring i, j outside loops

// Function to initialize the board
void initializeBoard() {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the board
void printBoard() {
    printf("\n");
    for (i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

// Function to check if the game is won
int checkWin() {
    for (i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return 1; // Row check
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return 1; // Column check
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return 1; // Diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return 1; // Other diagonal
    return 0;
}

// Function to check if the board is full (draw condition)
int isDraw() {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

// Function to handle player moves
void makeMove() {
    int row, col;
    while (1) {
        printf("Player %c, enter row (1-3) and column (1-3): ", player);
        scanf("%d %d", &row, &col);
        row--; col--; // Adjusting for 0-based index

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

// Main function
int main() {
    initializeBoard();
    
    while (1) {
        printBoard();
        makeMove();
        
        if (checkWin()) {
            printBoard();
            printf("Player %c wins!\n", player);
            break;
        }

        if (isDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        // Switch players
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}

