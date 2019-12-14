//Напишите функцию находящую корень монотонной вещественной функции f бинарным поиском(бисекцией). Можно считать что корень обязательно существует. Корнем будем считать значение x, такое что |f(x)|<10^(-6).  В комментариях напишите, почему решение- эффективное

#include <iostream>
using namespace std;
float f(float x) {
 return 2 * x + 3;
}

float root(float l, float r, float e1) {
 float c = (l + r) / 2;
 while (f(c) > e1) {
  if (f(c) * f(l) > 0) {
   l = c;
  }
  if (f(c) * f(r) > 0) {
   r = c;
  }
 }
 return c;
}

int main()
{
 float l, r, c, e;
 cin >> l, r;
 if (f(l) * f(r) > 0) {
  cout << "корней нет";
  return 0;
 }
 cout << root(l, r, e);
 return 0;
}
