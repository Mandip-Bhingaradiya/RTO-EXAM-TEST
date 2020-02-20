/*
---------------------------------RTO Learning Licence App for India:---------------------------------------------

Here in this app first authorized user need to create his/her account and then he/she need to sign in into that
after applicants need to enter their details for the learning licence after that test will start here the passing
criteria is 11/15 when the applicant give 11 correct answer test will over and then he will able to generate his
Learning Licence copy.

------------------------------------------------------------------------------------------------------------------
*/


#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<ctime>
using namespace std;
class User
{
public:
    int a=0;
    string user;
    string password;

    int mainMenu(int &a,string &user,string &password)
    {
        cout<<endl;
        cout<<endl;
        cout<<endl;
        //this is the welcome tab is generated for to create or login the account
        cout<<"\t     *****************************************\n"<<"\t\t         RTO LICENCE EXAM TEST\n"<<"\t     *****************************************";
        cout<<endl;
        cout<<"\n\t     Welcome to RTO licence Theory exam test\n";
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"\t     Please select an option from the given menu\n\n";
        cout<<"\t     1. Login\n";
        cout<<"\t     2. Create a new Account\n";
        cout<<"\t     3. Rules\n";
        cout<<endl;
        cout<<"\t     Please select your choice: ";
        cin>>a;
        system("cls");
        menu(a,user,password);
        pickVal(a,user,password);
        return a;
    }

    int menu(int &a,string &User,string &password)
    {
        while(a<1 || a>3)
        {
            cout<<endl;
            cout<<"\tInvalid option. Please choose from 1, 2 or 3.\n"<<endl;
            a=mainMenu(a,user,password);
            return 0;
        }
    }

    int pickVal(int &a,string &user,string &password)
    {
        switch(a)
        {
        case 1:
            login(a,user,password);
            break;

        case 2:
            creatAcount(user,password);
            getch();
            system("cls");
            login(a,user,password);
            getch();
            system("cls");
            break;

        case 3:
            rules();
            getch();
            system("cls");
            break;

        case 4:
            return 0;
            break;

        default:
            cout<<"internal error"<<endl;
        }
        return 0;
    }

    int rules(){
        cout<<"---------------------------------Exam Rules-------------------------------\n\n";
        cout<<"--> You need to insert all the information.\n";
        cout<<"--> If you give 11 correct then you are clear the exam.\n";
        cout<<"--> After clearing the exam must need to generate your licence copy.\n\n";
        cout<<"press enter for back to menu...";
        getch();
        system("cls");
        mainMenu(a,user,password);

    }
    int creatAcount(string &user,string &password)
    {   //here the create account tab is generate for the authorized user
        cout<<"\t-------------------------------------\n"<<"\t\tCreate an Account\n "<<"\t-------------------------------------";
        cout<<"\n\tEnter the user name of your choice: ";
        cin>>user;
        cout<<"\tEnter a password of your choice: ";
        cin>>password;
        cout<<endl;
        cout<<endl;
        cout<<"\t  Your account has been created successfully  ! \n"<<endl;
        return 0;
        getch();
        system("cls");
    }

    int login(int &a,string &user,string &password)
    {   //here the login account tab is generate for the authorized user
        abc:
        string user2;
        string password2;
        cout<<"\n\t----------------------------------\n"<<"\t\tLog into your Account\n"<<"\t-----------------------------------";
        cout<<"\n\tEnter your User name: ";
        cin>>user2;
        cout<<"\tEnter your password: ";
        cin>>password2;
        if(user2==user && password2==password)
        {
            cout<<endl;
            cout<<"\t YOU ARE LOGED IN ! "<<endl;
        }
        else
        {
        cout<<endl;
        cout<<"\n\tUser name or Password is INVALID.\n"<<endl;
        getch();
        system("CLS");
        mainMenu(a,user,password);
        }
    }
};
class Intro:public User
{
public:
    long long int adhar_no;
    char nm1[10],nm2[10],state[10];
    string email,b;
    long long int p_no;
    int d,m,y;


    void welcome()
    {   //here applicant tab is generated for applicant who apply for the test
        cout<<"\t***************************************\n"<<"\t\t  RTO LICENCE EXAM TEST\n"<<"\t***************************************";
        cout<<"\n\tWelcome to RTO licence Theory exam test";
    }

    void getData()
    {
        cout<<"\n\n\tApplicant Details:";
        cout<<"\n\n\tEnter your first name:";
        cin>>nm1;
        cout<<"\n\tEnter your Last name:";
        cin>>nm2;
        phone:
        cout<<"\n\tEnter your phone Number:";
        cin>>p_no;
        if(p_no>9999999999 || p_no<1000000000)
        {
            cout<<"\n\t-> Your phone number must be 10 digit.\n";
            goto phone;
        }
        Adharn:
        cout<<"\n\tEnter your Adhar Card Number:-";
        cin>>adhar_no;
        if(adhar_no>999999999999 || adhar_no<100000000000)
        {
            cout<<"\n\t-> Your Adhar number must be 12 digit.\n";
            goto Adharn;
        }
        cout<<"\n\tEnter your Blood Group: ";
        cin>>b;
        cout<<"\n\tEnter your E-MAIL: ";
        cin>>email;
        cout<<"\n\tEnter the State:";
        cin>>state;
    }

    void bDate()
    {
         time_t n=time(0);
        tm *l= localtime(&n);
        cout<<"\n\tEnter your Date of birth(dd mm yyyy):";
        cin>>d>>m>>y;
        cout<<endl;
        int t=(1900+l->tm_year)-y;
        if(t<18)
        {
            cout<<"\n\tYou are not eligible for Driving licence\n";
            cout<<"\t\tThank you for visiting\n\n";
            cout<<"Press enter for home page...";
            getch();
            system("cls");
            mainMenu(a,user,password);
            welcome();
            getData();
            bDate();
        }
        cout<<"Press enter for next...";
        getch();
        system("cls");
    }
};
class Quiz
{ // here the quiz tab is generate for exam
public:
    char ans;
    int x=0;
    void questions()
    {
    for(int i=1;i<16;)
    {
        switch(i)
        {
        case 1:
            cout<<"The best driving technique for dealing with slippery roads is to...?\n";
            cout<<"  A. Change up gear\n";
            cout<<"  B. Change down gear\n";
            cout<<"  C. Constantly apply the brakes\n";
            cout<<"  D. Drive as quickly as possible\n";
            cout<<"\nenter your ans:- ";
            cin>>ans;
            cout<<endl;
            if(ans=='b' || ans=='B')
                x++;
            cout<<"press enter for next...";
            getch();
            system("cls");
            break;
        case 2:
            cout<<"To ride motorcycle without gears, a person must be least what age?\n";
            cout<<"  A. 17\n";
            cout<<"  B. 16\n";
            cout<<"  C. 15\n";
            cout<<"  D. 14\n";
            cout<<"\nenter your ans:- ";
            cin>>ans;
            cout<<endl;
            if(ans=='b' || ans=='B')
                x++;
            cout<<"press enter for next...";
            getch();
            system("cls");
            break;
        case 3:
            cout<<"Traveling at 60km/h, how far will your vehicle travel in single second?\n";
            cout<<"  A. 12.2m\n";
            cout<<"  B. 4.3m\n";
            cout<<"  C. 16.6m\n";
            cout<<"  D. 8.6m\n";
            cout<<"\nenter your ans:- ";
            cin>>ans;
            cout<<endl;
            if(ans=='c' || ans=='C')
                x++;
            cout<<"press enter for next...";
            getch();
            system("cls");
            break;
        case 4:
            cout<<"Your insurance has expired. How long can you legally drive your vehicle before you renew it?\n";
            cout<<"  A. 0 days\n";
            cout<<"  B. 1 week\n";
            cout<<"  C. 1 month\n";
            cout<<"  D. 3 days\n";
            cout<<"\nenter your ans:- ";
            cin>>ans;
            cout<<endl;
            if(ans=='a' || ans=='A')
                x++;
            cout<<"press enter for next...";
            getch();
            system("cls");
            break;
        case 5:
            cout<<"If is acceptable to drink and drive...?\n";
            cout<<"  A. If an unexpected emergency arises\n";
            cout<<"  B. Under no circumstances\n";
            cout<<"  C. If you only have a short journey\n";
            cout<<"  D. If you are used to drinking\n";
            cout<<"\nenter your ans:- ";
            cin>>ans;
            cout<<endl;
            if(ans=='b' || ans=='B')
                x++;
            cout<<"press enter for next...";
            getch();
            system("cls");
            break;
        case 6:
            cout<<"A state driving license is valid for use...?\n";
            cout<<"  A. Anywhere in India\n";
            cout<<"  B. Anywhere in the world\n";
            cout<<"  C. Anywhere in India,Pakistan or Bangladesh\n";
            cout<<"  D. Only in the state of issue\n";
            cout<<"\nenter your ans:- ";
            cin>>ans;
            cout<<endl;
            if(ans=='a' || ans=='A')
                x++;
            cout<<"press enter for next...";
            getch();
            system("cls");
            break;
        case 7:
            cout<<"It is permissible to exceed the speed limit...?\n";
            cout<<"  A. When making an overtake\n";
            cout<<"  B. On empty road\n";
            cout<<"  C. In perfect conditions\n";
            cout<<"  D. Under no circumstances\n";
            cout<<"\nenter your ans:- ";
            cin>>ans;
            cout<<endl;
            if(ans=='d' || ans=='D')
                x++;
            cout<<"press enter for next...";
            getch();
            system("cls");
            break;
        case 8:
            cout<<"If you're involved in a motor accident, how long do you have to the nearest police station?\n";
            cout<<"  A. 48 hours\n";
            cout<<"  B. 12 hours\n";
            cout<<"  C. 72 hours\n";
            cout<<"  D. 24 hours\n";
            cout<<"\nenter your ans:- ";
            cin>>ans;
            cout<<endl;
            if(ans=='d' || ans=='D')
                x++;
            cout<<"press enter for next...";
            getch();
            system("cls");
            break;
        case 9:
            cout<<"A passenger may not carried on a motorcycle unless it has...?\n";
            cout<<"  A. A large engine\n";
            cout<<"  B. Proper foot rest\n";
            cout<<"  C. Mudguards\n";
            cout<<"  D. Wide tires\n";
            cout<<"\nenter your ans:- ";
            cin>>ans;
            cout<<endl;
            if(ans=='b' || ans=='B')
                x++;
            cout<<"press enter for next...";
            getch();
            system("cls");
            break;
        case 10:
            cout<<"The number plate of your vehicle must be...?\n";
            cout<<"  A. In Arabic with English numerals\n";
            cout<<"  B. In Hindi\n";
            cout<<"  C. In the local language\n";
            cout<<"  D. In English with Arabic numerals\n";
            cout<<"\nenter your ans:- ";
            cin>>ans;
            cout<<endl;
            if(ans=='d' || ans=='D')
                x++;
            cout<<"press enter for next...";
            getch();
            system("cls");
            break;
        case 11:
            cout<<"A cautionary traffic sign is what shape?\n";
            cout<<"  A. Rectangular\n";
            cout<<"  B. Circular\n";
            cout<<"  C. Square\n";
            cout<<"  D. Triangular\n";
            cout<<"\nenter your ans:- ";
            cin>>ans;
            cout<<endl;
            if(ans=='d' || ans=='D')
                x++;
            cout<<"press enter for next...";
            getch();
            system("cls");
            break;
        case 12:
            cout<<"What shape is mandatory traffic sign?\n";
            cout<<"  A. Square\n";
            cout<<"  B. Triangular\n";
            cout<<"  C. Rectangular\n";
            cout<<"  D. Circular\n";
            cout<<"\nenter your ans:- ";
            cin>>ans;
            cout<<endl;
            if(ans=='d' || ans=='D')
                x++;
            cout<<"press enter for next...";
            getch();
            system("cls");
            break;
        case 13:
            cout<<"Once you have obtained your learner's licence, it is valid for how long?\n";
            cout<<"  A. Four months\n";
            cout<<"  B. Six months\n";
            cout<<"  C. One year\n";
            cout<<"  D. Eight months\n";
            cout<<"\nenter your ans:- ";
            cin>>ans;
            cout<<endl;
            if(ans=='b' || ans=='B')
                x++;
            cout<<"press enter for next...";
            getch();
            system("cls");
            break;
        case 14:
            cout<<"You see a blind person holding up their white cane at the roadside. What should you do?\n";
            cout<<"  A. Stop and let them cross\n";
            cout<<"  B. Accelerate to get past them quickly\n";
            cout<<"  C. Move to the other side of the road to avoid them\n";
            cout<<"  D. Shout a warning from your window\n";
            cout<<"\nenter your ans:- ";
            cin>>ans;
            cout<<endl;
            if(ans=='a' || ans=='A')
                x++;
            cout<<"press enter for next...";
            getch();
            system("cls");
            break;
        case 15:
            cout<<"A PUCC(Pollution Under Control Certificate) is valid for how long from the date of issue?\n";
            cout<<"  A. Eight months\n";
            cout<<"  B. Twenty months\n";
            cout<<"  C. Four months\n";
            cout<<"  D. Twelve months\n";
            cout<<"\nenter your ans:- ";
            cin>>ans;
            cout<<endl;
            if(ans=='d' || ans=='D')
                x++;
            cout<<"press enter for next...";
            getch();
            system("cls");
            break;
        }i++;

        if(x==11)
        {
            cout<<"\nyou are pass this exam.";
            cout<<"\nyour score is: "<<x<<"/15";
            int a=1;
            break;
        }
    }
        if(x!=11)
        {
           cout<<"\nbetter luck next time.";
           cout<<"\nyour score is: "<<x<<"/15";
        }
    }
};
string fileCreat(string n)
{
    stringstream result;
    result << n;
    return result.str();
}
int main()
{
     time_t n=time(0);
    tm *l= localtime(&n);
    system("color 74");
    char date[9];
	_strdate(date);
	cout << date << endl;
    int a=0;
    string user;
    string password;

    User u1;
    u1.mainMenu(a,user,password);

    Intro i1;
    system("CLS");
    i1.welcome();
    i1.getData();
    i1.bDate();

    Quiz q;
    q.questions();
    if(q.x==11)
    {   // here the licence generate tab is create when applicant is clear exam he/she will able to generate the licence copy
        fstream fout;
        string f_name;
        string filename;

        cout<<"\n  enter file name: ";
        cin>>f_name;
        filename= fileCreat(f_name) +".txt";
        cout<<endl;
        cout<<"   Your file "<<filename << " is created  \n";
        cout<<endl;
        cout<<"   ( YOUR LICENCE DETAIL STORE IN THIS FILE )\n ";
        fout.open(filename.c_str(),ios::out);
        fout<<"---------------------------------------------------------------------------------------------------"<<endl;
        fout<<"                                                                           Date: "<<date<<"        "<<endl;
        fout<<"                                                                                                   "<<endl;;
        fout<<"                             Licence to drive vehicles through India                               \n"<<endl;
        fout<<" DL No.: 199600_____                                                                               \n"<<endl;
        fout<<" Name: "<<i1.nm1<<" "<<i1.nm2<<"\n"<<endl;//46
        fout<<" Phone No.: "<<i1.p_no<<"\n"<<endl;//53
        fout<<" Aadhar No.: "<<i1.adhar_no<<"\n"<<endl;//49
        fout<<" State: "<<i1.state<<"\n"<<endl;//56
        fout<<" DOB: "<<i1.d<<"/"<<i1.m<<"/"<<i1.y<<"\n"<<endl;//40
        fout<<"                                                                                                   "<<endl;
        fout<<" (Holder's Signature)                                                         Licence Authority    "<<endl;
        fout<<"                                                                                   India           "<<endl;
        fout<<"                                                                                                   "<<endl;
        fout<<"                                                                                                   "<<endl;
        fout<<"---------------------------------------------------------------------------------------------------"<<endl;
        fout<<"                                                                                                   "<<endl;
        fout<<"                                                                                                   "<<endl;
        fout<<"---------------------------------------------------------------------------------------------------"<<endl;
        fout<<"Blood Group: "<<i1.b<<"\n"<<endl;
        fout<<"Validity: "<<1900+l->tm_year<<"-"<<1925+l->tm_year<<"\n"<<endl;
        fout<<"                                                                                                   "<<endl;
        fout<<"                                                                                                   "<<endl;
        fout<<"E-MAIL: "<<i1.email<<endl;
        fout<<"                                                                                                   "<<endl;
        fout<<"                                                                                                   "<<endl;
        fout<<"                                                                                                   "<<endl;
        fout<<"                                                                                                   "<<endl;
        fout<<"                                                                                                   "<<endl;
        fout<<"                                                                                                   "<<endl;
        fout<<"                                                                                                   "<<endl;
        fout<<"                                                                                                   "<<endl;
        fout<<"---------------------------------------------------------------------------------------------------"<<endl;
        fout.close();
    }
}
