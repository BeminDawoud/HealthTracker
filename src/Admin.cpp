#include "Admin.h"

Admin::Admin()
{
    //dtor
}

Admin::Admin(string _Name,string _Email,string _Password,int _Age):Person(_Name,_Email,_Password,_Age)
{
    //ctor
}


void Admin::User_interface()
{
    bool signOut = false;
    while(!signOut)
    {
        cout << CYAN << "-----------------------------------------------------------------------" << endl;
        cout << "Welcome, " << getName() << "! Here are your Options" << endl;
        cout << "1. Manage Doctors" << endl;
        cout << "2. Manage Patients" << endl;
        cout << "3. Sign Out" << endl;
        cout << "-----------------------------------------------------------------------" << endl;
        int option = 0;
        cout << "Choose an option: ";
        manual_Cin(option);

        switch (option)
        {
            case 1:
                cout << YELLOW <<"Managing Doctors..." << endl;
                sleep(1);
                cout << "-----------------------------------------------------------------------" << endl;
                break;

            case 2:
                cout << YELLOW <<"Managing Patients..." << endl;
                sleep(1);
                cout << "-----------------------------------------------------------------------" << endl;
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


string Admin::getType()
{
    return "Admin";
}



Admin::~Admin()
{
    //dtor
}


