#ifndef DISEASE_H
#define DISEASE_H
#include <iostream>
#include <string.h>
using namespace std;

class Disease
{
    public:
        Disease(string _name,string _symptoms);
        ~Disease();
        string getName();
        string getSymptoms();
    private:
        string name;
        string symptoms;
};

#endif // DISEASE_H
