#include <iostream>
#include "../DLS/DLS.h"

using namespace std;

/*!
Функция получения среднего арифметического в массиве
Принимает на вход размер массива и указатель на массив
*/
int getAvg(const int size, int* values);
/*!
Функция установки размера массива
*/
int setSize();
/*!
Функция заполнения массива
Принимает на вход размер массива и указатель на массив
*/
int setArr(const int size, int* values);
/*!
Функция вывода массива на экран
Принимает на вход размер массива и указатель на массив
*/
int printArr(const int  size, int* values);



/*
Главная функция
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Выберите режим: \n1. Массив \n2. ДЛС\n: ";
    int work;
    cin >> work;
    if (work == 1)
    {
        const int size = setSize();
        int* values = new int[size];
        setArr(size, values);      // Заполнение массива
        cout << "Массив: \n";
        printArr(size, values);     // Вывод массива на экран
        getAvg(size, values);       // Среднее арифметическое
    }
    else if (work == 2)
    {
        DLS ll;
        cout << ll.ToString();
        //DLS ll = { 11, 33, 44 };
        ll.AddElementTail(50);
        ll.AddElementHead(10);
        cout << ll.GetElement(1);
        cout << ll.ToString();
        //ll.addElement(1, 22);
        //ll.addElement(6, 37);
        ll.AddElement(3, 35);
        ll.RemoveElement(1);
        cout << ll.ToString();
    }
}

int setSize() {
    int size;
    cout << "Введите размер массива: \n";
    while (true)    // Проверка на положительный размер массива
    {
        cin >> size;
        if (size < 0)
        {
            cout << "Введите положительное число элементов: ";
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
    cout << "Среднее арифметическое:" << sum / size << endl;
    return 0;
}
