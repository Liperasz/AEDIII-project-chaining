# Matriz  - Documentação

Esse é um projeto para a disciplin de Algoritmos e Estruturas de Dados III com o tema de encadeamento de uma matriz.

## Funções Básicas de Matriz

### `Matrix* createMatrix(int row, int col)`
Aloca e inicializa uma matriz com o número especificado de linhas e colunas.

### `void freeMatrix(Matrix *matrix)`
Libera toda a memória alocada para a matriz, incluindo todas as linhas e elementos.

### `void printMatrix(Matrix *matrix)`
Exibe a matriz no terminal, percorrendo e imprimindo cada elemento linha por linha.

### `int createElement(Matrix *matrix, int row, int col)`
Cria um novo elemento na posição especificada. Atualmente, esta função é usada apenas internamente pela `allocateMatrixElements`. Tentativas de uso em outros contextos podem não funcionar como esperado.

*Observação:* Esta função foi desenvolvida para simplificar outras operações, mas devido à complexidade de implementação, seu escopo foi limitado.

### `int allocateMatrixElements(Matrix *matrix)`
Aloca todos os elementos da matriz com base nas dimensões (linhas/colunas) especificadas. Esta é a única função que utiliza `createElement` corretamente.

## Funções de Modificação de Estrutura (Parte 1)

### `int addRow(Matrix *matrix, int row)`
Adiciona uma nova linha na posição especificada:
- `row = 1`: insere como primeira linha
- `1 < row <= matrix->rows`: insere no meio, empurrando as linhas existentes
- `row > matrix->rows`: adiciona no final

### `int addColumn(Matrix *matrix, int col)`
Adiciona uma nova coluna na posição especificada, funcionando de forma análoga à `addRow`.

### `int removeRow(Matrix *matrix, int row)`
Remove uma linha da matriz:
- `row = 1`: remove a primeira linha
- `1 < row <= matrix->rows`: remove uma linha do meio
- `row > matrix->rows`: remove a última linha

### `int removeColumn(Matrix *matrix, int col)`
Remove uma coluna da matriz, funcionando de forma similar à `removeRow`.

## Operações com Matrizes (Parte 2)

### `int sumMatrix(Matrix *matrix1, Matrix *matrix2, Matrix **result)`
Realiza a soma de duas matrizes (matrix1 + matrix2) e armazena o resultado em `result`:
1. Verifica se as dimensões das matrizes são compatíveis
2. Se a matriz resultante já existir, ela é liberada
3. Cria uma nova matriz com as dimensões adequadas
4. Armazena a soma dos elementos correspondentes

## Funções Principais (Requisitadas)

### `int insertValue(Matrix *matrix, int row, int col, int value)`
Insere um valor na posição (row, col) especificada da matriz.

### `int consultValuePosition(Matrix *matrix, Element **element, int row, int col)`
Consulta o valor em uma posição específica, armazenando o elemento encontrado no ponteiro fornecido.

### `int consultValue(Matrix *matrix, Element **element, int value)`
Busca um valor na matriz. Se encontrado, o ponteiro `element` aponta para sua localização; caso contrário, aponta para NULL.

### `int printNeighbours(Matrix *matrix, int row, int col)`
Exibe os vizinhos (superior, inferior, esquerdo, direito) do elemento na posição especificada. Vizinhos inexistentes são mostrados como NULL.

## Função Extra

### `int swapElements(Matrix *matrix, int row1, int col1, int row2, int col2)`
Troca os valores entre dois elementos da matriz. Observação: Esta operação não altera a estrutura de ponteiros, apenas os valores armazenados.


## Dificuldades e Desafios do Projeto

Principais desafios do projeto:

### 1. Implementação da `createElement`
- A função foi concebida como uma solução genérica para criação de elementos, visando simplificar outras operações como alocação de matriz, adição de linhas e colunas
- Encontramos complexidades inesperadas na manipulação dos ponteiros em diferentes contextos
- Dedicação: aproximadamente 9 horas de tentativas para cobrir todos os casos de uso
- Solução adotada: limitamos seu escopo para uso exclusivo pela `allocateMatrixElements`

### 2. Operações `addRow` e `addColumn`
- A principal dificuldade foi desenvolver uma lógica única que cobrisse três cenários distintos:
  - Inserção no início da matriz
  - Inserção no meio da estrutura
  - Inserção no final
- Originalmente planejávamos utilizar `createElement` para simplificar o código
- Solução final: implementação de código mais robusto, com tratamentos específicos para cada caso

### 3. Gerenciamento de Memória
- Desafio constante na manipulação dinâmica da estrutura encadeada
- Necessidade de garantir que todas as alocações fossem corretamente liberadas
- Dificuldade especial nas operações de remoção de linhas/colunas
