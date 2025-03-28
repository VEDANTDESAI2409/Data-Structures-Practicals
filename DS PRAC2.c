//AIM : Implementation of Array applications of Sparse Matrices.
#include <stdio.h>
#define MAX 10
// Structure for storing sparse matrix elements
typedef struct {
 int row, col, value;
} Sparse;
void printSparse(Sparse sp[], int size) {
 printf("\nRow Col Value\n");
 for (int i = 0; i < size; i++)
 printf("%d %d %d\n", sp[i].row, sp[i].col, sp[i].value);
}
int main() {
 int mat[MAX][MAX], rows, cols, count = 0;
 Sparse sp[MAX];
 printf("Enter rows and cols: ");
 scanf("%d %d", &rows, &cols);
 printf("Enter matrix:\n");
 for (int i = 0; i < rows; i++)
 for (int j = 0; j < cols; j++) {
 scanf("%d", &mat[i][j]);
 if (mat[i][j] != 0) {
 sp[count++] = (Sparse){i, j, mat[i][j]};
 }
 }
 printSparse(sp, count);
 return 0;
}
