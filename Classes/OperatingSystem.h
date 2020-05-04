#pragma once

#include "Software.h"

class OperatingSystem : public Software {
protected:
    string os_name;
    struct system_requirement {
        int bit_depth;
        int RAM;
        string Arch;
        system_requirement();   //Конструктор струткуры по умолчнию
        system_requirement(int, int, string);   //Конструктор структуры с параметром
    } *sys_req;
public:
    OperatingSystem();  //Конструктор по умолчанию
    OperatingSystem(string, string, string, string, string, int, int, string);  //Конструктор с параметром и списком инициализации
    OperatingSystem(const OperatingSystem&);    //Констурктор копирования

    virtual void change_version() override; //предопределенная функция для вывода информации об объекте
    virtual void ToPrint() override;    //Переопределнный метод для изменения данных о версии

    friend ostream& operator<< (ostream&, const OperatingSystem&);  //Перегрузка оператора ввода
    friend istream& operator>> (istream&, OperatingSystem&);    //Перегрузка оператора вывода

    virtual ~OperatingSystem(); //Деструктор
};
