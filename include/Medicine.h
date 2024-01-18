#ifndef MEDICINE_H
#define MEDICINE_H
#include <iostream>
#include <string.h>
using namespace std;

class Medicine
{
    public:
        Medicine(string _name,string type);
        ~Medicine();
        string getName();
        string getType();
    private:
        string name;
        string type;
};

#endif // MEDICINE_H
