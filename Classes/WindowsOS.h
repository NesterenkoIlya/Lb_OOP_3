#pragma once

#include "OperatingSystem.h"

class WindowsOS : public OperatingSystem {
    string activation_key = "Your Windows OS isn't activated!";
    string release;
    float* assembly;
public:
    WindowsOS();
    WindowsOS(string, string, string, string, string, int, int, string, string, string, float);
    WindowsOS(const WindowsOS&);

    void activation();
    void update();

    virtual void ToPrint() override;
    virtual void change_version() override;

    friend ostream& operator<< (ostream&, WindowsOS&);
    friend istream& operator>> (istream&, WindowsOS&);

    virtual ~WindowsOS();
};
