#include "Doctor.h"


Doctor::Doctor()
{
    //dtor
}



Doctor::Doctor(string _Name,string _Email,string _Password,int _Age,string _Specialty):
    Person(_Name,_Email,_Password,_Age),specialty(_Specialty)
{
    //ctor
}



void Doctor::User_interface()
{
    bool signOut = false;
    while(!signOut)
    {
        cout << CYAN <<"-----------------------------------------------------------------------" << endl;
        cout << "Welcome, " << getName() << "! Here are your Options" << endl;
        cout << "1. View Patients" << endl;
        cout << "2. Prescribe Medication" << endl;
        cout << "3. Sign Out" << endl;
        cout << "-----------------------------------------------------------------------" << endl;
        int option = 1;
        cout << "Choose an option: ";
        cin.ignore(10, '\n');
        manual_Cin(option);

        switch (option)
        {
            case 0:
                cout << YELLOW <<"Viewing Patients..." << endl;
                sleep(1);
                cout << "-----------------------------------------------------------------------" << endl;
                break;

            case 2:
                cout << YELLOW <<"Prescribing Medication..." << endl;
                sleep(1);
                cout << "-----------------------------------------------------------------------" << endl;
                break;

            case 3:
                cout << YELLOW <<"Signing Out..." << endl;
                signOut = true;
                sleep(1);
                cout << "-----------------------------------------------------------------------" << endl;
                return;

            default:
                cout << RED <<"Invalid option. Returning..." << endl;
                sleep(1);
                cout << "-----------------------------------------------------------------------" << endl;
                break;
        }
    }

}



string Doctor::getType()
{
    return "Doctor";
}


string Doctor::getSpecialty()
{
    return specialty;
}

Doctor::~Doctor()
{
    //dtor
}



