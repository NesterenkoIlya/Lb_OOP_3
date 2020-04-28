#pragma once

#include "Software.h"

class OperatingSystem : public Software {
protected:
    string os_name;
    struct system_requirement {
        int bit_depth;
        int RAM;
        string Arch;
        system_requirement();
        system_requirement(int, int, string);
    } *sys_req;
public:
    OperatingSystem();
    OperatingSystem(string, string, string, string, string, int, int, string);
    OperatingSystem(const OperatingSystem&);

    virtual void change_version() override;
    virtual void ToPrint() override;

    friend ostream& operator<< (ostream&, const OperatingSystem&);
    friend istream& operator>> (istream&, OperatingSystem&);

    virtual ~OperatingSystem();
};
