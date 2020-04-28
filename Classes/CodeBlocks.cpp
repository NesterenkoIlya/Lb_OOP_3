#include "CodeBlocks.h"

/*
 * Конструкторы структуры project_info
 */
CodeBlocks::project_info::project_info() {
    name = "";
    path = "";
    lang = "";
}

CodeBlocks::project_info::project_info(string a, string b, string c) {
    name = a;
    path = b;
    lang = c;
}

/*
 * Конструкторы
 */
//Конструктор по умолчанию
CodeBlocks::CodeBlocks() {
    proj_inf = new project_info();
}

//Конструктор с параметром и списком инициализации
CodeBlocks::CodeBlocks(string a, string b, string c, string d, string e, string f, string g)
: Software(a, b, c, d), proj_inf(new project_info(e, f, g)) {
}

//Конструктор копирования
CodeBlocks::CodeBlocks(const CodeBlocks& obj) {
    proj_inf = new project_info(obj.proj_inf->name, obj.proj_inf->path, obj.proj_inf->lang);
    version = obj.version;
    ver_codename = obj.ver_codename;
    developer = obj.developer;
    dev_lang = obj.dev_lang;
}

/*
 * Перегрузка Операций
 */
//Перегрузка операйии вывода
ostream& operator<< (ostream& out, const CodeBlocks& obj) {
    out << "Version: " << obj.version << endl
        << "Version CodeName: " << obj.ver_codename << endl
        << "Developer: " << obj.developer << endl
        << "Dev_Language: " << obj.dev_lang << endl
        << "Project info:\n"
        << "    Name: " << obj.proj_inf->name << endl
        << "    Path: " << obj.proj_inf->path << endl
        << "    Lang: " << obj.proj_inf->lang << endl;

    return out;
}

//Перегрузка операции ввода
istream& operator>> (istream& in, CodeBlocks& obj) {
    cout << "Version: "; in >> obj.version;
    cout << "Version CodeName: "; in >> obj.ver_codename;
    cout << "Developer: "; in >> obj.developer;
    cout << "Dev_Language: "; in >> obj.dev_lang;
    cout << "\nProject info:\n";
    cout << "    Name: "; in >> obj.proj_inf->name;
    cout << "    Path: "; in >> obj.proj_inf->path;
    cout << "    Lang: "; in >> obj.proj_inf->lang;

    return in;
}

/*
 * Виртуальные ф-ии
 */
void CodeBlocks::ToPrint() {
    cout << "Class CodeBlocks\n";
    cout << *this;
}

void CodeBlocks::change_version() {
    cout << "New Version: ";
    cin >> version;
    cout << "New Version CodeNae: ";
    cin >> ver_codename;
}

//Деструктор
CodeBlocks::~CodeBlocks() {
    delete proj_inf;
    cout << "Destructor CodeBlocks\n";
}
