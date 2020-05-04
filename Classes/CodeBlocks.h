#pragma once

#include "Software.h"

class CodeBlocks : public Software {
    struct project_info {
        string name;
        string path;
        string lang;
        string version;
        project_info();
        project_info(string, string, string, string);
    } *proj_inf = nullptr;
public:
    CodeBlocks ();  //Конструктор по умолчанию
    CodeBlocks (string, string, string, string, string, string, string, string);    //Конструктор с параметром и списком инициализации
    CodeBlocks (const CodeBlocks&); //Конструктор копирования

    virtual void change_version() override; //Предопределенная функция для вывода информации об объекте
    virtual void ToPrint() override;    //Переопределнный метод для изменения данных о версии

    void create_project();  //Метод для создания проекта
    void change_lang(); //Метод для изменения языка проекта
    void update_project();  //Метод для обновления проекта

    friend ostream& operator<< (ostream&, const CodeBlocks&);   //Перегрузка оператора ввода
    friend istream& operator>> (istream&, CodeBlocks&); //Перегрузка оператора вывода

    virtual ~CodeBlocks();  //Деструктор
};
