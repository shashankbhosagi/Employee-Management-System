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

void Employee ::displayEmpData()
{
    cout << "Employee ID : " << emp_id << endl;
    cout << "Employee Name : " << emp_name << endl;
    cout << "Employee Designation : " << designation << endl;
    cout << "Employee Age : " << age << endl;
    cout << "Employee Salary : " << salary << endl;
    cout << "Employee Experince : " << experince << endl;
}

int main()
{
   

    return 0;
}
