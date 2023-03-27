#include<fstream>
#include<string>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;
struct date{int dd,mm,yy;};
int geneno();
int valp(char n[])
{
	int f=1;
   for(int k=0;k<10&&(f);k++)
   	if(!(n[k]>='0'&&n[k]<='9'))
      	f=0;
   return f;
}


void valnod(int n, int m,int y)
{
	int md;
   switch(m)
   {
   	case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:md=31;break;
      case 4:
      case 6:
      case 9:
      case 11:md=30;break;
      case 2:
      if(y%4==0&&y%100!=0||y%400==0)
      	md=29;
      else
      	md=28;
      break;
   }
   int vnod;
   if(n<0||n>md)
   {
   	cout<<"Invalid no. of days.Input valid no. of days?";cin>>vnod;
      valnod(vnod,m,y);
   }                   
}

class emp
{
	char des[10];
	int eno;
   char name[20];
   char sex;
   char pno[10];
	date dob,doj;
   char mno[10];
	double bsal;
	char add[12];
   public:
   emp() {

   }
   private:
      void _getNumber(char temp[], char* inputMessage, char* invalidMessage)
      {
         int valid = 0;
         do {
				cout<<inputMessage;
            cin>>temp;
				valid = valp(temp);
            if(!valid) {
               cout<<invalidMessage;
            }
         } while(!valid);
      }
   public:
      void min() {
         _getNumber(mno, "Input mobile number?", "Invalid mobile number.Again,");

      }

      void nmin() {
         _getNumber(mno, "Input new mobile number?", "Invalid mobile number.Again,");

      }

      void npin() {
         _getNumber(pno, "Input new phone number?", "Invalid phone number.Again,");

      }
           
      void pin() {
         _getNumber(pno, "Input phone number?", "Invalid phone number.Again,");

      }
      void bdatin(date dob)
      {
      	cout<<"Input Date of Birth(Example:If the date is 22 March,1997,enter";
         cout<<" 22)?";
   		cin>>dob.dd;
   		cout<<"Input Month of Birth?";cin>>dob.mm;
   		cout<<"Input Year of Birth?";cin>>dob.yy;
         int md;
   		switch(dob.mm)
   		{
   			case 1:
      		case 3:
      		case 5:
      		case 7:
      		case 8:
      		case 10:
      		case 12:md=31;break;
            case 4:
      		case 6:
      		case 9:
      		case 11:md=30;break;
      		case 2:
      		if(dob.yy%4==0&&dob.yy%100!=0||dob.yy%400==0)
      			md=29;
      		else
      		md=28;
      	break;
   		}
   		date nd;
   		if(!(dob.dd>=1&&dob.dd<=md&&dob.mm>0&&dob.mm<=12))
   		{
   			cout<<"Invalid date.Again,";
            bdatin(dob);

   		}
      }

      void jdatin(date doj)
      {
      	cout<<"Input Date of Join(Example:If the date is 22 March,1997,enter";
         cout<<" 22)?";
   		cin>>doj.dd;
   		cout<<"Input Month of Join?";cin>>doj.mm;
   		cout<<"Input Year of Join?";cin>>doj.yy;
         int md;
   		switch(doj.mm)
   		{
   			case 1:
      		case 3:
      		case 5:
      		case 7:
      		case 8:
      		case 10:
      		case 12:md=31;break;
            case 4:
      		case 6:
      		case 9:
      		case 11:md=30;break;
      		case 2:
      		if(doj.yy%4==0&&doj.yy%100!=0||doj.yy%400==0)
      			md=29;
      		else
      		md=28;
      	break;
   		}
   		date nd;
   		if(!(doj.dd>=1&&doj.dd<=md&&doj.mm>0&&doj.mm<=12))
   		{
   			cout<<"Invalid date.Again,";
            jdatin(doj);

   		}
      }


      void empin()
      {
      	cout<<"Enter name?";
        	gets(name);
         eno=geneno();
   		cout<<"Input sex[ 'M' for male, 'F' for female]?";
         cin>>sex;
   		bdatin(dob);
   		jdatin(doj);
   		cout<<"Input designation?";
         gets(des);
   		cout<<"Input basic salary?";
         cin>>bsal;
         pin();
   		min();
   		cout<<"Input address?";
         gets(add);

      }
      //Display:
   	void empdisplay()
     	{
   	  	cout<<"Employee Number="<<eno<<endl;
      	cout<<"Name="<<name<<endl;
      	cout<<"Designation="<<des<<endl;
         cout<<"Sex="<<sex<<endl;
      	cout<<"Date of Birth="<<dob.dd<<"/"<<dob.mm<<"/"<<dob.yy<<endl;
      	cout<<"Date of Joining="<<doj.dd<<"/"<<doj.mm<<"/"<<doj.yy<<endl;
      	cout<<"Basic Salary="<<bsal<<endl;
      	cout<<"Phone Number="<<pno<<endl;
      	cout<<"Mobile Number="<<mno<<endl;
      	cout<<"Address="<<add<<endl;
   	}
      void dis1()
      {
      	double gross=bsal+.55*bsal+.35*bsal+.15*bsal;
         double ded=0;
         double net=gross-ded;
         cout<<"-------------------------------";
         cout<<"-------------------------------------------------"<<endl;
         cout<<"ENo   Name             Designation    Basic     Gross       ";
         cout<<"Deduction    Net"<<endl;
         printf("%5i %-17s %-14s %-10.2lf %-10.2lf %-10.2lf %-8.2lf",eno,name,des,bsal,
         gross,ded,net);
         cout<<endl;
         cout<<"------------------------------";
         cout<<"-----------------------------------------------"<<endl;
      }
      //Return:
   	char* retname()
   	{
   		return name;
   	}
   	int reteno()
   	{
   		return eno;
   	}
      char* retdes()
      {
      	return des;
      }
      //Edit:
   	void eddes(char* desi)
   	{
   		//strcpy(des1,desi);
   	}
   	void edsex(char s)
   	{
   		sex=s;
   	}
   	void eddob(date d)
   	{
   		dob=d;
   	}
   	void eddoj(date d)
   	{
   		doj=d;
   	}
   	void edbsal(double b)
   	{
   		bsal=b;
   	}
   	void edadd(char* a)
   	{
   	//	strcpy(add,a);
   	}

};
int geneno()
{
   emp a;
   int en, len=sizeof(emp);
   ifstream fin("emp.txt");
   if (!fin)
   	en=0;
   else
   {
      fin.seekg(0, ios::end);
      int n=fin.tellg()/len;
      if (n==0)
         en=0;
      else
      {
         fin.seekg(len*(n-1), ios::beg);
         fin.read((char*)&a, sizeof(a));
         en=a.reteno();
      }
   }
   fin.close();
   return en + 1;
}
class mpay
{
	int eno;
   char name[35];
   int yr;
   int mon;
   int nod;
   double basic;
   double da;
   double hra;
   double con;
   double gross;
   double ded;
   double net;
   public:
    	void  calsal()
      {
      	double maxdays;
         switch(mon)
         {
         	case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12: {
               maxdays=31;
               break;
            }
            case 4:
            case 6:
            case 9:
            case 11: {
               maxdays=30;
               break;
            }
            case 2: {
            	if(yr%4==0&&yr%100!=0||yr%400==0)
               	maxdays=29;
               else
               	maxdays=28;
            }
         }
         basic*=nod/maxdays;
         da=.55*basic;
         hra=.35*basic;
         con=.15*basic;
         gross=basic+da+hra+con;
         ded=0;
         net=gross-ded;
      }
      void mpayin()
      {
      	cout<<"Input Employee Number?";
         cin>>eno;
   		cout<<"Input Employee name?";
         gets(name);
   		cout<<"Input Month[1-12]?";
         cin>>mon;
   		cout<<"Input Year?";
         cin>>yr;
   		cout<<"Input number of days worked?";
         cin>>nod;
         valnod(nod,mon,yr);
   		cout<<"Input Basic Salary?";
         cin>>basic;
   		calsal();
      }
   		void dis2()
      	{
            cout<<"--------------------------------------------------";
         	cout<<"------------------------------"<<endl;
         	cout<<"Salary slip for the month of:"<<this->mon<<" "<<this->yr<<endl;
         	cout<<"Employee No:"<<this->eno<<"                                     ";
         	cout<<"Employee Name:"<<this->name<<endl;
         	cout<<"--------------------------------------------------";
         	cout<<"------------------------------"<<endl;
         	cout<<"Basic         "<<this->basic<<"                                ";
         	cout<<"      "<<"Deductions    "<<ded<<endl;
         	cout<<"DA            "<<this->da<<endl;
         	cout<<"HRA           "<<this->hra<<endl;
         	cout<<"Conveyance    "<<this->con<<endl;
         	cout<<"--------------------------------------------------";
         	cout<<"------------------------------"<<endl;
         	cout<<"Gross Pay     "<<this->gross<<"                                 ";
         	cout<<"      "<<"Net           "<<this->net<<endl;
      	}
};
void addRecSingle() {
	ofstream f("emp.txt",ios::out|ios::app);
	emp a;
   a.empin();
   f.write((char*)&a,sizeof(a));
   f.close();
}
void adrec()
{
   int n;
   cout<<"Input no. of records to be added?";
   cin>>n;

   for(int k=0;k<n;k++)
   {
       addRecSingle();
   }
}
void mod()
{
	int f=0;
   char c;
   cout<<"Do you want to specify the employee whose records are to be";
   cout<<" modified by Employee No. or by Employee Name?"<<endl;
   cout<<"Press 'A' for Employee Name"<<endl;
   cout<<"Press 'B' for Employee No."<<endl;
   cin>>c;
	if(c=='A')
   {
   	emp a;
      char name[35],o;
      cout<<"Input name?";
      gets(name);
      cout<<"Input what you want to modify"<<endl;
      cout<<"'D' for Designation"<<endl;
      cout<<"'B' for Date of Birth"<<endl;
      cout<<"'J' for Date of Joining"<<endl;
      cout<<"'S' for Sex"<<endl;
      cout<<"'L' for bsal"<<endl;
      cout<<"'P' for Phone Number"<<endl;
      cout<<"'M' for Mobile Number"<<endl;
      cout<<"'A' for Address"<<endl;
      cin>>o;
      ifstream fin("emp.txt");
      ofstream fout("temp.txt",ios::out|ios::app);
      switch (o)
      {
      	case 'D':
         {
         	char d[35];
         	cout<<"Input new Designation?";
            gets(d);
           /* while(fin.read((char*)&a,sizeof(a)))
         	{
         		if(strcmp(a.retname(),name)==0)
         		{
         			a.eddes(d);
            		f=1;
               }
               fout.write((char*)&a,sizeof(a));
            } */
         }
         break;
         case 'B':
         {
         	date d;
         	cout<<"Input Date of Birth(Example:If the date is 22 March,1997,";
            cout<<"enter 22)?";
   			cin>>d.dd;
   			cout<<"Input Month of Birth?";cin>>d.mm;
   			cout<<"Input Year of Birth?";cin>>d.yy;
            a.bdatin(d);
            while(fin.read((char*)&a,sizeof(a)))
         	{
         		if(strcmp(a.retname(),name)==0)
         		{
         			a.eddob(d);
            		f=1;
               }
               fout.write((char*)&a,sizeof(a));
            }
         }
         break;
         case 'J':
         {
         	date d;
         	cout<<"Input Date of Join(Example:If the date is 22 March,1997,";
            cout<<"enter 22)?";
   			cin>>d.dd;
   			cout<<"Input Month of Join?";cin>>d.mm;
   			cout<<"Input Year of Join?";cin>>d.yy;
            a.jdatin(d);
            while(fin.read((char*)&a,sizeof(a)))
         	{
         		if(strcmp(a.retname(),name)==0)
         		{
         			a.eddoj(d);
            		f=1;
               }
               fout.write((char*)&a,sizeof(a));
            }
         }
         break;
         case 'S':
         {
         	char d;
         	cout<<"Input new Sex?";cin>>d;
            while(fin.read((char*)&a,sizeof(a)))
         	{
         		if(strcmp(a.retname(),name)==0)
         		{
         			a.edsex(d);
            		f=1;
               }
               fout.write((char*)&a,sizeof(a));
            }
         }
         break;
         case 'L':
         {
         	double d;
         	cout<<"Input new Basic Salary?";cin>>d;
            while(fin.read((char*)&a,sizeof(a)))
         	{
         		if(strcmp(a.retname(),name)==0)
         		{
         			a.edbsal(d);
            		f=1;
               }
               fout.write((char*)&a,sizeof(a));
            }
         }
         break;
         case 'P':
         {
         	char d[11];
         	while(fin.read((char*)&a,sizeof(a)))
         	{
         		if(strcmp(a.retname(),name)==0)
         		{
         			a.npin();
            		f=1;
               }
               fout.write((char*)&a,sizeof(a));
            }
         }
         break;
         case 'M':
         {
         	char d[11];
         	while(fin.read((char*)&a,sizeof(a)))
         	{
         		if(strcmp(a.retname(),name)==0)
         		{
         			a.nmin();
            		f=1;
               }
               fout.write((char*)&a,sizeof(a));
            }
         }
         break;
         case 'A':
         {
         	char d[45];
         	cout<<"Input new Address?";
            gets(d);
            while(fin.read((char*)&a,sizeof(a)))
         	{
         		if(strcmp(a.retname(),name)==0)
         		{
         			a.edadd(d);
            		f=1;
               }
               fout.write((char*)&a,sizeof(a));
            }
         }
         break;
      }
      fin.close();
      fout.close();
	}
   if(c=='B')
   {
   	int eno;
      emp a;
      char name[35],o;
      cout<<"Input Employee Number?";cin>>eno;
      cout<<"Input what you want to modify"<<endl;
      cout<<"'D' for Designation"<<endl;
      cout<<"'B' for Date of Birth"<<endl;
      cout<<"'J' for Date of Joining"<<endl;
      cout<<"'S' for Sex"<<endl;
      cout<<"'L' for bsal"<<endl;
      cout<<"'P' for Phone Number"<<endl;
      cout<<"'M' for Mobile Number"<<endl;
      cout<<"'A' for Adress"<<endl;
      cin>>o;
      ifstream fin("emp.txt");
      ofstream fout("temp.txt",ios::out|ios::app);
      switch (o)
      {
      	case 'D':
         {
         	char d[35];
         	cout<<"Input new Designation?";
            gets(d);
            while(fin.read((char*)&a,sizeof(a)))
         	{
         		if(a.reteno()==eno)
         		{
         			a.eddes(d);
            		f=1;
               }
               fout.write((char*)&a,sizeof(a));
            }
         }
         break;
         case 'B':
         {
         	date d;
         	cout<<"Input new Day of Birth[Example:If date is 22 March 1997, ";
            cout<<"input 22]?";cin>>d.dd;
            cout<<"Input new month of joining?";cin>>d.mm;
            cout<<"Input new year of joining?";cin>>d.yy;
            while(fin.read((char*)&a,sizeof(a)))
         	{
         		if(a.reteno()==eno)
         		{
         			a.eddob(d);
            		f=1;
               }
               fout.write((char*)&a,sizeof(a));
            }
         }
         break;
         case 'J':
         {
         	date d;
         	cout<<"Input new Day of Birth[Example:If date is 22 March 1997, ";
            cout<<"input 22]?";cin>>d.dd;
            cout<<"Input new month of joining?";cin>>d.mm;
            cout<<"Input new year of joining?";cin>>d.yy;
            while(fin.read((char*)&a,sizeof(a)))
         	{
         		if(a.reteno()==eno)
         		{
         			a.eddoj(d);
            		f=1;
               }
               fout.write((char*)&a,sizeof(a));
            }
         }
         break;
         case 'S':
         {
         	char d;
         	cout<<"Input new Sex?";cin>>d;
            while(fin.read((char*)&a,sizeof(a)))
         	{
         		if(a.reteno()==eno)
         		{
         			a.edsex(d);
            		f=1;
               }
               fout.write((char*)&a,sizeof(a));
            }
         }
         break;
         case 'L':
         {
         	double d;
         	cout<<"Input new Basic Salary?";cin>>d;
            while(fin.read((char*)&a,sizeof(a)))
         	{
         		if(a.reteno()==eno)
         		{
         			a.edbsal(d);
            		f=1;
               }
               fout.write((char*)&a,sizeof(a));
            }
         }
         break;
         case 'P':
         {
         	char d[11];
            while(fin.read((char*)&a,sizeof(a)))
         	{
         		if(a.reteno()==eno)
         		{
         			a.npin();
            		f=1;
               }
               fout.write((char*)&a,sizeof(a));
            }
         }
         break;
         case 'M':
         {
         	char d[11];
         	while(fin.read((char*)&a,sizeof(a)))
         	{
         		if(a.reteno()==eno)
         		{
         			a.nmin();
            		f=1;
               }
               fout.write((char*)&a,sizeof(a));
            }
         }
         break;
         case 'A':
         {
         	char d[45];
         	cout<<"Input new Address?";
            gets(d);
            while(fin.read((char*)&a,sizeof(a)))
         	{
         		if(a.reteno()==eno)
         		{
         			a.edadd(d);
            		f=1;
               }
               fout.write((char*)&a,sizeof(a));
            }
         }
         break;
      }
      fin.close();
   	fout.close();
   }


   remove("emp.txt");
   rename("temp.txt","emp.txt");
   if(f!=0)
   	cout<<"Record modified"<<endl;
   else
   	cout<<"Record not found"<<endl;
}
void srch()
{
	char c;
   cout<<"Input what basis you want to search on:"<<endl;
   cout<<"Press 'N' for Employee Name"<<endl;
   cout<<"Press 'U' for Employee Number"<<endl;
   cin>>c;
   int f=0;
   switch(c)
   {
   	case 'N':
      {
      	emp a;
      	char n[35];
         ifstream fin("emp.txt");
         cout<<"Input name?";
         gets(n);
         while(fin.read((char*)&a,sizeof(a)))
         {
         	if(strcmp(a.retname(),n)==0)
            {
            	f=1;
               a.empdisplay();
            }
         }
         fin.close();
      }

  	 	break;
   	case 'U':
   	{
      	emp a;
      	int e;
         ifstream fin("emp.txt");
         cout<<"Input eno?";cin>>e;
         while(fin.read((char*)&a,sizeof(a)))
         {
         	if(a.reteno()==e)
            {
            	f=1;
               a.empdisplay();
            }
         }
         fin.close();
      }
      break;
   }
   if(f)
   	cout<<"Search successful"<<endl;
   else
   	cout<<"Search not successful"<<endl;
}
void in()
{
ofstream fout("mpay.txt",ios::out|ios::app);
 mpay a;
   a.mpayin();

   fout.write((char*)&a,sizeof(a));
   fout.close();
}
void rep()
{
   int c;
	cout<<"1)Details of each Employee from Employee File"<<endl;
   cout<<"2)Salary statement"<<endl;
   cout<<"3)Salary Slip"<<endl;
   cout<<"Input choice[1-3]?";cin>>c;
   switch(c)
   {
   	case 1:
      {
      	emp a;
   		ifstream fin ("emp.txt");
   		while(fin.read((char*)&a,sizeof(a)))
   			a.empdisplay();
   		fin.close();
   		break;
      }
      case 2:
      {
      	emp a;
   		ifstream fin ("emp.txt");
   		while(fin.read((char*)&a,sizeof(a)))
   			a.dis1();
   		fin.close();
   		break;
      }
      case 3:
      {
      	mpay a;
   		ifstream fin ("mpay.txt");
         while(fin.read((char*)&a,sizeof(a)))  {
            a.dis2();
         }
         fin.close();
   		break;
      }

      default:cout<<"Invalid choice"<<endl;
   }
}



void main()
{
	int ch;
   do
   {
   	  cout<<"1. Addition of records for new Employees in Employee File"<<endl;
   	  cout<<"2. Modification of existing records in Employee File except ";
   	  cout<<"Employee No and Employee Name"<<endl;
      cout<<"3. Searching in Employee Fileusing following fields: ";
      cout<<"Employee Number, Employee Name"<<endl;
      cout<<"4. Input of number of days worked and other deductions of each ";
      cout<<"employee in Monthly Pay File"<<endl;
      cout<<"5. Report (Screen/Printer)"<<endl;
      cout<<"0. Exit from menu"<<endl;
      cout<<"Enter choice[0-5]?";
      cin>>ch;
      switch(ch)
      {
      	case 1:adrec(); break;
         case 2:mod();break;
         case 3:srch();break;
         case 4:in();break;
         case 5:rep();break;
         default:cout<<"Invalid Input"<<endl;
      }
      cout<<endl;
   }
   while(ch);
   getch();
}
