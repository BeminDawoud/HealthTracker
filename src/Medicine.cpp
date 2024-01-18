#include "Medicine.h"

Medicine::Medicine(string _name,string _type):name(_name),type(_type)
{
    //ctor
}

Medicine::~Medicine()
{
    //dtor
}
string Medicine::getName(){
    return name;
}
string Medicine::getType(){
    return type;
}
