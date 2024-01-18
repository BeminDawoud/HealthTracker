#ifndef ADMIN_H
#define ADMIN_H


#include <Person.h>
#include<Doctor.h>
#include<Patient.h>


class Admin : public Person
{
    public:
        Admin();
        Admin(string _Name,string _Email,string _Password,int _Age);
        string getType() override;
        void User_interface() override;
        ~Admin();
};

#endif // ADMIN_H
