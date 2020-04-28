#include "OperatingSystem.h"

/*
 * Конструкторы струтктуры
 */

OperatingSystem::system_requirement::system_requirement() {
    bit_depth = 0;
    RAM = 0;
    Arch = "";
}

OperatingSystem::system_requirement::system_requirement(int a, int b, string c) {
    bit_depth = a;
    RAM = b;
    Arch = c;
}

/*
 * Конструкторы
 */

OperatingSystem::OperatingSystem() {
    os_name = "";
    sys_req = new system_requirement();
}

OperatingSystem::OperatingSystem(string ver, string vercn, string dev, string devl, string name, int bd, int ram, string arch)
: Software(ver, vercn, dev, devl), os_name(name) ,sys_req(new system_requirement(bd, ram, arch)) {
}

OperatingSystem::OperatingSystem(const OperatingSystem & obj) {
    sys_req = new system_requirement(obj.sys_req->bit_depth, obj.sys_req->RAM, obj.sys_req->Arch);
    version = obj.version;
    ver_codename = obj.ver_codename;
    developer = obj.developer;
    dev_lang = obj.dev_lang;
}

/*
 * Виртуальные ф-ии
 */

void OperatingSystem::ToPrint() {
    cout << "Class OperatingSystem\n";
    cout << *this;
}

void OperatingSystem::change_version() {
    cout << "New Version: ";
    cin >> version;
    cout << "New Version CodeNae: ";
    cin >> ver_codename;
}

/*
 * Перегрузка операторов
 */

ostream& operator<< (ostream& out, const OperatingSystem& obj) {
    out << "Version: " << obj.version << endl
        << "Version CodeName: " << obj.ver_codename << endl
        << "Developer: " << obj.developer << endl
        << "Dev_Language: " << obj.dev_lang << endl
        << "OS Name: " << obj.os_name << endl
        << "System Requirement:\n"
        << "   Bit depth: x" << obj.sys_req->bit_depth << endl
        << "   RAM: " << obj.sys_req->RAM << endl
        << "   Architecture: " << obj.sys_req->Arch << endl;

    return out;
}

istream& operator>> (istream& in, OperatingSystem& obj) {
    cout << "Version: "; in >> obj.version;
    cout << "Version CodeName: "; in >> obj.ver_codename;
    cout << "Developer: "; in >> obj.developer;
    cout << "Dev_Language: "; in >> obj.dev_lang;
    cout << "\nOS Name: "; in >> obj.os_name;
    cout << "System Requirement:\n";
    cout << "   Bit depth: x"; in >> obj.sys_req->bit_depth;
    cout << "   RAM: "; in >> obj.sys_req->RAM;
    cout << "   Architecture: "; in >> obj.sys_req->Arch;

    return in;
}

//Деструктор
OperatingSystem::~OperatingSystem() {
    delete sys_req;
    cout << "\nDestructor OperatingSystem\n";
}
