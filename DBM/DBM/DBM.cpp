#include <iostream>

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
    const int size = setSize();
    int* values = new int[size];
    setArr(size, values);      // Заполнение массива
    cout << "Массив: \n";
    printArr(size, values);     // Вывод массива на экран
    getAvg(size, values);
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
    cout << "Среднее арифметическое:" << sum/size << endl;
    return 0;
}
