//
// Created by liperasz on 27/05/2025.
//

#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

Matrix* createMatrix(int row, int col) {

    Matrix* matrix = (Matrix*) malloc(sizeof(Matrix));
    if (matrix != NULL) {

        matrix->columns = col;
        matrix->rows = row;
        matrix->first = NULL;
    }

    return matrix;

}

void freeMatrix(Matrix *matrix) {

    if (matrix != NULL) {
        Element *aux = matrix->first;
        while (aux != NULL) {
            Element *aux2 = aux;
            aux = aux->below;
            while (aux2 != NULL) {
                Element *aux3 = aux2;
                aux2 = aux2->right;
                free(aux3);
            }
        }
        free(matrix);
    }

}


void printMatrix(Matrix *matrix) {

    if (matrix != NULL && matrix->first != NULL) {
        Element *aux = matrix->first;
        printf("--------------------------------\n");
        while (aux != NULL) {
            Element *aux2 = aux;
            printf("|");
            while (aux2 != NULL) {
                printf(" %d |", aux2->data );
                aux2 = aux2->right;
            }
            printf("\n");
            printf("--------------------------------\n");
            aux = aux->below;
        }
    }
}

int createElement(Matrix *matrix, int row, int col) {

    if (matrix == NULL || row > matrix->rows || col > matrix->columns || row < 1 || col < 1) {
        printf("Invalid input\n");
        return 0;
    }

    Element *element = (Element*) malloc(sizeof(Element));
    if (element == NULL) {
        printf("Error in alocating element\n");
        return 0;
    }

    if (row == 1) {
        element->above = NULL;
    } else {
        Element* aux = matrix->first;
        for (int i = 1; i < row- 1; i++) {
            aux = aux->below;
        }
        for (int i = 1; i < col; i++) {
            aux = aux->right;
        }
        aux->below = element;
        element->above = aux;
    }

    element->below = NULL;

    if (col == 1) {
        element->left = NULL;
    } else {
        Element* aux = matrix->first;
        for (int i = 1; i < col - 1; i++) {
            aux = aux->right;
        }
        for (int i = 1; i < row; i++) {
            aux = aux->below;
        }
        aux->right = element;
        element->left = aux;
    }

    element->right = NULL;

    if (row == 1 && col == 1) {
        matrix->first = element;
    }

    return 1;
}


int allocateMatrixElements(Matrix *matrix) {

    if (matrix == NULL) {
        return 0;
    }

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {

            createElement(matrix, i + 1, j + 1);

        }
    }

    return 1;

}

int addRow(Matrix *matrix, int row) {


    if (matrix == NULL || matrix->first == NULL || row < 1) {
        return 0;
    }


    if (row > matrix->rows) {
        row = matrix->rows + 1;
    }

    Element *aux = matrix->first;

    if (row == 1) {

        for (int i = 0; i < matrix->columns; i++) {

            Element *element = (Element*) malloc(sizeof(Element));
            element->below = NULL;
            element->left = NULL;
            element->right = NULL;
            element->above = NULL;

            if (i == 0) {
                matrix->first = element;
            }
            aux->above = element;
            element->below = aux;

            if (i > 0) {
                element->left = aux->left->above;
                aux->left->above->right = element;
            }

            aux = aux->right;

        }

    }

    if (row > 1 && row <= matrix->rows) {

        for (int i = 0; i < row - 1; i++) {
            aux = aux->below;
        }

        for (int i = 0; i < matrix->columns; i++) {

            Element *element = (Element*) malloc(sizeof(Element));
            element->below = aux;
            element->left = NULL;
            element->right = NULL;
            element->above = aux->above;
            element->above->below = element;
            aux->above = element;

            if (i > 0) {
                element->left = aux->left->above;
                aux->left->above->right = element;
            }

            aux = aux->right;

        }

    }

    if (row == matrix->rows + 1) {

        for (int i = 1; i < matrix->rows; i++) {
            aux = aux->below;
        }

        for (int i = 0; i < matrix->columns; i++) {
            Element *element = (Element*) malloc(sizeof(Element));
            element->below = NULL;
            element->left = NULL;
            element->right = NULL;
            element->above = aux;

            aux->below = element;


            if (i > 0) {

                element->left = aux->left->below;
                aux->left->below->right = element;

            }

            aux = aux->right;

        }
    }


    matrix->rows += 1;
    return 1;
}

int addColumn(Matrix *matrix, int col) {

    if (matrix == NULL || matrix->first == NULL || col < 1) {
        return 0;
    }

    if (col > matrix->columns) {
        col = matrix->columns + 1;
    }

    Element *aux = matrix->first;

    if (col == 1) {

        for (int i = 0; i < matrix->rows; i++) {

            Element *element = (Element*) malloc(sizeof(Element));
            element->right = NULL;
            element->left = NULL;
            element->above = NULL;
            element->below = NULL;

            if (i == 0) {
                matrix->first = element;
            }

            aux->left = element;
            element->right = aux;

            if (i > 0) {
                element->above = aux->above->left;
                aux->above->left->below = element;
            }

            aux = aux->below;
        }
    }

    if (col > 1 && col <= matrix->columns) {

        for (int i = 0; i < col - 1; i++) {
            aux = aux->right;
        }

        for (int i = 0; i < matrix->rows; i++) {

            Element *element = (Element*) malloc(sizeof(Element));
            element->right = aux;
            element->left = aux->left;
            element->above = NULL;
            element->below = NULL;

            element->left->right = element;
            aux->left = element;

            if (i > 0) {
                element->above = aux->above->left;
                aux->above->left->below = element;
            }

            aux = aux->below;
        }
    }

    if (col == matrix->columns + 1) {

        for (int i = 1; i < matrix->columns; i++) {
            aux = aux->right;
        }

        for (int i = 0; i < matrix->rows; i++) {

            Element *element = (Element*) malloc(sizeof(Element));
            element->right = NULL;
            element->left = aux;
            element->above = NULL;
            element->below = NULL;

            aux->right = element;

            if (i > 0) {
                element->above = aux->above->right;
                aux->above->right->below = element;
            }

            aux = aux->below;
        }
    }

    matrix->columns += 1;
    return 1;
}


int removeRow(Matrix *matrix, int row) {

    if (matrix == NULL || matrix->first == NULL || row < 1) {
        return 0;
    }

    if (row > matrix->rows) {
        row = matrix->rows;
    }

    Element *element = matrix->first;

    if (row == 1) {

        matrix->first = element->below;

        for (int i = 0; i < matrix->columns; i++) {

            Element *aux = element;
            element = element->right;

            aux->below->above = NULL;
            free(aux);

        }

    }

    if (row > 1 && row <= matrix->rows - 1) {

        for (int i = 0; i < row - 1; i++) {
            element = element->below;
        }

        for (int i = 0; i < matrix->columns; i++) {

            Element *aux = element;
            element = element->right;
            aux->below->above = aux->above;
            aux->above->below = aux->below;

            free(aux);

        }

    }

    if (row == matrix->rows) {

        for (int i = 0; i < row - 1; i++) {
            element = element->below;
        }

        for (int i = 0; i < matrix->columns; i++) {

            Element *aux = element;
            element = element->right;
            aux->above->below = NULL;

            free(aux);

        }

    }

    matrix->rows -= 1;
    return 1;

}

int removeColumn(Matrix *matrix, int col) {

    if (matrix == NULL || matrix->first == NULL || col < 1) {
        return 0;
    }

    if (col > matrix->columns) {
        col = matrix->columns;
    }

    Element *element = matrix->first;

    if (col == 1) {

        matrix->first = element->right;

        for (int i = 0; i < matrix->rows; i++) {

            Element *aux = element;
            element = element->below;

            aux->right->left = NULL;
            free(aux);

        }

    }

    if (col > 1 && col <= matrix->columns - 1) {

        for (int i = 0; i < col - 1; i++) {
            element = element->right;
        }

        for (int i = 0; i < matrix->rows; i++) {

            Element *aux = element;
            element = element->below;
            aux->right->left = aux->left;
            aux->left->right = aux->right;

            free(aux);

        }

    }

    if (col == matrix->columns) {

        for (int i = 0; i < col - 1; i++) {
            element = element->right;
        }

        for (int i = 0; i < matrix->rows; i++) {

            Element *aux = element;
            element = element->below;
            aux->left->right = NULL;

            free(aux);

        }

    }

    matrix->columns -= 1;
    return 1;
}


int insertValue(Matrix *matrix, int row, int col, int value) {

    if (matrix == NULL || matrix->first == NULL) {
        return 0;
    }

    if (row < 1 || col < 1 || row > matrix->rows || col > matrix->columns) {
        return 0;
    }

    Element *element = matrix->first;
    for (int i = 1; i < row; i++) {
        element = element->below;
    }
    for (int i = 1; i < col; i++) {
        element = element->right;
    }

    element->data = value;

    return 1;
}

int consultValuePosition(Matrix *matrix, Element **element, int row, int col) {

    if (matrix == NULL || matrix->first == NULL) {
        *element = NULL;
        return 0;
    }

    if (row < 1 || col < 1 || row > matrix->rows || col > matrix->columns) {
        *element = NULL;
        return 0;
    }

    *element = matrix->first;
    for (int i = 1; i < row; i++) {
        *element = (*element)->below;
    }
    for (int i = 1; i < col; i++) {
        *element = (*element)->right;
    }

    return 1;
}

int consultValue(Matrix *matrix, Element **element, int value) {

    if (matrix == NULL || matrix->first == NULL) {
        *element = NULL;
        return 0;
    }

    *element = matrix->first;
    while (*element != NULL) {
        Element *aux = *element;
        *element = (*element)->below;
        while (aux != NULL && aux->data != value) {
            aux = aux->right;
        }

        if (aux != NULL && aux->data == value) {
            *element = aux;
            return 1;
        }
    }

    *element = NULL;

    return 0;

}

int printNeighbours(Matrix *matrix, int row, int col) {

    if (matrix == NULL || matrix->first == NULL) {
        return 0;
    }

    if (row < 1 || col < 1 || row > matrix->rows || col > matrix->columns) {
        return 0;
    }

    Element *element = matrix->first;
    for (int i = 1; i < row; i++) {
        element = element->below;
    }
    for (int i = 1; i < col; i++) {
        element = element->right;
    }

    if (element == NULL) {
        return 0;
    }

    printf("\n\n--------------------------------\n");
    printf("Printing neighbors of element %d in position (%d, %d)\n\n", element->data, row, col);
    if (element->above != NULL) {
        printf("Neighbor above: %d\n", element->above->data);
    } else {
        printf("Neighbor above is NULL\n");
    }
    if (element->below != NULL) {
        printf("Neighbor below: %d\n", element->below->data);
    } else {
        printf("Neighbor below is NULL\n");
    }
    if (element->left != NULL) {
        printf("Neighbor on left: %d\n", element->left->data);
    } else {
        printf("Neighbor on left is NULL\n");
    }
    if (element->right != NULL) {
        printf("Neighbor on right: %d\n", element->right->data);
    } else {
        printf("Neighbor on right is NULL\n");
    }

    printf("--------------------------------\n\n");

    return 1;
}


    int swapElements(Matrix *matrix, int row1, int col1, int row2, int col2) {
        if (matrix == NULL || matrix->first == NULL) {
            return 0;
        }

        if (row1 < 1 || row1 > matrix->rows || col1 < 1 || col1 > matrix->columns ||
            row2 < 1 || row2 > matrix->rows || col2 < 1 || col2 > matrix->columns) {
            return 0;
            }

        Element *elem1 = matrix->first;
        Element *elem2 = matrix->first;

        for (int i = 1; i < row1; i++) {
            elem1 = elem1->below;
        }
        for (int j = 1; j < col1; j++) {
            elem1 = elem1->right;
        }

        for (int i = 1; i < row2; i++) {
            elem2 = elem2->below;
        }
        for (int j = 1; j < col2; j++) {
            elem2 = elem2->right;
        }

        if (elem1 == NULL || elem2 == NULL) {
            return 0;
        }

        int temp = elem1->data;
        elem1->data = elem2->data;
        elem2->data = temp;

        return 1;
    }

int sumMatrix(Matrix *matrix1, Matrix *matrix2, Matrix **result) {

    if (matrix1 == NULL || matrix2 == NULL || matrix1->first == NULL || matrix2->first == NULL) {
        return 0;
    }

    if (matrix1->rows != matrix2->rows || matrix1->columns != matrix2->columns) {
        return 0;
    }

    if (*result != NULL) {
        freeMatrix(*result);
    }

    *result = createMatrix(matrix1->rows, matrix1->columns);
    allocateMatrixElements(*result);

    Element *element1 = matrix1->first;
    Element *element2 = matrix2->first;
    Element *element3 = (*result)->first;

    for (int i = 0; i < matrix1->rows; i++) {

        Element *aux1 = element1;
        Element *aux2 = element2;
        Element *aux3 = element3;

        element1 = element1->below;
        element2 = element2->below;
        element3 = element3->below;

        for (int j = 0; j < matrix1->columns; j++) {

            aux3->data = aux1->data + aux2->data;

            aux1 = aux1->right;
            aux2 = aux2->right;
            aux3 = aux3->right;

        }

    }

    return 1;

}


