/*
Заготовки кода здесь нет — вы легко справитесь без неё. А вот решение не забудьте сохранить — оно
вам понадобится в следующем задании.
*/
#include <iostream>
#include <set>
#include <vector>

using namespace std;


// разработайте сигнатуру фунции MakeVector по аналогии с функцией MakeSet из урока



uint64_t Factorial(int num) {
    int factorial = 1;
    cout << "Текущее число = "s << num << endl;
    if (num != 0) {
        factorial = Factorial(num - 1) * num;
    }
    cout << "Значение факториала "s << factorial << "для числа "s << num << endl;
    return factorial;
}
int main() {
    Factorial(4);
}