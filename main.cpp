    // bhagwat
#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Employee
{
    char emp_name[20];
    long int emp_id;
    int salary;
    char designation[20];
    int experince;
    int age;

public:
    void readEmpData();
    void displayEmpData();
    int getID();
};

void Employee ::readEmpData()
{
    cout << "Employee ID : ";
    cin >> emp_id;

    cout << "Employee Name : ";
    cin >> emp_name;
    cout << "Employee Designation : ";
    cin >> designation;
    cout << "Employee age : ";
    cin >> age;
    cout << "Employee salary : ";
    cin >> salary;
    cout << "Employee Experince : ";
    cin >> emp_id;
}

void Employee::displayEmpData()
{
    cout << "Employee ID : " << emp_id <<emp_name<<designation<<age<<salary<<experince<< endl;
}

int Employee::getID()
{
    return emp_id;
}

int main()
{
    Employee emp, e;
    char ch, option;
    fstream file;
    int isFound;
    file.open("fileName", ios::ate | ios :: in | ios::out | ios::binary);
    do
    {
        cout<<"--------------Menu--------------";
        cout<<"1. => Add a record";
        cout<<"2. => Display the Record";
        cout<<"3. => Search Employee using Empolyee ID ";
        cout<<"4. => Update the Record";
        cout<<"5. => Delete the record of particulat employee ";
        cout<<"6. => Exit the Menu";

    } while (ch !='n'||'N');
    cin>>option;

    switch(option)
    {
        case '1':
        emp.readEmpData();
        file.seekg(0, ios::beg);
        isFound = 0;
        file.read((char*)&e, sizeof(e));
        while (!(file.eof()))
        {
            if(e.getID() == emp.getID())
            {
                cout<<"This ID already Exists!!!! Pls try for another ID";
                isFound = 1;
                break;
            }
            file.read((char *)&e, sizeof(e));

        }
        if(isFound == 1)
        {
            break;
        }
        file.clear();
        file.seekp(0, ios::end);
        file.write((char*)&emp, sizeof(emp));
        cout<<"New record has been added successfully :)";
        break;

        case '2':
               
        
    }
    

    return 0;
}
