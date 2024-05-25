#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


void printBoard(int board[], int n)
 {
 	 int i, j;
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            if (board[i] == j) {
                printf("Q ");  
            } else {
                printf(". "); 
            }
        }
        printf("\n");
    }
    printf("\n");
}


bool isSafe(int board[], int row, int col) {
	int i;
    for (i = 0; i < row; i++) {
    
        if (board[i] == col || abs(board[i] - col) == (row - i)) {
            return false;  
        }
    }
    return true;  
}

bool solveNQueens(int board[], int row, int n) {
    if (row == n) {  
        printBoard(board, n);  
        return true;  
    }

    bool foundSolution = false;  
    int col;
    for ( col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;  
            
            foundSolution |= solveNQueens(board, row + 1, n);
        }
    }
    return foundSolution;
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    int* board = (int*)malloc(n * sizeof(int)); 
    bool hasSolution = solveNQueens(board, 0, n);  

    if (!hasSolution) {
        printf("No solution found for %d queens.\n", n);
    }

    free(board); 
    return 0;
}

