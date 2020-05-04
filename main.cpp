#include <iostream>
#include "Classes/CodeBlocks.h"
#include "Classes/WindowsOS.h"
#include "Classes/Printer.h"
using namespace std;
string delimiter = "________________________________________________________________\n";

void Interface();
Software** add_element(Software** array, Software* element, int& n);    //Функция для добавления обьекта в массив
Software** delete_element(Software** array, int &n, int index); //Функция для удаления обьекта из массив

int main () {
    //system("chcp 1251");
    int n(0), index(0);
    Software** array = new Software *[n];
    Printer printer;
    int c;
    do {
        Interface();
        cin >> c;
        switch (c) {
            case 1: {   //Кейс для проверки класса OperatingSystem
                OperatingSystem *os = new OperatingSystem;  //Создание динамического объекта класса OperatingSystem
                cin >> *os;
                cout << *os;
                os->change_version();
                array = add_element(array, os, n);
                break;
            } case 2: { //Кейс для проверки класса WindowsOS
                WindowsOS *wos = new WindowsOS; //Создание динамического объекта класса WindwosOS
                cin >> *wos;
                cout << *wos;
                wos->update();
                wos->activation();
                wos->update();
                cout << *wos;
                array = add_element(array, wos, n);
                break;
            } case 3: { //Кейс для проверки класса CodeBlocks
                CodeBlocks *cb = new CodeBlocks;    //Создание динамического объекта класса CodeBlocks
                cin >> *cb;
                cout << *cb;
                cb->create_project();
                cb->change_lang();
                cb->change_version();
                cb->update_project();
                array = add_element(array, cb, n);
                break;
            } case 4: { //Кейс для удаления элемента из массива array
                cout << "Ведите индекс удаляемого элемента в диапазоне (0," << n << "]\n";
                cin >> index;
                if (index >= n && index < 0)
                    cout << "Вы ввели неверный индекс\n";
                else
                    array = delete_element(array, n, index);
                break;
            } case 0:   //Кейс для завершения ввода
                break;
            default:
                break;
        }
    } while (c);
    cout << "n = " << n << endl;    //Вывод количества элементов массива array
    for (int i(0); i < n; i++) {    //Вывод информации обо всех обьектах в массиве array с помощью printer
        cout << delimiter;
        printer.printing(array[i]);
    }
    for (int i = 0; i < n; i++)
        delete array[i];
    delete[] array;
}

void Interface() {
    cout << delimiter
         << "Веедите:\n"
         << "\t1, для создания класса OperatingSystem\n"
         << "\t2, для создания класса WindowsOS\n"
         << "\t3, для создания класса CodeBlocks\n"
         << "\t4, для удаления элемента из массива array\n"
         << "\t0, для завершения ввода\n"
         << delimiter;
}
Software** add_element(Software** array, Software* element, int& n) {
    Software** tmp = new Software * [n + 1];    //Создание временного массива размером n+1
    for (int i(0); i < n; i++)  //Копирование array в tmp
        tmp[i] = array[i];
    tmp[n] = element;   //Добавление нового элемента в конец массива tmp
    delete[] array;
    n++;
    return tmp;
}
Software** delete_element(Software** array, int &n, int index) {
    Software** tmp = new Software * [n--];  //Создание временного массива размером n-1
    for (int i(0); i < n + 1; i++) {    //Копирование всех элементов массива array в tmp до array[index]
        if (i == index)
            break;
        tmp[i] = array[i];
    }
    for (int i(index); i < n; i++)  //Копирование всех элементов массива array в tmp после array[index]
        tmp[i] = array[i + 1];
    return tmp;
}
