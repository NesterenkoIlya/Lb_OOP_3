#include "WindowsOS.h"

/*
 * Конструкторы
 */

WindowsOS::WindowsOS() {
    os_name = "";
    sys_req = new system_requirement();
    activation_key ="";
    release = "";
    assembly = new float;
}

WindowsOS::WindowsOS(string ver, string vercn, string dev, string devl, string name, int bd, int ram, string arch, string key, string rel, float asseml)
: OperatingSystem(ver, vercn, dev, devl, name, bd, ram, name), activation_key(key), release(rel), assembly(new float(asseml)) {
}

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

void WindowsOS::activation() {
    if (activation_key == "Your Windows OS isn't activated!") {
        cout << "Ebter activation key: ";
        cin >> activation_key;
        cout << "Your WindowsOS is activated\n";
    } else
        cout << "Your WindowsOS is already activated\n";
}

void WindowsOS::update() {
    cout << "Update\n";
    cout << "Release: ";
    cin >> release;
    cout << "Assembly: ";
    cin >> *assembly;
    change_version();
}

/*
 * Виртуальные ф-ии
 */

void WindowsOS::ToPrint() {
    cout << "Class WindowsOS\n";
    cout << *this;
}

void WindowsOS::change_version() {
    cout << "New Version: ";
    cin >> version;
    cout << "New Version CodeNae: ";
    cin >> ver_codename;
}

/*
 * Перегрузка операторов
 */

ostream& operator<< (ostream& out, WindowsOS& obj) {
    OperatingSystem& OS_obj = obj;
    cout << OS_obj;
    out << "Activation Key: " << obj.activation_key << endl
        << "Release: " << obj.release << endl
        << "Assembly: " << obj.assembly << endl;

    return out;
}

istream& operator>> (istream& in, WindowsOS& obj) {
    cout << "Version: "; in >> obj.version;
    cout << "Version CodeName: "; in >> obj.ver_codename;
    cout << "Developer: "; in >> obj.developer;
    cout << "Dev_Language: "; in >> obj.dev_lang;
    cout << "\nOS Name: "; in >> obj.os_name;
    cout << "System Requirement:\n";
    cout << "   Bit depth: x"; in >> obj.sys_req->bit_depth;
    cout << "   RAM: "; in >> obj.sys_req->RAM;
    cout << "   Architecture: "; in >> obj.sys_req->Arch;
    cout << "Activation Key: "; in >> obj.activation_key;
    cout << "Release: "; in >> obj.release;
    cout << "Assembly: "; in >> *obj.assembly;

    return in;
}

//Деструктор
WindowsOS::~WindowsOS() {
    cout << "Destructor WindowsOS\n";
    delete assembly;
}
