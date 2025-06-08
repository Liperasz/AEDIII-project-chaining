//
// Created by liperasz on 27/05/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {

    Matrix *matrix = createMatrix(3, 5);
    allocateMatrixElements(matrix);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            insertValue(matrix, i+1, j+1, (i+1)*(j+1)*2);
        }
    }

    printf("Matriz original:\n");
    printMatrix(matrix);
    printf("\n\n");

    Element *element;
    int x = 2, y = 5;
    if (consultValuePosition(matrix, &element, 2, 5) == 1) {
        printf("Valor da posição (%d,%d): %d\n", x, y, element->data);
    }

    int value = 24;
    if (consultValue(matrix, &element, value) == 1) {
        printf("O valor %d está na matriz\n", value);
    } else {
        printf("O valor %d nao está na matriz\n", value);
    }

    printNeighbours(matrix, 2, 3);

    printf("Trocando os elementos das posições (1,1) e (3,5):\n");
    swapElements(matrix, 1, 1, 3, 5);

    printf("Matriz após troca:\n");
    printMatrix(matrix);

    printf("Adicionando Linha\n");
    addRow(matrix, 1);
    printMatrix(matrix);
    printf("\n\n");

    printf("Adicionando Linha\n");
    addRow(matrix, 4);
    printMatrix(matrix);
    printf("\n\n");

    printf("Adicionando Linha\n");
    addRow(matrix, 8);
    printMatrix(matrix);
    printf("\n\n");

    printf("Adicionando Coluna\n");
    addColumn(matrix, 1);
    printMatrix(matrix);
    printf("\n\n");

    printf("Adicionando Coluna\n");
    addColumn(matrix, 2);
    printMatrix(matrix);
    printf("\n\n");

    printf("Adicionando Coluna\n");
    addColumn(matrix, 30);
    printMatrix(matrix);
    printf("\n\n");

    printf("Removendo Linha\n");
    removeRow(matrix, 1);
    printMatrix(matrix);
    printf("\n\n");

    printf("Removendo Linha\n");
    removeRow(matrix, 2);
    printMatrix(matrix);
    printf("\n\n");

    printf("Removendo Linha\n");
    removeRow(matrix, 4);
    printMatrix(matrix);
    printf("\n\n");

    printf("Removendo Coluna\n");
    removeColumn(matrix, 1);
    printMatrix(matrix);
    printf("\n\n");

    printf("Removendo Coluna\n");
    removeColumn(matrix, 3);
    printMatrix(matrix);
    printf("\n\n");

    printf("Removendo Coluna\n");
    removeColumn(matrix, 20);
    printMatrix(matrix);
    printf("\n\n");

    printf("Criando matriz 2\n");
    Matrix *matrix2 = createMatrix(matrix->rows, matrix->columns);
    allocateMatrixElements(matrix2);
    for (int i = 0; i < matrix2->rows; i++) {
        for (int j = 0; j < matrix2->columns; j++) {
            insertValue(matrix2, i+1, j+1, 2);
        }
    }
    printMatrix(matrix2);
    printf("\n\n");

    printf("Somando matrizes 1 e 2\n");
    Matrix *result = createMatrix(matrix2->rows, matrix2->columns);
    sumMatrix(matrix, matrix2, &result);
    printMatrix(result);


    freeMatrix(matrix);
    freeMatrix(matrix2);
    freeMatrix(result);

    return 0;
}
