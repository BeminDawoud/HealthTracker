#include "Patient.h"

Patient::Patient()
{
    //dtor
}

Patient::Patient(string _Name,string _Email,string _Password,int _Age)
:Person(_Name,_Email,_Password,_Age)
{
    //ctor
}

string Patient::getType()
{
        return "Patient";
}


void Patient::User_interface()
{
    bool signOut = false;
    while(!signOut)
    {

        cout << CYAN <<"-----------------------------------------------------------------------" << endl;
        cout << "Welcome, " << getName() << "! Here are your Options" << endl;
        cout << "1. Enter a Symptom you are facing for medication" << endl;
        cout << "2. Check Available Doctors" << endl;
        cout << "3. Sign Out" << endl;
        cout << "-----------------------------------------------------------------------" << endl;
        int option = 0;
        cout << "Choose an option: ";
        manual_Cin(option);

        switch (option)
        {
            case 1:
            {
                string symptom;
                cout << YELLOW <<"Enter the symptom you are facing: ";
                cin >> symptom;
                cout << GREEN <<"Prescription: Take medicine XYZ" << endl;
                sleep(1);
                cout << "-----------------------------------------------------------------------" << endl;

                break;
            }

            case 2:
                cout << YELLOW <<"Available Doctors:" << endl;
                cout << "1. Dr. Smith (Cardiologist)" << endl;
                cout << "2. Dr. Johnson (Dermatologist)" << endl;
                cout << "-----------------------------------------------------------------------" << endl;
                sleep(1);
                break;

            case 3:
                cout << YELLOW <<"Signing Out..." << endl;
                sleep(1);
                cout << "-----------------------------------------------------------------------" << endl;
                signOut = true;
                return;

            default:
                cout << RED <<"Invalid option. Returning..." << endl;
                sleep(1);
                cout << "-----------------------------------------------------------------------" << endl;
                break;
        }
    }
}

Patient::~Patient()
{
    //dtor
}


