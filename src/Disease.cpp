#include "Disease.h"

Disease::Disease(string _name,string _symptoms):name(_name),symptoms(_symptoms)
{
    //ctor
}

Disease::~Disease()
{
    //dtor
}
string Disease::getName(){
    return name;
}
string Disease::getSymptoms(){
    return symptoms;
}
