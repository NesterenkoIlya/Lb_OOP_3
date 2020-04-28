#include "Software.h"

Software::Software() {
    system("chcp 1251");
}

Software::Software(string a, string b, string c, string d) : version(a), ver_codename(b), developer(c),  dev_lang(d) {
    system("chcp 1251");
}



Software::~Software() {
    cout << "Destructor Software\n";
}