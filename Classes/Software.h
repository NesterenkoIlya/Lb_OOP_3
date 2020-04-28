#pragma once
#include <iostream>
#include <string>
using namespace std;

class Software {
protected:
    string version = "";
    string ver_codename = "";
    string developer = "";
    string dev_lang = "";
public:
    Software(); //Конструктор по умолчанию
    Software(string, string, string, string);   //Конструктор по умолчанию и списком инициализации

    virtual void change_version () = 0; //Виртуальная ф-ия для изменения версии
    virtual void ToPrint() = 0; //Метод для вывода информации о классе

    virtual ~Software();    //Деструктор
};