//Header Files
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<iomanip>
#include<fstream>
#include<cstring>

//Function Declaration
void menu();
void passcode();
void cpasscode();
using namespace std;

//Class One
class one{
     public:
     virtual void get()=0;
     virtual void show()=0;
};

//Class Information
class info:public one
{
    public:
    char name[50],time[50];
    int age,num;
    void get()
         {
         system("cls");
         cin.sync();
         cout<<"\n Enter Patient Name:";
         cin.getline(name,50);
         cout<<"\n Enter the Appointment Time:";
         cin.getline(time,50);
         cout<<"\n Enter age:";
         cin>>age;
         cout<<"\n Enter Appointment number:";
         cin>>num;
         }
    void show()
         {
         cout<<"\n Name:"<<name;
         cout<<"\n Age:"<<age;
         cout<<"\n Appointment time:"<<time;
         cout<<"\n Appointment number:"<<num;
         }
};

//Class Dr.Krithik
class Krithik:public info
{
public:
    info a1;
    void get()
    {
        system("cls");
        ofstream out("Krithik.txt",ios::app|ios::binary);
        a1.get();
        out.write((char*)&a1,sizeof(info));
        out.close();
        cout<<"Your entry has been saved";
        getch();
        menu();
    }
    void show()
    {
        ifstream in("krithik.txt");
            while(!in.eof())
            {
                in.read((char*)&a1,sizeof(a1));
                a1.show();
            }
            in.close();
            getch();
            menu();
    }
};

//Class Dr.Keerthan
class Keerthan:public info
{
public:
    info a1;
    void get()
    {
        system("cls");
        ofstream out("Keerthan.txt",ios::app|ios::binary);
        a1.get();
        out.write((char*)&a1,sizeof(info));
        out.close();
        cout<<"Your entry has been saved";
        getch();
        menu();
    }
    void show()
    {
        ifstream in("Keerthan.txt");
            while(!in.eof())
            {
                in.read((char*)&a1,sizeof(a1));
                a1.show();
            }
            in.close();
            getch();
            menu();
    }
};

//Class Dr.Kanchana
class Kanchana:public info
{
public:
    info a1;
    void get()
    {
        system("cls");
        ofstream out("Kanchana.txt",ios::app|ios::binary);
        a1.get();
        out.write((char*)&a1,sizeof(info));
        out.close();
        cout<<"Your entry has been saved";
        getch();
        menu();
    }
    void show()
    {
        ifstream in("Kanchana.txt");
            while(!in.eof())
            {
                in.read((char*)&a1,sizeof(a1));
                a1.show();
            }
            in.close();
            getch();
            menu();
    }
};

//Class staff
class staff:public one
{
public:
    char all[999];
    char name[50],age[20],sal[30],pos[20];
    void get()
    {
        ofstream out("staff.txt",ios::app);
        {
            system("cls");
            cin.sync();
            cout<<"\nEnter name:";
            cin.getline(name,50);
            cout<<"\nEnter age:";
            cin.getline(age,20);
            cout<<"\nEnter salary:";
            cin.getline(sal,30);
            cout<<"\nEnter working position:";
            cin.getline(pos,20);
        }
        out<<"\nName:"<<name<<"\nAge:"<<age<<"\nSalary:"<<sal<<"\nPosition:"<<pos;
        out.close();
        cout<<"\n\nYour information has been saved:\n\n\t\tPress any key to continue:";
        getch();
        menu();
    }
    void show()
    {
        ifstream in("staff.txt");
        if(!in)
        {
            cout<<"File open error";
        }
        while(!(in.eof()))
        {
            in.getline(all,999);
            cout<<all<<endl;
        }
        in.close();
        cout<<"\n\n\t\tPress any key to continue:";
        getch();
        menu();

    }
};

//Class information
class information
{
public:
    void drinfo()
    {
        system("cls");
        system("color F3");
        cout<<"\n=============================================\n";
        cout<<"\n\n\t\t(Three Doctors Available)\n\n\t\t[Information and timing are given below]\n";
        cout<<"-----------------------------------------------\n";
        cout<<"\t\tDr Available:\n";
        cout<<"\t\tDr. Krithik(skin specialist)\n\n";
        cout <<"\t\t\t[[Timing]]:\n\n";
        cout<<"\tMonday to Friday\t\t9AM TO 5PM\n";
        cout<<"\tSaturday        \t\t9AM TO 1PM\n";
        cout<<"\tSunday          \t\tOFF\n";
        cout<<"-----------------------------------------------\n";
        cout<<"\t\tDr. Keerthan(Bone specialist)\n\n";
        cout <<"\t\t\t[[Timing]]:\n\n";
        cout<<"\tMonday to Friday\t\t1PM TO 10PM\n";
        cout<<"\tSaturday        \t\t8AM TO 1PM\n";
        cout<<"\tSunday          \t\t10AM TO 12PM\n";
        cout<<"-----------------------------------------------\n";
        cout<<"\t\tDr. Kanchana(child specialist)\n\n";
        cout <<"\t\t\t[[Timing]]:\n\n";
        cout<<"\tMonday to Friday\t\t8AM TO 5PM\n";
        cout<<"\tSaturday        \t\t10AM TO 1PM\n";
        cout<<"\tSunday          \t\tOFF\n";
        cout<<"-----------------------------------------------\n";
        cout<<"\nPress any key to continue:";
        getch();
        menu();
    }
};

//Call doctor
void call_dr()
{
    system("cls");
    int choice;
    cout<<"\n\n\n\t\tPress 1 for Dr.Krithik\n\n\t\tPress 2 for Dr.Keerthan \n\n\t\tPress 3 for Dr.Kanchana";
    cin>>choice;

    one *ptr;
    Krithik s3;
    Keerthan s4;
    Kanchana s5;
    if(choice==1)
    {
        ptr=&s3;
        ptr->get();
    }
    else if(choice==2)
    {
        ptr=&s4;
        ptr->get();
    }
    else if(choice==3)
    {
        ptr=&s5;
        ptr->get();
    }
    else
    {
        cout<<"Sorry invalid choice:";
        getch();
        menu();
    }
}

void pinfoshow()
{
    system("cls");
    int choice;
    cout<<"\n\n\n\t\tPress 1 for Dr.Krithik\n\n\t\tPress 2 for Dr.Keerthan \n\n\t\tPress 3 for Dr.Kanchana";
    cin>>choice;

    one *ptr;
    Krithik s3;
    Keerthan s4;
    Kanchana s5;
    if(choice==1)
    {
        ptr=&s3;
        ptr->get();
    }
    else if(choice==2)
    {
        ptr=&s4;
        ptr->get();
    }
    else if(choice==3)
    {
        ptr=&s5;
        ptr->get();
    }
    else
    {
        cout<<"Sorry invalid choice:";
        getch();
        menu();
    }
}

void menu()
{
    system("cls");
    system("color FC");
    cout<<"\n\n";
    cout<<"\t\t   |+++++ MAIN MENU +++++|\n";
    cout<<"\t\t   | HOSPITAL MANAGEMENT |\n";
    cout<<"\t\t   |=====================|\n";
    cout<<"\n----------------------------------------\n";
    cout<<"\t\t     Please select any option     \n";

    cout<<"\n\n\t1-\t\t Press 1 for available doctor information\n\n";
    cout<<"\t2-\t\tPress 2 for Doctor Appointment\n\n";
    cout<<"\t3-\t\tPress 3 to save staff information\n\n";
    cout<<"\t4-\t\tPress 4 for patient appointment menu:\n\n";
    cout<<"\t5-\t\tPress 5 for staff information menu:\n\n";
    cout<<"\t6-\t\tPress 6 to change or create password\n\n";
    cout<<"\t7-\t\tPress 7 to Logout\n\n";

    cout<<"==========================================\n";
    cout<<"\n\n\t\tPlease enter your choice:";
    information a1;
    one *ptr;
    staff a2;
    int a;
    cin>>a;
    if(a==1)
    {
        a1.drinfo();
    }
    else if(a==2)
    {
        call_dr();
    }
    else if(a==3)
    {
        ptr=&a2;
        ptr->get();
    }
    else if(a==4)
    {
        pinfoshow();
    }
    else if(a==5)
    {
        ptr=&a2;
        ptr->get();
    }
    else if(a==6)
    {
        cpasscode();
    }
    else if(a==7)
    {
        passcode();
    }
    else
    {
        cout<<"Sorry invalid choice:";
    }
}

void passcode()
{
    system("cls");
    char p1[50],p2[50],p3[50];
    system("color Fc");
    ifstream in("password.txt");
    {
        cin.sync();
        cout<<"\n\n\n\n\n\n\t\tEnter the Password:";
        cin.getline(p1,50);
        in.getline(p2,50);
        if(strcmp(p1,p2)==0)
        {
            menu();
        }
        else
        {
            cout<<"\n\n\t\tIncorrect Password";
            Sleep(999);
            passcode();
        }
    }
    in.close();
}

void cpasscode()
{
    char n[50];
    system("cls");
    ofstream out("password.txt");
    {
        cin.sync();
        cout<<"\n\n\n\n\t\tEnter new password";
        cin.getline(n,50);
        out<<n;
    }
    out.close();
    cout<<"\n\nYour Password has been saved:";
    getch();
    menu();
}

int main()
{
    passcode();
    system("pause");
}
