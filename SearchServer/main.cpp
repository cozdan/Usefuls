#include <string>
#include <iostream>
#include <algorithm>


using namespace std;

void PrintSpacesPositions(string& str) {
    // напишите реализацию
    for (auto i = find(str.begin(), str.end(), ' '); i == str.end(); next(find(i + 1, str.end(), ' '))) {
        cout << distance(begin(str), i) << endl;
    }

    // cout << *(find(str.begin(), str.end(), ' ');
     //string space = " "s;
     //while(find(str.begin(), str.end(), ' ') != str.end()){
    //     cout << find(str.begin(), str.end(), ' ');
     //
}

int main() {
    string str = "He said: one and one and one is three"s;
    PrintSpacesPositions(str);
    return 0;
}