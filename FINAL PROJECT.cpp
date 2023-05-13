#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string> 
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

int stringToInt(std::string str) {
    int num;
    std::stringstream ss(str);
    ss >> num;
    return num;
}
struct Employee {
    string name;
    int age;
    int id;
    double salary;
    string position;
    double grossSalary, tax, netSalary, pension;
};
// Function to add a new employee
void addEmployee(Employee employees[], int& numEmployees) {
    string name, position;
    int age;
    double salary, grossSalary, tax, netSalary, pension,id ;
    cout << "Enter the employee's name: ";
    getline(cin, name);
    cout << "Enter the employee's ID: ";
    cin >> age;
    cout << "Enter the employee's age: ";
    cin >> age;
    cout << "Enter the employee's salary: ";
    cin >> salary;
    cin.ignore(); // ignore the newline character
    cout << "Enter the employee's position: ";
    getline(cin, position);

    // Calculate gross salary
    grossSalary = salary;

    // Calculate tax
    if(grossSalary < 600) {
        tax = 0;
    } else if(grossSalary > 601 && grossSalary <= 1650) {
        tax = 0.1 * grossSalary - 60;
    } else if(grossSalary > 1651 && grossSalary <= 3200) {
        tax = 0.15 * grossSalary - 142.5;
    } else if(grossSalary > 3201 && grossSalary <= 5250) {
        tax = 0.2 * grossSalary - 302.5;
    } else if(grossSalary > 5251 && grossSalary <= 7800) {
        tax = 0.25 * grossSalary - 565;
    } else if(grossSalary > 7801 && grossSalary <= 10900) {
        tax = 0.3 * grossSalary - 955;
    } else {
        tax = 0.35 * grossSalary - 1500;
    }

    // Calculate net salary
    netSalary = grossSalary - tax;
    
    // Calculate pension
    pension = 0.07 * grossSalary;

    Employee newEmployee;
    newEmployee.name = name;
    newEmployee.age = age;
    newEmployee.id = id;
    newEmployee.salary = salary;
    newEmployee.position = position;
    newEmployee.grossSalary = grossSalary;
    newEmployee.tax = tax;
    newEmployee.netSalary = netSalary;
    newEmployee.pension = pension;
    netSalary = grossSalary - ( tax + pension );
    cout << "\t############################\n";
    cout << "\t### Employee name:   " << name << endl;
    cout << "\t### Employee ID:     " << id << endl;
    cout << "\t### Employee age: " << age << endl;
    cout << "\t### Employee salary: " << salary << endl;
    cout << "\t### Gross Salary:    " << grossSalary << endl;
    cout << "\t### Tax:        " << tax << endl;
    cout << "\t### Pension:    " << pension << endl;
    cout << "\t### Net Salary:  " << netSalary << endl;
    cout << "\t############################\n";
    employees[numEmployees] = newEmployee;
    numEmployees++;

    cout << "Employee added successfully!" << endl;
}

// Function to modify an employee record
void modifyEmployee(Employee employees[], int numEmployees) {
    string name;
    bool employeeFound = false;
    
    cout << "Enter the name of the employee whose record you want to modify: ";
    getline(cin, name);
    
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].name == name) {
            employeeFound = true;
            cout << "Current information for " << employees[i].name << ":" << endl;
            cout << "Age: " << employees[i].age << endl;
            cout << "Salary: " << employees[i].salary << endl;
            cout << "Position: " << employees[i].position << endl;
            
            cout << "Enter the new age (or 0 to keep the current age): ";
            int age;
            cin >> age;
            if (age != 0) {
                employees[i].age = age;
            }
            
            cout << "Enter the new salary (or 0 to keep the current salary): ";
            double salary;
            cin >> salary;
            if (salary != 0) {
                employees[i].salary = salary;
            }
            cin.ignore(); // ignore the newline character
            
            cout << "Enter the new position (or press Enter to keep the current position): ";
            string position;
            getline(cin, position);
            if (position != "") {
                employees[i].position = position;
            }
            
            cout << "Employee record updated successfully!" << endl;
            break;
        }
    }
    
    if (!employeeFound) {
        cout << "Employee not found." << endl;
    }
}

// Function to calculate net salary
void calculateNetSalary(Employee employees[], int numEmployees) {
    string name;
    double grossSalary, tax, netSalary, pension;
    bool employeeFound = false;
    
    cout << "Enter the name of the employee: ";
    getline(cin, name);
    
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].name == name) {
            employeeFound = true;
            grossSalary = employees[i].salary;
            
            // Calculate tax
            if (grossSalary < 600) {
                tax = 0;
            } else if (grossSalary > 601 && grossSalary <= 1650) {
                tax = 0.1 * grossSalary - 60;
            } else if (grossSalary > 1651 && grossSalary <= 3200) {
                tax = 0.15 * grossSalary - 142.5;
            } else if (grossSalary > 3201 && grossSalary <= 5250) {
                tax = 0.2 * grossSalary - 302.5;
            } else if (grossSalary > 5251 && grossSalary <= 7800) {
                tax = 0.25 * grossSalary - 565;
            } else if (grossSalary > 7801 && grossSalary <= 10900) {
                tax = 0.3 * grossSalary - 955;
            } else {
                tax = 0.35 * grossSalary - 1500;
            }
            
            // Calculate pension
            pension = 0.07 * grossSalary;
            
            // Calculate net salary
            netSalary = grossSalary - (tax + pension);
            
            //Display net salary
            cout << "\t############################\n";
            cout << "\t###### Employee name: " << employees[i].name << endl;
            cout << "\t###### Employee ID: " << employees[i].id << endl;
            cout << "\t###### Gross Salary: " << grossSalary << endl;
            cout << "\t###### Tax: " << tax << endl;
            cout << "\t###### Pension: " << pension << endl;
            cout << "\t###### Net Salary: " << netSalary << endl;
            cout << "\t############################\n";
            
            break;
        }
    }
    
    if (!employeeFound) {
        cout << "Employee not found." << endl;
    }
}
// Function to delete an employee record
void deleteEmployee(Employee employees[], int& numEmployees) {
    string name;
    bool employeeFound = false;
    
    cout << "Enter the name of the employee you want to delete: ";
    getline(cin, name);
    
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].name == name) {
            employeeFound = true;
            for (int j = i; j < numEmployees - 1; j++) {
                employees[j] = employees[j + 1];
            }
            numEmployees--;
            
            cout << "Employee record deleted successfully!" << endl;
            break;
        }
    }
    
    if (!employeeFound) {
        cout << "Employee not found." << endl;
    }
}

// Function to display an employee record
void displayEmployee(Employee employees[], int numEmployees) {
    string name;
    bool employeeFound = false;
    
    cout << "Enter the name of the employee you want to display: ";
    getline(cin, name);
    
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].name == name) {
            employeeFound = true;
            cout << "Name: " << employees[i].name << endl;
            cout << "Age: " << employees[i].age << endl;
            cout << "Salary: " << employees[i].salary << endl;
            cout << "Position: " << employees[i].position << endl;
            
            break;
        }
    }
    
    if (!employeeFound) {
        cout << "Employee not found." << endl;
    }
}

// Function to display a list of employees
void displayEmployeeList(Employee employees[], int numEmployees) {
    for (int i = 0; i < numEmployees; i++) {
    	cout << "\t ####################################################"<<endl;
        cout << "\t ###### 	 Emp Name:   \t" << employees[i].name  << endl;
        cout << "\t ###### 	  position   \t"<< employees[i].position << endl;
        cout << "\t ###### 	 Emp Age:    \t" << employees[i].age << endl;
        cout << "\t ######   Salary:     \t"<<employees[i].salary<< endl;
        cout << "\t ###### 	 grosssalary \t"<< employees[i].grossSalary << endl;
        cout << "\t ###### 	 Tax:        \t" << employees[i].tax    << endl;
        cout << "\t ###### 	 Pension     \t"<<employees[i].pension <<endl;
        cout << "\t ###### 	 netsalary   \t"<<employees[i].netSalary<<endl;
    	cout << "\t ####################################################\n\t";
        cout << endl;
    }
    
    // Save the employee list to a file
    //ofstream outFile("employeeList.txt");
    ofstream outFile("employeeList.txt", std::ios_base::app);
    for (int i = 0; i < numEmployees; i++) {
        outFile << " Employee name " << employees[i].name << endl;
        outFile << " Employee age" << employees[i].age << endl;
        outFile << " Employee salary " <<employees[i].salary << endl;
        outFile << " Employee position "<<employees[i].position << endl; 
		outFile << " Employee grosssalary "<<employees[i].grossSalary<< endl; 
		outFile << " Employee tax "<<employees[i].tax<< endl;
		outFile << " Employee pension "<<employees[i].pension<< endl;
		outFile << " Employee netsalary "<<employees[i].netSalary<< endl;
		
		outFile << endl;
		
    }
    outFile.close();
    
    cout << "Employee list saved to employeeList.txt." << endl;
}

int main() {
    const int MAX_EMPLOYEES = 100;
    Employee employees[MAX_EMPLOYEES];
    int numEmployees = 0;
    int choice;
    
    do {
    	cout << "\n\t\t ###########********************************###########\n" ;
    	cout << "\t\t ###########********************************###########\n" ;
        cout << "\n\t\t ###########   	PAYROLL MANAGEMENT SYSTEM  ###########" << endl;
        cout << "\n\t\t ########### 1. ADD A NEW EMPLOYEE          ###########" << endl;
        cout << "\n\t\t ########### 2. MODIFY AN EMPLOYEE RECORD   ###########" << endl;
        cout << "\n\t\t ########### 3. DISPAY EMPLOYEE INFO        ###########" << endl;
        cout << "\n\t\t ########### 4. DELETE AN EMPLOYEE RECORD   ###########" << endl;
        cout << "\n\t\t ########### 5. DISPLAY AN EMPLOYEE RECORD  ###########" << endl;
        cout << "\n\t\t ########### 6. DISPLAY A LIST OF EMPLOYEES ###########" << endl;
        cout << "\n\t\t ####################### 7. EXIT  #####################" << endl;
        cout << "\n\t\t ######################################################" ;
    	cout << "\n\t\t ######################################################\n" ;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // ignore the newline character
        
        switch (choice) {
            case 1:
                addEmployee(employees, numEmployees);
                break;
            case 2:
                modifyEmployee(employees, numEmployees);
                break;
            case 3: {
               calculateNetSalary(employees, numEmployees);
                break;
            }
            case 4:
                deleteEmployee(employees, numEmployees);
                break;
            case 5:
                displayEmployee(employees, numEmployees);
                break;
            case 6:
                displayEmployeeList(employees, numEmployees);

                break;
            case 7:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
        
        cout << endl;
    } while (choice != 7);
    
    return 0;
}

