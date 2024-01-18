#ifndef DOCTOR_H
#define DOCTOR_H
#include <Person.h>

class Doctor : public Person
{
    public:
        Doctor();
        Doctor(string _Name,string _Email,string _Password,int _Age,string _Specialty);
        string getType() override;
        string getSpecialty();
        void User_interface() override;
        ~Doctor();
    protected:
        string specialty;
};

#endif // DOCTOR_H
