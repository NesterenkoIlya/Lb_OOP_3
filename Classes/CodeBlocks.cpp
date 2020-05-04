#include "CodeBlocks.h"
/*
 * Конструкторы структуры project_info
 */
//Конструктор структуры по умолчанию
CodeBlocks::project_info::project_info() {
    name = "";
    path = "";
    lang = "";
    version = "";
}
//Конструктор с параметрами и списком инициализации
CodeBlocks::project_info::project_info(string a, string b, string c, string d) {
    name = a;
    path = b;
    lang = c;
    version = d;
}

/*
 * Конструкторы
 */
//Конструктор по умолчанию
CodeBlocks::CodeBlocks() {
    proj_inf = new project_info();
}
//Конструктор с параметром и списком инициализации
CodeBlocks::CodeBlocks(string a, string b, string c, string d, string e, string f, string g, string h)
: Software(a, b, c, d), proj_inf(new project_info(e, f, g, h)) {
}
//Конструктор копирования
CodeBlocks::CodeBlocks(const CodeBlocks& obj) {
    proj_inf = new project_info(obj.proj_inf->name, obj.proj_inf->path, obj.proj_inf->lang, obj.proj_inf->version);
    version = obj.version;
    ver_codename = obj.ver_codename;
    developer = obj.developer;
    dev_lang = obj.dev_lang;
}

/*
 * Методы
 */
//Метод для создания проекта
void CodeBlocks::create_project() {
    cout << "create_project\n"
         << "Project info:\n";
    cout << "\tName: "; cin >> proj_inf->name;
    cout << "\tPath: "; cin >> proj_inf->path;
    cout << "\tLang: "; cin >> proj_inf->lang;
    cout << "\tVersion: "; cin >> proj_inf->version;
}
//Метод для изменения языка проекта
void CodeBlocks::change_lang() {
    cout << "change_lang\n"
         << "New project lang: ";
    cin >> proj_inf->lang;
}
//Метод для обновления проекта
void CodeBlocks::update_project() {
    cout << "update_project\n";
    cout << "New project version: "; cin >> proj_inf->version;
}

/*
 * Виртуальные ф-ии
 */
//Предопределенная функция для вывода информации об объекте
void CodeBlocks::ToPrint() {
    cout << "Class CodeBlocks\n";
    cout << *this;
}
//Переопределнный метод для изменения данных о версии
void CodeBlocks::change_version() {
    cout << "change_version\n";
    cout << "New Version: "; cin >> version;
    cout << "New Version CodeNae: "; cin >> ver_codename;
    cout << "New project version: "; cin >> proj_inf->version;
}

/*
 * Перегрузка Операций
 */
//Перегрузка операции ввода
istream& operator>> (istream& in, CodeBlocks& obj) {
    cout << "Version: "; in >> obj.version;
    cout << "Version CodeName: "; in >> obj.ver_codename;
    cout << "Developer: "; in >> obj.developer;
    cout << "Dev_Language: "; in >> obj.dev_lang;
    obj.create_project();

    return in;
}
//Перегрузка операйии вывода
ostream& operator<< (ostream& out, const CodeBlocks& obj) {
    out << "Version: " << obj.version << endl
        << "Version CodeName: " << obj.ver_codename << endl
        << "Developer: " << obj.developer << endl
        << "Dev_Language: " << obj.dev_lang << endl
        << "Project info:\n"
        << "\tName: " << obj.proj_inf->name << endl
        << "\tPath: " << obj.proj_inf->path << endl
        << "\tLang: " << obj.proj_inf->lang << endl
        << "\tVersion: " << obj.proj_inf->version << endl;

    return out;
}

//Деструктор
CodeBlocks::~CodeBlocks() {
    delete proj_inf;
    cout << "Destructor CodeBlocks\n";
}
