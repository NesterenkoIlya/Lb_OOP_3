#pragma once

#include "Software.h"

class CodeBlocks : public Software {
    struct project_info {
        string name;
        string path;
        string lang;
        project_info();
        project_info(string, string, string);
    } *proj_inf = nullptr;
public:
    CodeBlocks ();
    CodeBlocks (string, string, string, string, string, string, string);
    CodeBlocks (const CodeBlocks&);

    virtual void change_version() override;
    virtual void ToPrint() override;

    friend ostream& operator<< (ostream&, const CodeBlocks&);
    friend istream& operator>> (istream&, CodeBlocks&);

    virtual ~CodeBlocks();
};
