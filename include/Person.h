#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include <string.h>
#include <unistd.h>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"


// this is a custom cin to fix cin bugs.
void manual_Cin(int &user_choice);

class Person
{
    public:
        Person();
        Person(string _Name,string _Email,string _Password,int _age);
        string getName();
        string getEmail();
        string getPassword();
        int getAge();
        virtual string getType();
        virtual void User_interface();
        ~Person();
    protected:
        string name;
        int age;
        string email;
        string password;
};

#endif // PERSON_H
