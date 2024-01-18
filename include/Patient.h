#ifndef PATIENT_H
#define PATIENT_H
#include <Person.h>
#include <Doctor.h>
#include <Medicine.h>
class Patient:public Person
{
    public:
        Patient();
        Patient(string _Name,string _Email,string _Password,int _age);
        string getType() override;
        void User_interface() override;
        ~Patient();
    private:
        string condition;
};

#endif // PATIENT_H
