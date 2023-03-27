#include<fstream>
#include<ctype.h>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h >
using namespace std;


//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class EMPLOYEE
{
	int emp_code;
	char emp_name[50],desig[50],dept[50],dob[20],doj[20],month[20];
	char address[50], contact[20];
	int bank_acc,cl,medleave;
	float basic,da,hra,med,pf,gross,net;
public:
	void create_emp();		//function to add a new employee
	void show_emp();		//function to show employee information on screen
	void create_salary();  // function to add salary information of an employee
	void search_pay(); 		 //  searching pay slip
	int  getcode() 			   
		{ return emp_code; }

};         //class ends here

void EMPLOYEE::create_emp()
{
	cout<<"\n\t Enter The Employee Code:";
	cin>>emp_code;
	cout<<"\n\n\tEnter The Employee Name : ";
	gets(emp_name);
	cout<<"\n\n\tEnter The Department : ";
	gets(dept);
	cout<<"\n\n\tEnter The Designation : ";
	gets(desig);
	cout<<"\n\n\tEnter The Date of Birth(mm/dd/yyyy) : ";
	gets(dob);
	cout<<"\n\n\tEnter The Date of Join	(mm/dd/yyyy) : ";
	gets(doj);
	cout<<"\n\n\tEnter The Address : ";
	gets(address);
	cout<<"\n\n\tEnter The Contact Number : ";
	gets(contact);
	cout<<"\n\n\nNew Employee Added To The System....";
}

void EMPLOYEE::show_emp()
{
cout<<emp_code<<" "<<emp_name<<" "<<dept<<" "<<desig<<" "<<dob<<"\n\n";
cout<<doj<<" "<<address<<" "<<contact<<"\n\n";
}

void EMPLOYEE::create_salary()
{
cout<<"\n\tEnter The Employee Code:";
cin>>emp_code;
cout<<"\n\tEnter The Bank Account No:";
cin>>bank_acc;
cout<<"\n\tEnter The Month :";
gets(month);
cout<<"\n\tEnter No Of Casual Leaves Taken:";
cin>>cl;
cout<<"\n\tEnter No Of Medical Leaves Taken:";
cin>>medleave;
cout<<"\n\tEnter The Basic Salary:";
cin>>basic;
cout<<"\n\n\nSalary Credited To"<<" "<<"Account Number:"<<" "<<bank_acc;
}

void EMPLOYEE:: search_pay() {
float temp=0;
da=basic*105.0/100;
hra=basic*30.0/100;
med=200;
pf=3000;
gross=basic+da+hra+med;
if(cl>1)
temp+=cl*gross/30;
if(medleave>3)
temp+=medleave*gross/30;
net=gross-pf-temp;
cout<<"\n\n\t===================PAY SLIP FOR"<<" "<<emp_code<<" "<<"in"<<" "<<strupr(month)<<"==============\n\n";
cout<<"1) BASIC = RS. "<<" "<<basic<<"\n\n";
cout<<"2) DA = RS. "<<" "<<da<<"\n\n";
cout<<"3) HRA = RS. "<<" "<<hra<<"\n\n";
cout<<"4) MEDICAL = RS. "<<" "<<med<<"\n\n";
cout<<"5) GROSS = RS. "<<" "<<gross<<"\n\n";
cout<<"6) PF DEDUCTION = RS. "<<" "<<pf<<"\n\n";
cout<<"7) LEAVE DEDUCTION = RS. "<<" "<<temp<<"\n\n";
cout<<"===============================================================================================================\n\n\n";
cout<<"NET SALARY =RS. "<<" "<<net<<"\n\n";
}
//***************************************************************
//    	function declaration
//****************************************************************
void write_emp();	//function to write record in binary file
void write_sal();	 // function to credit salary details
void search_emp(int);	//function to search an employee based on emp code
void pay_slip(int);	   //function to generate slip
void remove_emp(int);	// function to remove employee
void intro();	//introductory screen function

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************


int main()
{
	char ch;
	int n;
	system("cls");
	intro();
	do
	{
		system("cls");
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. ADD NEW EMPLOYEE";
		cout<<"\n\n\t02. ADD SALARY DETAILS";
		cout<<"\n\n\t03. SEARCH AN EMPLOYEE";
		cout<<"\n\n\t04. VIEW PAY SLIP ";
		cout<<"\n\n\t05. REMOVE EMPLOYEE";
		cout<<"\n\n\t06. EXIT";
		cout<<"\n\n\tSelect Your Option (1-6) ";
		cin>>ch;
		system("cls");
		switch(ch)
		{
		case '1':
			write_emp();
			break;
		case '2':
			write_sal();
			break;
		case '3':
			cout<<"\n\n\tEnter The Employee Code:";
			cin>>n;
			search_emp(n);
			break;
		case '4':
			cout<<"\n\n\tEnter The Employee Code:";
			cin>>n;
			pay_slip(n);
			break;
		case '5':
			cout<<"\n\n\tEnter The Employee Code:";
			cin>>n;
			remove_emp(n);
			break;
		 case '6':
			cout<<"\n\n\tTHANK YOU FOR USING PAYROLL MANAGEMENT SYSTEM\n\n\n";
			break;
		 default :cout<<"\a";
		}
		getch();
	}while(ch!='6');

}


//***************************************************************
//    	function to write in file
//****************************************************************

void write_emp()
{
	EMPLOYEE ac;
	ofstream outFile;
	outFile.open("emp.dat",ios::binary|ios::app);
	ac.create_emp();
	outFile.write((char *) &ac, sizeof(EMPLOYEE));
	outFile.close();
}





//***************************************************************
//    	function to write salary details
//****************************************************************

void write_sal()
{
	EMPLOYEE ac;
	ofstream outFile;
	outFile.open("salary.dat",ios::binary|ios::app);
	ac.create_salary();
	outFile.write((char *) &ac, sizeof(EMPLOYEE));
	outFile.close();
}


//***************************************************************
//    	function to read specific record from file
//****************************************************************

void search_emp(int n)
{
	EMPLOYEE ac;
	int flag=0;
	ifstream inFile;
	inFile.open("emp.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
		 cout<<"\n\n==========================================================================\n\n";
		cout<<"Emp Code"<<" "<<"Emp Name"<<" "<<"Department"<<" "<<"Designation"<<"\n\n";
		cout<<"Date Of Birth"<<" "<<"Date of Join"<<" "<<"Address"<<" "<<"Contact No"<<"\n\n";
		cout<<"\n\n==========================================================================\n\n";
	while(inFile.read((char *) &ac, sizeof(EMPLOYEE)))
	{
		if(ac.getcode()==n)
		{
			ac.show_emp();
			flag=1;
		}
	}
	inFile.close();
	if(flag==0)
		cout<<"\n\Wrong Employee Code Entered\n\n";
}


//***************************************************************
//    	function to generate Pay Slip
//****************************************************************

void pay_slip(int n)
{
	EMPLOYEE ac;
	int flag=0;
	ifstream inFile;
	inFile.open("salary.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}

	while(inFile.read((char *) &ac, sizeof(EMPLOYEE)))
	{
		if(ac.getcode()==n)
		{
			ac.search_pay();
			flag=1;
		}
	}
	inFile.close();
	if(flag==0)
		cout<<"\n\Wrong Employee Code Entered\n\n";
}


//***************************************************************
//    	function to delete record of file
//****************************************************************


void remove_emp(int n)
{
	EMPLOYEE ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("emp.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("newEmp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &ac, sizeof(EMPLOYEE)))
	{
			if(ac.getcode()!=n)
		{
			outFile.write((char *) &ac, sizeof(EMPLOYEE));
		}
	}
	inFile.close();
	outFile.close();
	remove("emp.dat");
	rename("newEmp.dat","emp.dat");
	cout<<"\n\n\tEmployee Removed From The Organisation....\n\n";
}


//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************


void intro()
{
	cout<<"\n\n\n\t PAYROLL";
	cout<<"\n\n\t MANAGEMENT";
	cout<<"\n\n\t  SYSTEM ";
	cout<<"\n\n\n\n MADE BY : SEC1 GROUP:1";
	getch();
}
