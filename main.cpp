#include <iostream>
#include "Classes/CodeBlocks.h"
#include "Classes/WindowsOS.h"
#include "Classes/Printer.h"

string delimiter = "________________________________________________________________\n";

using namespace std;

void Interface() {
    cout << delimiter
         << "Веедите:\n"
         << "   1, для создания класса OperatingSystem\n"
         << "   2, для создания класса WindowsOS\n"
         << "   3, для создания класса CodeBlocks\n"
         << "   4, для удаления элемента из массива array\n"
         << "   0, для завершения ввода\n"
         << delimiter;
}

Software** add_element(Software** array, Software* element, int& n) {
    Software** tmp = new Software * [n + 1];
    for (int i(0); i < n; i++)
        tmp[i] = array[i];
    tmp[n] = element;
    delete[] array;
    n++;
    return tmp;
}

Software** delete_element(Software** array, int &n, int index) {
    Software** tmp = new Software * [n--];
    for (int i(0); i < n + 1; i++) {
        if (i == index)
            break;
        tmp[i] = array[i];
    }
    for (int i(index); i < n; i++)
        tmp[i] = array[i + 1];
    return tmp;
}

int main () {
    //system("chcp 1251");
    int n = 0;
    int index = 0;
    Software** array = new Software * [n];
    Printer printer;
    int c;
    do {
        Interface();
        cin >> c;
        switch (c) {
            case 1: {
                OperatingSystem *os = new OperatingSystem;
                cin >> *os;
                cout << *os;
                array = add_element(array, os, n);
                break;
            } case 2: {
                WindowsOS *wos = new WindowsOS;
                cin >> *wos;
                cout << *wos;
                array = add_element(array, wos, n);
                break;
            } case 3: {
                CodeBlocks *cb = new CodeBlocks;
                cin >> *cb;
                cout << *cb;
                array = add_element(array, cb, n);
                break;
            } case 4: {
                cout << "Ведите индекс удаляемого элемента в диапазоне (0," << n << "]\n";
                cin >> index;
                if (index >= n && index < 0)
                    cout << "Вы ввели неверный индекс\n";
                else
                    array = delete_element(array, n, index);
                break;
            } case 0:
                break;
            default:
                break;
        }
    } while (c);
    cout << "n = " << n << endl;
    for (int i(0); i < n; i++) {
        cout << delimiter;
        printer.printing(array[i]);
    }
}