#include "Person.h"

Person::Person()
{
    //dtor
}


Person::Person(string _Name,string _Email,string _Password,int _Age):name(_Name),email(_Email),password(_Password),age(_Age)
{
    //ctor
}

string Person::getName()
{
    return name;
}


string Person::getEmail(){
    return email;
}


string Person::getPassword(){
    return password;
}


int Person::getAge(){
    return age;
}

string Person::getType()
{
        return "Person";
}

void Person::User_interface()
{
     cout << "Welcome, " << getName() << "! " << endl;
}

Person::~Person()
{
    //dtor
}

