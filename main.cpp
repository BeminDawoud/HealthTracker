#include "Person.h"
#include "Patient.h"
#include "Doctor.h"
#include "Admin.h"

#define MAX_USERS 10
#define MAX_ADMINS 10

Patient patients[MAX_USERS];
Doctor doctors[MAX_USERS];
Admin admins[MAX_ADMINS];

int patients_index = 0;
int doctors_index = 0;
string userEmail;
string userPassword;

Person *loggedInUser = NULL;
bool foundUser = false;
bool correctPassword = false;

bool checkEmail();
bool checkPassword();
bool emailExists(string email);


int main()
{
    // Predefined DataBase of Users
    patients[patients_index++] = Patient("Ahmed Saber", "ahmed@gmail.com", "123", 50);
    patients[patients_index++] = Patient("Joseph", "Joseph@gmail.com", "123", 42);
    patients[patients_index++] = Patient("Sara", "sara@gmail.com", "123", 35);
    doctors[doctors_index++] = Doctor("Dr. Mariam", "mariam@gmail.com", "123", 45, "Cardiologist");
    doctors[doctors_index++] = Doctor("Dr. Youssef", "joo@gmail.com", "123", 38, "Dermatologist");
    admins[0] = Admin("Bemin", "bemin@gmail.com", "123", 35);
    admins[1] = Admin("David", "david@gmail.com", "123", 35);
    admins[2] = Admin("Basma", "basma@gmail.com", "123", 35);

    while (true)
    {
        int user_choice = 0;

        cout << GREEN <<"-----------------------------------------------------------------------" << endl;
        cout << GREEN << "Welcome to Health Track" << endl;
        cout << GREEN <<"-----------------------------------------------------------------------" << endl;
        sleep(1);

        cout << BLUE <<"Choose your option:" << endl;
        cout << "1. Log in" << endl;
        cout << "2. Sign up" << endl;
        cout << "3. Exit" << endl;
        cout << "-----------------------------------------------------------------------" << endl;
        manual_Cin(user_choice);

        if (user_choice == 3)
        {
            cout << "Exiting..." << endl;
            break;
        }

        if (user_choice == 1)
        {
            cout << CYAN <<"Enter your email: ";
            cin >> userEmail;

            // Check if the user exists in the system
            if(checkEmail())
            {
                if (checkPassword())
                    loggedInUser->User_interface();
            }
            else
            {
                cout << RED <<"User Email is not found, Try Again" << endl;
                cout << "Returning to main interface..." << endl;
                sleep(2);
            }

        }
            // User is new and he needs to sign up.
        else if (user_choice == 2)
        {
            int roleChoice = 0;

            while(roleChoice != 1 && roleChoice != 2)
            {
                cout << MAGENTA <<"-----------------------------------------------------------------------" << endl;
                cout << "Choose your role:" << endl;
                cout << "1. Patient" << endl;
                cout << "2. Doctor" << endl;
                cout << "-----------------------------------------------------------------------" << endl;
                manual_Cin(roleChoice);

                switch (roleChoice)
                {
                    case 1:
                    {
                        // Patient
                        string name, email, password;
                        int age;

                        cout << CYAN << "Enter your name: ";
                        cin >> name;

                        cout << "Enter your email: ";
                        cin >> email;
                        if (emailExists(email))
                            break;

                        cout << "Enter your password: ";
                        cin >> password;

                        cout << "Enter your age: ";
                        cin >> age;

                        // Add the new patient to the system
                        patients[patients_index++] = Patient(name, email, password, age);
                        break;
                    }

                    case 2:
                    {
                        // Doctor
                        string name, email, password, specialty;
                        int age;

                        cout << CYAN <<"Enter your name: ";
                        cin >> name;

                        cout << "Enter your email: ";
                        cin >> email;
                        if (emailExists(email))
                            break;

                        cout << "Enter your password: ";
                        cin >> password;

                        cout << "Enter your age: ";
                        cin >> age;

                        cout << "Enter your specialty: ";
                        cin >> specialty;

                        // Add the new doctor to the system
                        doctors[doctors_index++] = Doctor(name, email, password, age, specialty);
                        break;
                    }

                    default:
                        cout << RED <<"Invalid role choice. Returning..." << endl;
                        cout << "-----------------------------------------------------------------------\n" << endl;
                        sleep(2);
                        break;
                }
            }

        }

        else
        {
            cout << RED <<"Invalid choice. Returning to main interface...\n" << endl;
            cout << "-----------------------------------------------------------------------\n" << endl;
            sleep(1);
            continue;
        }
    }

    return 0;
}


bool checkEmail()
{
    foundUser = false;

    for (int i = 0; i < MAX_USERS; i++)
    {
        if (patients[i].getEmail() == userEmail)
        {
            foundUser = true;
            loggedInUser = &patients[i];
            break;
        }
    }

    for (int i = 0; i < MAX_USERS; i++)
    {
        if (doctors[i].getEmail() == userEmail)
        {
            foundUser = true;
            loggedInUser = &doctors[i];
            break;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (admins[i].getEmail() == userEmail)
        {
            foundUser = true;
            loggedInUser = &admins[i];
            break;
        }
    }

    return foundUser;
}


bool checkPassword()
{
    int i = 0;
    correctPassword = false;

    cout << CYAN <<"Enter Your Password: " << endl;
    cin >> userPassword;
    while (!correctPassword && i < 3)
    {
        if(loggedInUser->getPassword() == userPassword)
        {
            correctPassword = true;
            cout << GREEN << "You have successfully logged in..." << endl;
            cout << "-----------------------------------------------------------------------\n" << endl;
            return correctPassword;
        }
        else
        {
            cout << RED <<"Wrong Password, You only have three chances... " << endl;
            cout << "Enter Your Password Again: " << endl;
            cin >> userPassword;
        }
        i++;
    }
    cout << RED <<"Password is Incorrect, Exitting..." << endl;
    cout << "-----------------------------------------------------------------------\n" << endl;
    sleep(1);
    return false;
}

bool emailExists(string email)
{
    for (int i = 0; i < MAX_USERS; i++)
    {
        if (patients[i].getEmail() == email || doctors[i].getEmail() == email || admins[i].getEmail() == email)
        {
            cout << RED << "Email already exists. Please choose a different email." << endl;
            return true;
        }
    }
    return false;
}

void manual_Cin(int &user_choice)
{
    if (!(cin >> user_choice))
    {
        cin.clear();
        cin.ignore(10000,'\n');
    }
}
