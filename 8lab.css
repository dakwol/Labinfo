#include <iostream>
using namespace std;
int power(int x, int n)
{
  if (n == 0) return 1;
  return x * power(x, n - 1);
}
int main()
{
  unsigned int c, x, max, min, k, mask;
  mask = 15;
  cout<<"Введите число:"<<"\n";
  cin>> x;
  min = max = x & mask;
  k = 8;
  while ((x & (power(16, k - 1) * 15)) == 0)
    k--;
    for (int i = 0; i < k; i++)
       {
        if ((x >> i * 4 & mask) > max)
        max = x >> i * 4 & mask;
           if ((x >> i * 4 & mask) < min)
           min = x >> i * 4 & mask;
       }
   x = x << (8 - k + 1) * 4 >> (8 - k ) * 4 | max << k * 4;
   x = x >> 8 << 4 | min;
   cout<<"В шестнадцетиричном:\n";
   printf("Минимальное=%x\nМаксимальное=%x\nПреобразованное число=%x\n", min, max, x);
}
