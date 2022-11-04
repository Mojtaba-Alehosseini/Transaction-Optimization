//Mojtaba Alehosseini   mojtaba96
//password: mojtaba96

#include <iostream>
#include <windows.h>
using namespace std;
struct node
    {
        char from;
        int money;
        char to;
    };
node mylist[100];

void print_sleepy(char a[200], int time)
{
    int i;
    for (i=0;a[i]!='\0';i++)
    {
        cout<<a[i];
        Sleep(time);
    }
}

void Please_wait()
{
    for(int i=0;i<10;i++)
    {
        Sleep(100);
        cout<<"\b\b\b";
        cout<<"   ";
        cout<<"\b\b\b";
        cout<<".";
        Sleep(60);
        cout<<".";
        Sleep(55);
        cout<<".";
        Sleep(50);
    }
}

void Upgrading()
{
    int i;
    cout<<"upgrading:\t";
    for(i=0;i<10;i++)
    {
        cout<<i<<"%";
        Sleep(80);
        cout<<"\b\b";
    }
    for(i;i<85;i++)
    {
        cout<<i<<"%";
        Sleep(50);
        cout<<"\b\b\b";
    }
    for(i;i<101;i++)
    {
        cout<<i<<"%";
        Sleep(90);
        cout<<"\b\b\b";
    }
}

int Check_Key(int b)
{
    // b=0 yani register , b=1 yani password ke badan ezafe mikonm
    int i,a,s=0;
    char c[31],plswait[100];
   	if (b==0)
    {
        cout << "\nEnter license key:\n(if you don't have license key, you can buy it from contact us part)\n\t\t\t";
        cin.ignore();
        cin.get(c, 30);
        strcpy(plswait,"Please wait ...");
        print_sleepy(plswait,75);
        Please_wait();
        //mojtaba
        for (i = 0; i < 30 && c[i] != '\0'; i++)
        {
            a = int(c[i]);
            s += a;
        }
        if (s == 734)
        {
            cout<<"\nThanks for buy\n";
            Upgrading();
            return 1;
        }
        cout<<"\a\nWrong license key\n";
        Beep(1023,600);
        return 0;
    }
}

void check(int i, int n)
    {
        int j;
        for (j=0;j<n;j++)
        {
            if (j!=i && mylist[i].money!=0)
            {
                if (mylist[i].to==mylist[j].from)
                {
                    if (mylist[i].money < mylist[j].money)
                    {
                        mylist[i].to = mylist[j].to;
                        mylist[j].money -= mylist[i].money;
                        break;
                    }
                    else
                    {
                        mylist[i].money -= mylist[j].money;
                        mylist[j].from = mylist[i].from;
                        break;
                    }
                }
            }
        }
    }

void add(int n)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=i+1; j<n; j++)
        {
            if (mylist[j].from==mylist[i].from)
            {
                if(mylist[j].to==mylist[i].to)
                {
                    mylist[j].money+=mylist[i].money;
                    mylist[i].money=0;
                }
            }
        }
    }
}

void reorder(int a,int n)
{
    int i;
    for (i=a;i<n;i++)
    {
        mylist[i].from=mylist[i+1].from;
        mylist[i].to=mylist[i+1].to;
        mylist[i].money=mylist[i+1].money;
    }
}

int define_n(int n)
{
    int i,c=0;
    for (i=0;i<=n;i++)
    {
        if (mylist[i].money==0)
        {
            reorder(i,n);
            c++;
        }
    }
    return c;
}

void About()
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 0x07);
        cout<< "\n \t\t       ";
        SetConsoleTextAttribute(h, 0xF0);
        cout<<"Data Structure Project";
        SetConsoleTextAttribute(h, 0x07);
        cout<<"\n\t\t\t    ";
        SetConsoleTextAttribute(h, 0xFA);
        cout<<"Supervisor:";
        SetConsoleTextAttribute(h, 0x07);
	    cout<<"\n\t\t ";
	    SetConsoleTextAttribute(h, 0xF0);
	    cout<<"Dr seyed Abolfazl Shahzadeh fazeli";
	    SetConsoleTextAttribute(h, 0x07);
	    cout<<"\n\t\t\t   ";
	    SetConsoleTextAttribute(h, 0xFA);
	    cout<<"Developed by:";
	    SetConsoleTextAttribute(h, 0x07);
        cout<<"\n\t\t\t";
        SetConsoleTextAttribute(h, 0xF0);
        cout<<"Mojtaba Alehoseini";
        SetConsoleTextAttribute(h, 0x07);
        cout<<"\n\t\t\t    ";
        SetConsoleTextAttribute(h, 0xF3);
        cout<<"12/01/2019";//22/10/1397
        SetConsoleTextAttribute(h, 0x07);
        cout<<"\n\n";
}

void Contact_me()
{
	cout << "\n\t Ways to contact with me:\n\n\t     Email:     Alehoseini.Mojtaba@gmail.com\n\t Github:  mojtaba96\n";
}


int main()
{
    cout<<"Mojtaba Alehosseini";
    cout << "\n\t\t\t\t\t Data Structure Project ";
    int choose,n=0,j,i,reg=0;
    do
    {
        if (reg == 1)
            {
                cout << "\n\t\t\t\t\t  Full Version ";
            }
        else
        {
            cout << "\n\t\t\t\t\t      *Demo Mode* ";
            cout<< "\n to have more option buy full version in register option";
        }
        cout<<"\n 1) Add new";
        cout<<"\n 2) Show ordered list";
        if (reg==1)
        {
            cout<<"\n 3) reorder array to use the maximum size of program\n\t(with this option you can add 200 different person)";
        }
        else
        {
            cout<<"\n 7) Register";
        }
        cout<<"\n 8) Contact with me";
        cout<<"\n 9) About";
        cout<<"\n 0) Exit";
        cout<<"\nEnter your choice:\t";
        cin>>choose;
    switch (choose)
    {
        case 1:
            cout<<"\n Add Transaction\n";
            cout<<"\nPlease enter name as one character only\n";
            cout <<" Enter Payer name:\t"; //variz konande
            cin>>mylist[n].from;
            cout << " Enter Amount:\t\t"; //mablagh
            cin>>mylist[n].money;
            cout << " Enter Payee name:\t"; //daryaft konande
            cin>>mylist[n].to;
            cout << "\nSuccessfully added\n";
            n++;
            break;
        case 2:
            if (n==0)
            {
                cout<<"There is no record yet\n";
                break;
            }
            cout<<"show ordered list\n_____________________________";
            for (i=0;i<n;i++)
            {
                check(i,n);
            }
            add(n);
            cout<<"\nFrom\tHow much\tTo\n";
            for (i=0;i<n;i++)
            {
                if (mylist[i].money!=0)
                {
                    if(mylist[i].from!=mylist[i].to)
                    cout<<" "<<mylist[i].from<<"\t   "<<mylist[i].money<<"\t\t"<<mylist[i].to<<"\n";
                }
            }
           break;
        case 3:
            if (reg==1)
                {
                    cout<<"paksazi araye";
                    cout<<"\ndar hale hazer az "<<n<<" khane araye estefade shode ast";
                    n=n-define_n(n);
                    cout<<"\naknoon az "<<n<<" khane areye estefade mishavad";
                    break;
                }
                cout << "\aWrong Choice\n"<<'\a';
                break;
        case 7:
            if (reg==0)
                {
                    reg=Check_Key(0);
                    break;
                }
            cout << "\aWrong Choice\n";
            break;
        case 8:
            Contact_me();
            break;
        case 9:
            About();
            break;
        case 0:
            cout<<"\nGoodBye";
            return 0;
        default:
            cout << "\aWrong Choice";
            Beep(400,300);
    }
    }while(choose!=0);
    return 0;
}
