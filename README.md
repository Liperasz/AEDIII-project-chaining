Matrix* createMatrix(int row, int col):

  Essa função serve para criar a matriz, o que ela faz é alocar a matriz e definir a quantidade de linhas e colunas que ela tem/terá.

void freeMatrix(Matrix *matrix):

  Essa função serve para liberar a matriz, pegando eliminando cada linha uma de cada vez até liberar a matriz em si. 
  
void printMatrix(Matrix *matrix):

  Mostra a matriz no terminal, percorre da mesma forma que o freeMatrix, indo linha por linha.

int createElement(Matrix *matrix, int row, int col):

  Serve para criar um novo elemento dada sua posição.
  A função createElement foi criada numa tentativa de facilitar as outras funções de adição de elementos, como a função de 
alocar matriz, a função de adicionar coluna e a função de adicionar linha. Porém, devido a complexidade na hora de criar
essa função, a ideia original ficou de lado, e atualmente ela serve apenas para a função de alocar a matriz. Qualquer
outra tentativa de uso com ela dará errado. No total, foram quase 9 horas tentando cobrir todas as possibilidades para que 
a função createElement desse certo, mas não foi possível e desistimos.
  
int allocateMatrixElements(Matrix *matrix):

  A função aloca os elementos da matriz, conforme informado na própria matriz, com a quantidade de linhas e colunas.
Ela utiliza da função createElement e é a única função que a utiliza sem problemas.

// Funções extras parte 1
int addRow(Matrix *matrix, int row):

  A função serve para criar uma nova linha em qualquer posição da matriz.
  A função basicamente é dividida em três possibilidades, verifica se você quer adicionar como nova primeiro linha,
se quer adicionar no meio da matriz, ou se quer adicionar no final. Para adicionar no primeiro, basta passar o valor 1,
para o meio, passa bastar em qual posição você deseja que a nova linha fique, e ela empurrará a linha atual para baixo.
Para colocar no final, basta passar qualquer número que seja maior que a quantidade atual de linhas.
  Em conjunto com o createElement, essa foi a maior dificuldade do projeto, após muita tentativa de deixar um código
simples utilizando no createElement, prefirimos deixar o código robusto mas 100% funcional.

int addColumn(Matrix *matrix, int col);

  Serve para adicionar uma nova coluna em qualquer posição da matriz.
  Funciona exatamente da mesma forma que addRow, apenas com as modificações necessárias para passar para o próximo elemento.

int removeRow(Matrix *matrix, int row):

  Serve para remover qualquer linha da matriz.
  De forma semelhante a addRow, ele verifica caso seja a primeira linha, se é uma linha do meio, ou se é a última linha, e age
com base nisso, alterando os ponteiros e liberando os elementos.
  Para remover a ultima linha, basta passar qualquer valor maior que a quantidade atual de linhas.

int removeColumn(Matrix *matrix, int col);

  Serve para remover qualquer coluna da matriz.
  Funciona da mesma forma que removeRow.

// Funções extras parte 2
int sumMatrix(Matrix *matrix1, Matrix *matrix2, Matrix **result):

  Passado como parâmetro três matrizes, ele faz a soma da matriz A + Matriz B, e o resultado saí na matriz C.
  A função verifica se a quantidade de elementos entre as matrizes são iguais através de matrix->columns e matrix->rows.
Caso for igual, então a função verifica se a matriz C já existe, se existir, ela é eliminada e uma nova é criada. O 
objetivo é que a matriz C tem que possuir a mesma quantidade de elementos que a Matriz A e a Matriz B. Após esse processo,
a função percorre linha por linha atribuindo os valores das somas na matriz C.

// Funções pedidas na instrução do projeto
int insertValue(Matrix *matrix, int row, int col, int value):

  A função insertValue serve para inserir o valor em uma posição escolhida.
  A função acha o elemento que está na posição desejada e aplica o valor que foi passado como parâmetro.
  
int consultValuePosition(Matrix *matrix, Element **element, int row, int col):

  A função consulta o valor presente em uma posição específica.
  A função primeiro acha a linha e depois a coluna do elemento, e então coloca o valor encontrado na posição em um ponteiro
que é passado como parâmetro.

int consultValue(Matrix *matrix, Element **element, int value):

  A função serve para consultar o elemento onde um valor está presente.
  A função percorre a matriz em busca de um valor específico, ao encontrar o valor, o ponteiro passado como parâmetro
passa a apontar para o elemento onde o valor está presente. Caso o valor não esteja na matriz, o ponteiro aponta para NULL.

int printNeighbours(Matrix *matrix, int row, int col):

  A função serve para mostrar na tela os elementos vizinhos a um elemento de uma posição específica.
  A função percorre até a posição e mostra os elementos vizinhos, caso não existam, mostra que o vizinho é NULL.

// Essa troca não muda a posição real dos nós na estrutura de ponteiros, apenas os valores armazenados ( FUNÇÂO EXTRA)
int swapElements(Matrix *matrix, int row1, int col1, int row2, int col2);
