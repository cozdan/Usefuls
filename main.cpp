/*
��������� ���� ����� ��� � �� ����� ���������� ��� ��. � ��� ������� �� �������� ��������� � ���
��� ����������� � ��������� �������.
*/
#include <iostream>
#include <set>
#include <vector>

using namespace std;


// ������������ ��������� ������ MakeVector �� �������� � �������� MakeSet �� �����



uint64_t Factorial(int num) {
    int factorial = 1;
    cout << "������� ����� = "s << num << endl;
    if (num != 0) {
        factorial = Factorial(num - 1) * num;
    }
    cout << "�������� ���������� "s << factorial << "��� ����� "s << num << endl;
    return factorial;
}
int main() {
    Factorial(4);
}