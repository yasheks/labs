#include <iostream>
#include <clocale>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

void arr(int **d2, int N, int M)
{
    for (int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("d2[%d][%d] = ", i, j);
            scanf("%d", &d2[i][j]);
        }
    }
}

void del(int **arr1, int **arr2, int **A, int N1, int N2){
	for (int i = 0; i < N1; i++)
		{
			delete[] arr1[i];
		}
		delete [] arr1;

	for (int i = 0; i < N1; i++)
		{
			delete[] arr2[i];
		}
		delete [] arr2;

	for (int i = 0; i < N1; i++)
		{
			delete[] A[i];
		}
	delete [] A;
}

void fop(FILE *f)
{
	if (f==NULL)
	{
		printf("\nError\n");
		exit(1);
	}
}

void matr1(int ***arr1, int N1, int M1, FILE *f)
{
	*arr1 = new int *[N1];
	for (int i = 0; i < N1; i++)
	{
		(*arr1)[i] = new int [M1];
	}
	
	for (int i = 0; i < N1; i++)
	{
		for (int j = 0; j < M1; j++)
		{
			fscanf(f, "%d", &(*arr1)[i][j]);
		}
	}
}

void matr2(int ***arr2, int N2, int M2, FILE *f)
{
	*arr2 = new int *[N2];
	for (int i = 0; i < N2; i++)
	{
		(*arr2)[i] = new int [M2];
	}
	
	for (int i = 0; i < N2; i++)
	{
		for (int j = 0; j < M2; j++)
		{
			fscanf(f, "%d", &(*arr2)[i][j]);
		}
	}
}

void rav(int M1, int N2)
{
	if (M1 != N2)
	{
		//fprintf(f, "\nError\n");
		printf("\nError\n");

		exit(1);
	}
}

void matrA(int ***A, int N1, int M2)
{
	*A = new int* [N1];
	for (int i = 0; i < N1; i++)
	{
		(*A)[i] = new int [M2];
		for (int j = 0; j < M2; j++)
		{
			(*A)[i][j] = 0;
		}
	}
}

void prA(FILE *f, int N1, int M2, int **A)
{
	fprintf(f, "\nРезультат произведения матриц:\n");
	for (int i = 0; i < N1; i++){
        for (int j = 0; j < M2; j++){
            fprintf(f, "%d\t ", A[i][j]);
        }
	}
    fprintf(f, "\n");
}

void mult(int **arr1, int **arr2, int **A, int N1, int M2, int M1)
{
	for (int i = 0; i < N1; i++)
	{
		for (int j = 0; j < M2; j++)
		{
			A[i][j] = 0;
			for (int k = 0; k < M1; k++)
			{
				A[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
}

int main(int argc, char** argv) {
	setlocale(LC_CTYPE, " ");
	
	int N1, M1, N2, M2;
	int **arr1;
	int **arr2;
	int **A;
	
	FILE *f;
	f = fopen("file1.txt", "r");
	
	fop(f);

	fscanf(f, "%d %d", &N1, &M1);
	matr1(&arr1, N1, M1, f);

	
	fscanf(f, "%d %d", &N2, &M2);
	matr2(&arr2, N2, M2, f);

	fclose(f);

	rav(M1, N2);

	matrA(&A, N1, M2);
	
	mult(arr1, arr2, A, N1, M2, M1);
	
	f = fopen ("file1.txt", "a");
	
	fop(f);
	
	prA(f, N1, M2, A);
	
	fclose(f);

	del(arr1, arr2, A, N1, N2);
}


