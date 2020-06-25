#include <iostream>
#include <ctime>
using namespace std;

int main()
{
int min,max,N;
int i,j;

int M ;
int** array;
cout << "Введите количество строк: ";//ввод размеров матрицы
cin >> M;
cout << "Введите количество столбцов: ";
cin >> N;

array = new int*[M];
    for ( i = 0; i < M; i++)
    array[i] = new int[N];

    for ( i = 0; i < M; i++) // ввод эллементов матрицы
    {
      for ( j = 0; j < N; j++)
        {
         cout << "[" << i << "][" << j << "]: ";
         cin >> array[i][j];
        }
     cout << endl;
    }

cout << "Введённый массив:\n";
for ( i = 0; i < M; i++) //вывод на экран матрицы после заполнения(первоначальный вид)
    {
     for ( j = 0; j < N; j++)
        {
         cout << array[i][j] << " ";
        }
    cout << endl;
    }
//Нахождение максимального и минимального эллементов
    for (int i = 0; i < N; i++)
        {
         for (int j = 0; j < N; j++)
            {
              if (j==0 || array[i][j]>max) max=array[i][j];
              if (j==0 || array[i][j]<min) min=array[i][j];
            }
         for (int j = 0; j < N; j++)//Перестановка элеменов местами
            {
              if (array[i][j]==max) array[i][j]=min;
              else if (array[i][j]==min) array[i][j]=max;
            }
       }
cout << "\nРезультирующий массив:\n";
for(i = 0; i<M; i++)
    {
     for(j = 0; j<N; j++)
        {
         cout << array[i][j] << " ";
        }
     cout << endl;
   }
delete [] array; // очистка памяти
return 0;
}
