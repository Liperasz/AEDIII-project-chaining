//
// Created by liperasz on 27/05/2025.
//

#ifndef MATRIX_H
#define MATRIX_H

typedef struct element {

    struct element *above;
    struct element *below;
    struct element *right;
    struct element *left;
    int data;

} Element;

typedef struct {

    Element *first;
    int columns;
    int rows;

} Matrix;

Matrix* createMatrix(int row, int col);
void freeMatrix(Matrix *matrix);
void printMatrix(Matrix *matrix);

// A função createElement só funciona com o allocateMatrix, nem tenta usar de outra forma que não vai funcionar
int createElement(Matrix *matrix, int row, int col);
int allocateMatrixElements(Matrix *matrix);

// Funções extras parte 1
int addRow(Matrix *matrix, int row);
int addColumn(Matrix *matrix, int col);
int removeRow(Matrix *matrix, int row);
int removeColumn(Matrix *matrix, int col);

// Funções extras parte 2
int sumMatrix(Matrix *matrix1, Matrix *matrix2, Matrix **result);

// Funções pedidas na instrução do projeto
int insertValue(Matrix *matrix, int row, int col, int value);
int consultValuePosition(Matrix *matrix, Element **element, int row, int col);
int consultValue(Matrix *matrix, Element **element, int value);
int printNeighbours(Matrix *matrix, int row, int col);

// Essa troca não muda a posição real dos nós na estrutura de ponteiros, apenas os valores armazenados ( FUNÇÂO EXTRA)
int swapElements(Matrix *matrix, int row1, int col1, int row2, int col2);

#endif //MATRIX_H
