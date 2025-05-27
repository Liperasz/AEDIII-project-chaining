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
int createElement(Matrix *matrix, int row, int col);
int allocateMatrixElements(Matrix *matrix);
int insertValue(Matrix *matrix, int row, int col, int value);
int consultValuePosition(Matrix *matrix, Element **element, int row, int col);
int consultValue(Matrix *matrix, Element **element, int value);
int printNeighbours(Matrix *matrix, int row, int col);


#endif //MATRIX_H
