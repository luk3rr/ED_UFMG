#include <stdlib.h>

struct Matrix {
  int rows, cols;
  int **data;
};

int main() {
  int i;

  // Inicializar o ponteiro com valor nulo
  struct Matrix *rotation3D = 0;

  // Aloca o espaço para o ponteiro
  rotation3D = (struct Matrix*) malloc(sizeof(struct Matrix));

  // Atribui valores aos atributos
  rotation3D->rows = 4;
  rotation3D->cols = 4;

  // Aloca espaço para o ponteiro bidimensional 'data'
  rotation3D->data = (int **)malloc(sizeof(int *) * rotation3D->rows);

  // Para cada posição em row, aloca um espaço para armazenar um ponteiro para o tipo inteiro de 4 * 4 bytes
  for (i = 0; i < rotation3D->rows; i++)
    rotation3D->data[i] = (int *)malloc(sizeof(int) * rotation3D->cols);

  // Para cada posição em row, libera o espaço alocado
  for (i = 0;i < rotation3D->rows; i++)
    free(rotation3D->data[i]);

  // Libera o espaço alocado para armazenar os dados da struct
  free(rotation3D->data);

  // Libera o espaço alocado para armazenar a struct
  free(rotation3D);
  return 0;
}
