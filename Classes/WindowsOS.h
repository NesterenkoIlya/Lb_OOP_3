#pragma once

#include "OperatingSystem.h"

class WindowsOS : public OperatingSystem {
    string activation_key;  //Ключ активации
    string release; //Выпуск
    float* assembly;    //Сборка
public:
    WindowsOS();    //Конструктор по умолчанию
    WindowsOS(string, string, string, string, string, int, int, string, string, string, float); //Конструктор с параметром и спиком инициализаии
    WindowsOS(const WindowsOS&);    //Конструктор копирования

    void activation();  //Метод для ввода ключа активации
    void update();  //Метод для обновления

    virtual void ToPrint() override;    //Предопределенная функция для вывода информации об объекте
    virtual void change_version() override; //Переопределнный метод для изменения данных о версии


    friend istream& operator>> (istream&, WindowsOS&);  //Перегрузка оператора ввода
    friend ostream& operator<< (ostream&, WindowsOS&);  //Перегрузка оператора вывода

    virtual ~WindowsOS();   //Деструктор
};
