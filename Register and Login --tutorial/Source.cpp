// Register and Login tutorial by Inhale Code via Youtube

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

void login();
void registr();
void forgot();


int main()
{
    int choice;
    cout << "***********************************" << endl;
    cout << "**************WELCOME**************" << endl;
    cout << "MENU: " << endl;
    cout << "1) Login" << endl;
    cout << "2) Register" << endl;
    cout << "3) Forgot Username or Password" << endl;
    cout << "4) Exit" << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice;
    cout << endl;

    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        registr();
        break;
    case 3:
        forgot();
        break;
    case 4:
        system("cls");
        cout << "Invalid input, please try again.";
            main();
    }
}

void login()
{
    int count;
    string user, pass, u, p;
    system("cls");
    cout << "Please enter the following details: " << endl;
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    ifstream input("database.txt");
    while (input >> u >> p)
    {
        if (u == user && p == pass)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << "Hello " << user << "\n <LOGIN SUCCESSFUL>\n";
        cin.get();
        main();
    }
}
// register first
void registr()
{
    string reguser, regpass, ru, pu;
    system("cls");
    cout << "Enter Username: ";
    cin >> reguser;
    cout << "Enter Password: ";
    cin >> regpass;

    ofstream reg("database.txt", ios::app);
    reg << reguser << " " << regpass << endl;
    system("cls");
    cout << "\nRegistration Successful. " << endl;
    main();
}

void forgot()
{
    int ch;
    system("cls");
    cout << "Forget?" << endl;
    cout << "1) Search your id by userename" << endl;
    cout << "2) Main Menu" << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
        int count = 0;
        string searchuser, su, sp;
        cout << "\n Enter your username: ";
        cin >> searchuser;

        ifstream searchu("database.txt");
        while (searchu >> su >> sp)
        {
            if (su == searchuser)
            {
                count = 1;
            }
        }
        searchu.close();
        if (count == 1)
        {
            cout << "\n Account Found" << endl;
            cout << "\nYour password is: " << sp;
            cin.get();
            system("cls");
            main();
        }
        else
        {
            cout << "\nSorry, your userID was not found...\n";
                cin.get();
            main();
        }
        break;
    }
}