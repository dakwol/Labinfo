#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 5
int Me(int A[][N])
    {
        int i,j;
        for (j=0;j<N;j++)
            for (i=0;i<N;i++)
                scanf("%d" , &A[i][j]);
    }
int file(int A[][N])
    {
        int i, j; FILE* f;
        f = fopen("in", "r");
        if (f != NULL)
            for (j = 0; j<N; j++)
                for (i = 0; i<N; i++)
                    fscanf(f, "%d", &A[i][j]);
        else printf("Входной файл отсутствует");
        fclose(f);
    }
int rec(int X[], int stepi)
    {
        if (stepi< 4)
            if (X[stepi] % 2 != 0)
                return X[stepi] * rec(X, stepi + 1);
            else return 1;
        else return 1;
    }
int output(int A[][N], int X[])
    {
        FILE* f; int Y =0;
        for (int j = 0; j<N; j++)
            {
                for (int i = 0; i< N; i++)
                printf("%3d", A[i][j]);
                printf("\n");
            }
            for (int i = 0; i< N; i++)
            printf("\nx[%d]=%d", i+1, X[i]);
            printf("\nY = %d", rec(X, 0));
            f = fopen("out", "w");
            if (f != NULL)
                {
                    for (int i = 0; i< N; i++)
                        {
                            for (int j = 0; j< N; j++)
                                fprintf(f, "%3d", A[j][i]);
                            fprintf(f, "\n");
                        }
                    for (int i = 0; i < N; i++)
                        fprintf(f, "\nx[%d]=%d", i+1, X[i]);
                    fprintf(f, "\nY = %d", rec(X, 0));
                }
            else printf("Ошибка открытия файла");
    }
int *MainCalculation(int A[][5],int (*yka)(int[][N] ),int X[])
    {
        int min,Check=false;
        int j,i,t; (*yka)(A);
        // Поиск минимального элемента
	    min=A[0][0];
        for(i=0;i<N;i++)
            {
                for(j=0;j<N;j++)
                {
			       if (A[i][j]<min)
			         {
			        	min=A[i][j];
			         }
		        }
            }
            printf("минимальный эл.%d\n",min);
            for (i = 0; i < 5; i++)
               {
                    for (j = 0; j < 5; j++)
                       {
                          if (A[i][j]==min)
                          {
                            Check=true;
                          }
                       }
                    if (Check)
                    {
                      X[i]=1;
                    }
                   else
                    {
                      X[i]=-1;
                    }
                  Check=false;
               }
    }
int main()
    {
        char* locale = setlocale(LC_ALL,"");
        int A[N][N], X[N], k; int *Xpointer;
        int (*yka)(int[][N]) = NULL;
        printf("Укажите какой ввод матрицы\nC клавиатуры - введите 1\nC файла - 0\n");
        printf("Ваш выбор - "); scanf("%d", &k);
        if (k == 1) yka = Me;
        else yka = file;
        Xpointer = MainCalculation(A,yka, X);
        output(A, Xpointer);
    }
