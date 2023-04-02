#include <iostream>

using namespace std;

/*!
������� ��������� �������� ��������������� � �������
��������� �� ���� ������ ������� � ��������� �� ������
*/
int getAvg(const int size, int* values);
/*!
������� ��������� ������� �������
*/
int setSize();
/*!
������� ���������� �������
��������� �� ���� ������ ������� � ��������� �� ������
*/
int setArr(const int size, int* values);
/*!
������� ������ ������� �� �����
��������� �� ���� ������ ������� � ��������� �� ������
*/
int printArr(const int  size, int* values);



/*
������� �������
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    const int size = setSize();
    int* values = new int[size];
    setArr(size, values);      // ���������� �������
    cout << "������: \n";
    printArr(size, values);     // ����� ������� �� �����
    getAvg(size, values);
}

int setSize() {
    int size;
    cout << "������� ������ �������: \n";
    while (true)    // �������� �� ������������� ������ �������
    {
        cin >> size;
        if (size < 0)
        {
            cout << "������� ������������� ����� ���������: ";
        }
        else return size;
    }
}

int setArr(const int size, int* values) {
    srand(clock());
    for (int i = 0; i < size; i++) {
        values[i] = rand();
    }
    return 0;
}

int printArr(const int  size, int* values) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ": " << values[i] << "\n";
    }
    return 0;
}

int getAvg(const int size, int* values) {
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += values[i];
    }
    cout << "������� ��������������:" << sum/size << endl;
    return 0;
}
