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
    int x=0;
    Employee emp, e;
    char ch;int option;
    fstream file;
    int isFound;
    int ID;

    file.open("fileName", ios::ate | ios :: in | ios::out | ios::binary);
    do
    {
        cout<<"--------------Menu--------------\n";
        cout<<"1. => Add a record\n";
        cout<<"2. => Display the Record\n";
        cout<<"3. => Search Employee using Empolyee ID \n";
        cout<<"4. => Update the Record\n";
        cout<<"5. => Delete the record of particular employee \n";
        cout<<"6. => Exit the Menu\n";
        cin>>option;

    switch(option)
    {
        case 1:
        {
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
        }

        case 2:
        {cout<<"\nRecord for Employee";
        file.seekg(0, ios::beg);
        int count = 0;
        file.read((char*)&e, sizeof(e));
        cout<<"\n"<<"     "<<"Emp ID"<<""<<"Name"<<""<<"Designation"<<""<<"age"<<""<<"Salary"<<""<<"Experince";

        while (file)
        {
            count++;
            e.displayEmpData();
            file.read((char*)&e, sizeof(e));
                       
        }
        cout<<endl<<count<<" records found......";
        break;
        }
        case 3:
        {
        isFound = 0;
        cout<<"\n"<<"Enter ID of an employee to be searched : ";
        cin>>ID;
        file.seekg(0, ios::beg);
        file.read((char *)&e, sizeof(e));
        while (file)
        {
            if(e.getID() == ID)
            {
                cout<<"Record found....";
                cout<<"\n"<<"     "<<"Emp ID"<<""<<"Name"<<""<<"Designation"<<""<<"age"<<""<<"Salary"<<""<<"Experince";
                e.displayEmpData();
                isFound = 1;
                break;

            }
            file.read((char *)&e, sizeof(e)); 
        }
        if(isFound == 0)
        {
            cout<<"Data not found for this employee id #"<<ID;
        }
        break;
        }

        case 4: //Update the record
        {
        int i=0;
        cout<<"\n"<<"File is being modified";
        cout<<"\nEnter employee Id to be updated : ";
        cin>>ID;
        isFound = 0;
        file.seekg(0, ios::beg);
        file.read((char *)&e, sizeof(e));
        while (file)
        {
            i++;
            if (e.getID() == ID)
            {
                cout<<"The old record of employee having ID : "<<ID<<"is:";
                e.displayEmpData();
                isFound = 1;
                break;
            }
            file.read((char *)&e, sizeof(e));

            
        }

        if(isFound == 0)
        {
            cout<<"\nData not found for employee ID#"<<ID;
            break;
        }

        file.clear();
        int location = (i-1)*sizeof(e);
        file.seekp(location, ios::beg);
        cout<<"\nEnter new the record for employee having ID"<<ID;
        e.readEmpData();
        file.write((char*)&e, sizeof(e));
        break;
        }
        
        case 5: //delete record 
        {
            int i=0;
            cout<<"\nENter the employee ID to be deleted:";
            cin>>ID;
            isFound = 0;
            file.seekg(0, ios::beg);
            file.read((char *)&e, sizeof(e));
            while (file)
            {
                i++;
                if (e.getID() == ID)
                {
                    cout<<"The old record of the employee having ID";
                }
                
            }
            
            
        }

        

               
        x++;
    }while(x!=1);
    
    } while (1);

    

    return 0;
}
