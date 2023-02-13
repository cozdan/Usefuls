/*
Заготовки кода здесь нет — вы легко справитесь без неё. А вот решение не забудьте сохранить — оно
вам понадобится в следующем задании.
*/
#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <typename It>
void PrintRange(It range_begin, It range_end) {
    bool is_first = 1;
    for (auto it = range_begin; it != range_end; ++it) {
        cout << *it << " ";
    }
    cout << endl;

}

int main() {
    cout << "Test1"s << endl;
    set<int> test1 = { 1, 1, 1, 2, 3, 4, 5, 5 };
    PrintRange(test1.begin(), test1.end());
    cout << "Test2"s << endl;
    vector<int> test2 = {}; // пустой контейнер
    PrintRange(test2.begin(), test2.end());
    cout << "End of tests"s << endl;
}