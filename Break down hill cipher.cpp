#include <stdio.h>
#include <stdlib.h>

#define MOD 26
#define MATRIX_SIZE 2


int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; 
}

int determinant(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) % MOD;
}


void adjoint(int matrix[MATRIX_SIZE][MATRIX_SIZE], int adj[MATRIX_SIZE][MATRIX_SIZE]) {
    adj[0][0] = matrix[1][1];
    adj[0][1] = -matrix[0][1];
    adj[1][0] = -matrix[1][0];
    adj[1][1] = matrix[0][0];
}


int invertMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE], int inv[MATRIX_SIZE][MATRIX_SIZE]) {
    int det = determinant(matrix);
    int invDet = modInverse(det, MOD);
    if (invDet == -1) {
        printf("Matrix is not invertible.\n");
        return 0;
    }

    int adj[MATRIX_SIZE][MATRIX_SIZE];
    adjoint(matrix, adj);


    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            inv[i][j] = (adj[i][j] * invDet) % MOD;
            if (inv[i][j] < 0) {
                inv[i][j] += MOD;
            }
        }
    }
    return 1;
}


void multiplyMatrices(int mat1[MATRIX_SIZE][MATRIX_SIZE], int mat2[MATRIX_SIZE][MATRIX_SIZE], int result[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
            result[i][j] %= MOD;
        }
    }
}

int main() {
   
    int plaintextPairs[MATRIX_SIZE][MATRIX_SIZE] = {
        {7, 4}, 
        {11, 11}
    };

   
    int ciphertextPairs[MATRIX_SIZE][MATRIX_SIZE] = {
        {13, 8}, 
        {15, 10} 
    };

    int inversePlaintext[MATRIX_SIZE][MATRIX_SIZE];
    int keyMatrix[MATRIX_SIZE][MATRIX_SIZE];

    
    if (!invertMatrix(plaintextPairs, inversePlaintext)) {
        printf("Cannot recover the key matrix because the plaintext matrix is not invertible.\n");
        return 1;
    }

   
    multiplyMatrices(inversePlaintext, ciphertextPairs, keyMatrix);

    printf("Recovered Key Matrix:\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", keyMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

