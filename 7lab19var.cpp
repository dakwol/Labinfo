#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 5
int Me(int A[][N])//функция ввода матрицы с клавиатуры
{
   int i,j;
   for (j=0;j<N;j++)
      for (i=0;i<N;i++)
        scanf("%d" , &A[i][j]);
}

int file(int A[][N])//функция чтения матрицы из файла
{
   int i, j; FILE* f;
   f = fopen("in.txt", "r");//открытие файла для чтения
   if (f != NULL)//проверка открытия файла
      for (i = 0; i<N; i++)//считывание матрицы из файла
         for (j = 0; j<N; j++)
         fscanf(f, "%d", &A[i][j]);
   else printf("Входной файл отсутствует");
   fclose(f);//закрытие файла
}
int rec(int Y,int p,int A[][N], int stepi)//определяем Y
{
    if (stepi < 4)
    {
      if (A[0][stepi] % 2 != 0)p++;
          if(p!=0 && A[0][stepi] % 2 == 0)
          {
            Y+= A[0][stepi] ; rec(Y,p,A, stepi + 1);
          }
      else rec(Y,p,A, stepi + 1);
    }
    else return Y;
}
int output(int A[][N], int X[])//функция вывода матрицы на экран и в файл(вместе с X и Y)
{
   FILE* f; int Y =0;
   for (int i = 0; i<N; i++)//вывод матрицы на экран
    {
        for (int j = 0; j< N; j++)
        printf("%3d", A[i][j]);
        printf("\n");
    }
   for (int i = 0; i< N; i++)//вывод X и Y на экран
   printf("\nx[%d]=%d", i+1, X[i]);
   printf("\nY = %d", rec(0,0,A, 0));
   f = fopen("out.txt", "w");//открытие файла для записи
   if (f != NULL)//Проверка открытия файла
    {
       for (int i = 0; i< N; i++)//запись в файл матрицы
        {
          for (int j = 0; j< N; j++)
              fprintf(f, "%3d", A[i][j]);
              fprintf(f, "\n");
       }
       for (int i = 0; i < N; i++)//запись в файл X и Y
           fprintf(f, "\nx[%d]=%d", i+1, X[i]);
           fprintf(f, "\nY = %d", rec(0,0,A, 0));
    }
    else printf("Ошибка открытия файла");
}
int *MainCalculation(int A[][5],int (*yka)(int[][N] ),int X[])
{
        int min,Check=false;
        int j,i,t; (*yka)(A);
	    min=A[0][0];// Поиск минимального элемента в матрице
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
            printf("Минимальный элемент матрицы: %d\n",min);
            for (i = 0; i < N; i++)//нахождение минимального элемента в строках
               {
                    for (j = 0; j < N; j++)
                       {
                          if (A[i][j]==min)//если найденный элемент в строке равен минимальному в матрице, то присваиваем значение истина
                          {
                            Check=true;
                          }
                       }

                    if (Check)//если значение истино, записываем 1, в противном случае -1
                    {
                      X[i]=1;
                    }
                   else
                    {
                      X[i]=-1;
                    }
                  Check=false;
               }
             return X;//возвращаем X
    }
int main()
{
    char* locale = setlocale(LC_ALL,"");
    int A[N][N], X[N], k; int *Sp;
    int (*yka)(int[][N]) = NULL;
    printf("Укажите какой ввод матрицы\nC клавиатуры - введите 1\nC файла - введите 0\n");
    printf("Ваш выбор - "); scanf("%d", &k);
    if (k == 1) yka = Me;
    else yka = file;
    Sp = MainCalculation(A,yka, X);
    output(A, Sp);
}
