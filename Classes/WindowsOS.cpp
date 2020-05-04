#include "WindowsOS.h"
/*
 * Конструкторы
 */
//конструктор по умолчанию
WindowsOS::WindowsOS() {
    os_name = "";
    sys_req = new system_requirement();
    activation_key = "Your WindowsOS isn't activated!";
    release = "";
    assembly = new float;
}
//Конструктор с параметром и списком инициализации
WindowsOS::WindowsOS(string ver, string vercn, string dev, string devl, string name, int bd, int ram, string arch, string key, string rel, float asseml)
: OperatingSystem(ver, vercn, dev, devl, name, bd, ram, name), activation_key(key), release(rel), assembly(new float(asseml)) {
}
//Конструктор копирования
WindowsOS::WindowsOS(const WindowsOS& obj) {
    version = obj.version;
    ver_codename = obj.ver_codename;
    developer = obj.developer;
    dev_lang = obj.dev_lang;
    sys_req = new system_requirement(obj.sys_req->bit_depth, obj.sys_req->RAM, obj.sys_req->Arch);
    activation_key = obj.activation_key;
    release = obj.release;
    assembly = obj.assembly;
}

/*
 * Методы
 */
/*
 * Метод для активации WindowsOS
 * Ввод ключа и проверка его на правильность так как он должен быть введен по шлбону
 */
void WindowsOS::activation() {
    cout << "Activation\n";
    if (activation_key == "Your WindowsOS isn't activated!") {  //Проверк на активированность WindowsOS
        while(true) {
            bool tmp = 1;    //Результат активации
            cout << "Enter activation key as AAAA-BBBB-CCCC-DDDD: ";
            cin >> activation_key;
            for (int i(4); i < activation_key.length(); i += 5) {   //Проверка на соответсвие шаблону
                if (activation_key[i] != '-' || activation_key.length() != 19) {
                    cout << "You enter invalid key!\n";
                    tmp = 0;    //Если ключ введен неверно то становится false
                    break;
                }
            }
            if (tmp == 0) {     //Если false, то спрашиваем у пользователя не хочет ли он повторить ввод
                int tmp2;
                cout << "If you want to try again input '1', otherwise input '0': "; cin >> tmp2;
                if (tmp2 == 1)
                    continue;
                else {
                    cout << "Your WindowsOS still unactivated\n";
                    activation_key = "Your WindowsOS isn't activated!";
                    return;
                }
            } else if (tmp == 1) break; //Если true то активация прошла успешно
        }
        cout << "Your WindowsOS is activated\n";
    } else
        cout << "Your WindowsOS is already activated\n";
}
/*
 * Метод для обновления WindowsOS
 * Также включает в себя переопределенный метод change_version
 * Если WindowsOS не активирована обновление невозможно
 */
void WindowsOS::update() {
    cout << "Update\n";
    if (activation_key == "Your WindowsOS isn't activated!") {  //Проверка на активацию
        cout << "You need to activate WindowsOS before update\n";
        return;
    }
    cout << "Release: "; cin >> release;
    cout << "Assembly: "; cin >> *assembly;
    change_version();
}

/*
 * Виртуальные ф-ии
 */
//Переопределенный метод ToPrint для вывода информации об объекте класса
void WindowsOS::ToPrint() {
    cout << "Class WindowsOS\n";
    cout << *this;
}
//Переопределнный метод для изменения данных о версии который наследуется из Software
void WindowsOS::change_version() {
    cout << "change_version\n";
    cout << "\tNew Version: "; cin >> version;
    cout << "\tNew Version CodeName: "; cin >> ver_codename;
}

/*
 * Перегрузка операторов
 */
//Перегрузка оператора ввода
ostream& operator<< (ostream& out, WindowsOS& obj) {
    OperatingSystem& OS_obj = obj;
    cout << OS_obj;
    out << "Activation Key: " << obj.activation_key << endl
        << "Release: " << obj.release << endl
        << "Assembly: " << *obj.assembly << endl;

    return out;
}
//Перегрузка оператора вывода
istream& operator>> (istream& in, WindowsOS& obj) {
    cout << "Version: "; in >> obj.version;
    cout << "Version CodeName: "; in >> obj.ver_codename;
    cout << "Developer: "; in >> obj.developer;
    cout << "Dev_Language: "; in >> obj.dev_lang;
    cout << "\nOS Name: WindowsOS\n"; obj.os_name="WindowsOS";
    cout << "System Requirement:\n";
    cout << "\tBit depth: x"; in >> obj.sys_req->bit_depth;
    cout << "\tRAM: "; in >> obj.sys_req->RAM;
    cout << "\tArchitecture: "; in >> obj.sys_req->Arch;
    cout << "Release: "; in >> obj.release;
    cout << "Assembly: "; in >> *obj.assembly;
    cout << endl;

    return in;
}

//Деструктор
WindowsOS::~WindowsOS() {
    cout << "Destructor WindowsOS\n";
    delete assembly;
}
