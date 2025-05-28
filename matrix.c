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

int removeElement(Matrix *matrix, int row, int col) {

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


    if (element->above != NULL) {
        element->above->below = element->below;
    }
    if (element->below != NULL) {
        element->below->above = element->above;
    }
    if (element->left != NULL) {
        element->left->right = element->right;
    }
    if (element->right != NULL) {
        element->right->left = element->left;
    }

    free(element);

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

    if (matrix == NULL) {
        return 0;
    }

    if (matrix->rows + 1 < row) {
        return 0;
    }

    matrix->rows += 1;
    for (int i = 0; i < matrix->columns; i++) {


        //Falta atualização do createElement()

        // createElement(matrix, row, i + 1);

        //-------------------------------------------------------------------------------


    }

    return 1;
}

int addColumn(Matrix *matrix, int col) {

    if (matrix == NULL) {
        return 0;
    }

    if (matrix->rows + 1 < col) {
        return 0;
    }

    matrix->columns += 1;
    for (int i = 0; i < matrix->rows; i++) {


        //Falta atualização do createElement()

        // createElement(matrix, row, i + 1);

        //-------------------------------------------------------------------------------


    }

    return 1;
}

int removeRow(Matrix *matrix, int row) {

    if (matrix == NULL || matrix->first == NULL) {
        return 0;
    }

    Element *element = matrix->first;
    for (int i = 1; i < row; i++) {
        element = element->below;
    }

    if (element == NULL) {
        return 0;
    }

    int col = 1;
    while (element != NULL) {
        Element *aux = element;
        element = element->right;

        //Falta atualização do removeElement()

        // removeElement(matrix, row, col);

        //-------------------------------------------------------------------------------

        col++;
    }

    matrix->rows--;

    return 1;

}

int removeColumn(Matrix *matrix, int col) {

    if (matrix == NULL || matrix->first == NULL) {
        return 0;
    }

    Element *element = matrix->first;
    for (int i = 1; i < col; i++) {
        element = element->right;
    }

    if (element == NULL) {
        return 0;
    }

    int row = 1;
    while (element != NULL) {
        Element *aux = element;
        element = element->below;


        //Falta atualização do removeElement()

        // removeElement(matrix, row, col);

        //-------------------------------------------------------------------------------


        row++;
    }

    matrix->columns--;

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