#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;
#define limit 50

int employee_count = 0;

class employee
{

public:
    int emp_id;
    char emp_name[30];
    int age;
    char date_of_birth[10];
    char position[20];
    char gender;
    int experince;
    int salary;
    void get_data();
    void print_data(int i);
};
employee emp[limit];

void employee ::get_data()
{
    cout << "--------------Taking INput---------------\n";
    if (employee_count < limit)
    {
        cout << "\n Enter id (number): ";
        cin >> emp[employee_count].emp_id;
        cout << "\n Enter Name (20 characters): ";
        cin >> emp[employee_count].emp_name;
        cout << "\n Enter Age (number): ";
        cin >> emp[employee_count].age;
        cout << "\n Enter DOB (dd-mm-yy): ";
        cin >> emp[employee_count].date_of_birth;
        cout << "\n Enter Position : ";
        cin >> emp[employee_count].position;
        cout << "\n Enter Gender (M/F) : ";
        cin >> emp[employee_count].gender;
        cout << "\n Enter years of experince";
        cin >> emp[employee_count].experince;
        cout << "\n Enter Salary";
        cin >> emp[employee_count].salary;
        employee_count++;
    }
    else
    {
        cout << "\n Cannot add more than 50 Employees";
    }
}

void employee ::print_data(int i)
{
    if (i == 0)
    {
        cout << "\n"
             << "EmpID" << setw(6) << "Name" << setw(20) << "Designation" << setw(10) << "age" << setw(10) << "Salary" << setw(15) << "Experince";
        cout << "\n " << emp[i].emp_id << "    " << emp[i].emp_name << "     " << emp[i].position << setw(5) << emp[i].age << setw(9) << emp[i].salary << setw(10) << emp[i].experince;
    }
    else
    {
        cout << "\n " << emp[i].emp_id << "    " << emp[i].emp_name << "     " << emp[i].position << setw(5) << emp[i].age << setw(9) << emp[i].salary << setw(10) << emp[i].experince;
    }

     
}

void print_by_age()
{
    cout << "\n **** **** Printing All Records by Age********";
    int count50plus = 0;
    int count40plus = 0;
    int lessthen40 = 0;

    for (int i = 0; i < employee_count; i++)
    {
        if (emp[i].age > 21)
            count50plus++;
        else if (emp[i].age >= 18)
            count40plus++;
        else
            lessthen40++;
    }

    cout << "\n Persons more than 21 : " << count50plus;
    cout << "\n Persons more than 18 : " << count40plus;
    cout << "\n Persons less than 18 : " << lessthen40;
}

void print_count_by_gender()
{

    cout << "******Print No. of males and Females******";

    int male = 0;
    int female = 0;

    for (int i = 0; i < employee_count; i++)
    {
        if (emp[i].gender == 'm' || 'M')
        {
            male++;
        }
        else if (emp[i].gender == 'f' || 'F')
        {
            female++;
        }
    }

    cout << "\nNumber of Male : " << male;
    cout << "\nNumber of Female : " << female;
}

int choice = -1;

int main()
{
    do
    {
        cout << "\n\n <<<<<<<<<<<<<<<<<<<<  MENU >>>>>>>>>>>>>>>>>>>>\n";
        cout << "\n 1 Input Records";
        cout << "\n 2 Print All Records";
        cout << "\n 3 Print By Age(greater than 21, greater 18, less than 18)";
        cout << "\n 4 Print count of genders";
        cout << "\n 0 to Exit!!\n";
        cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< >>>>>>>>>>>>>>>>>>>>>>>>>";

        cout << "\n\n Enter your Choice : ";
        cin >> choice;
        if (choice == 0)
        {
            break;
        }
        else
        {
            switch (choice)
            {
            case 1:
            {
                emp[employee_count].get_data();
                break;
            }

            case 2:
            {
                cout << "=============Printing the list of Employees=============";
                cout << "total_number of employees : " << employee_count << endl;

                for (int i = 0; i < employee_count; i++)
                {
                    
                   
                        emp[i].print_data(i);
                    
                }
                break;
            }
            case 3:
            {
                print_by_age();
                break;
            }
            case 4:
            {
                print_count_by_gender();
                break;
            }
            case 0:
            {
                cout << "Exiting the program";
            }
            default:
            {
                cout << "\nError : Invalid Selection\nPlease Enter a choice from above only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
            }
            }
        }

    } while (1);

    return 0;
}
