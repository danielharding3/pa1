#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
	
	int matrix1[1000][1000];
	int matrix2[1000][1000];
	//int result[][];
	int row1;
	int row2;
	int col1;
	int col2;
	int i;
	int j;
	int k;
	int number = 0;
	int x;
	int y;
	
	FILE *fptr;
	fptr = fopen(argv[1], "r");
	
	//first matrix
	fscanf(fptr, "%d\t%d", &row1, &col1);
	x = row1;
	//fscanf(fptr, "%d", &row1);
	//fscanf(fptr, "%d", &col1);
	//matrix1 = (int **)malloc(row1 * col1*sizeof(int));
	for (i = 0; i < row1; i++) {
		for (j = 0; j < col1; j++) {
			fscanf(fptr, "%d", &matrix1[i][j]);
		}
		fscanf(fptr, "\n");
	}
	
	//second matrix
	fscanf(fptr, "%d\t%d", &row2, &col2);
	y = col2;
	
	//fscanf(fptr, "%d", &row2);
	//fscanf(fptr, "%d", &col2);
	//matrix2 = (int **)malloc(row2 * col2*sizeof(int));
	
	
	for (i = 0; i < row2; i++) {
		for (j = 0; j < col2; j++) {
			fscanf(fptr, "%d", &matrix2[i][j]);
		}
		fscanf(fptr, "\n");
	}
	
	if (col1 != row2) {
		printf("bad-matrices");
		return 0;
	}
	//result = (int **)malloc(row1 * col2*sizeof(int));
	int result[x][y];
	for (i = 0; i < row1; i++) {
		for (j = 0; j < col2; j++) {
			result[i][j] = 0;
		}
	}
	
	for (i = 0; i < row1; i++) {
		for (j = 0; j < col2; j++) {
			for (k = 0; k < row2; k++) {
				number = number + matrix1[i][k] * matrix2[k][j];
			}
			result[i][j] = number;
			number = 0;
		}
	}
	
	for (i = 0; i < row1; i++) {
		for (j = 0; j < col2; j++) {
			printf("%d\t", result[i][j]);
		}
		printf("\n");
	}
	
	
	//free(mat1);
	//free(mat2);
	//free(result);
	fclose(fptr);
	return 0;
}

