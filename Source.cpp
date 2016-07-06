#include<fstream>
#include<stdio>
#include<process>
#include<conio>
#include<iomanip>
using namespace std;
class travellers
{
int t_code;
char t_telno[20];
char t_name[25];
char t_add[20];
int age;
char gender[10];
int train_no;
public:
void readdata();
void writedata();
void writefile();
void readfile();
void searchfile();
void modify();
void Delete();
void Insert();
};
class train
{
int f_no;
char from[20];
float charges;
char to[20];
int no_of_seats;
public:
void Input();
void Output();
void writefile();
void readfile();
void searchfile();
void modifile();
void delfile();
void insertfile();
};
void travellers::readdata()
{
clrscr();
cout<<"\n\tEnter traveller code ";
cin>>t_code;
cout<<"\n\tEnter name ";
gets(t_name);
cout<<"\n\tEnter address ";
gets(t_add);
cout<<"\n\tEnter telephone number ";
cin>>t_telno;
cout<<"\n\tEnter age ";
cin>>age;
cout<<"\n\tEnter gender ";
cin>>gender;	
cout<<"\n\tEnter train number ";
cin>>train_no;
clrscr();
}
void travellers::writedata()
{
cout<<"\t________________________________________\n";
cout<<"\n\t Traveller code : "<<t_code;
cout<<"\n\t Traveller name : "<<t_name;
cout<<"\n\t Traveller address : "<<t_add;
cout<<"\n\t Traveller telephone number : "<<t_telno;
cout<<"\n\t Traveller age : "<<age;
cout<<"\n\t Traveller gender : "<<gender;
cout<<"\n\t Train number is : "<<train_no<<"\n\n";
}
void travellers::writefile()
{
travellers t;
int n,i;
ofstream onfile("travellers.dat",ios::binary|ios::out);
cout<<"\n\tEnter no. of travellers ";
cin>>n;
for(i=0;i<n;i++)
{
t.readdata();
onfile.write((char*)&t,sizeof(t));
}
onfile.close();
}
void travellers::readfile()
{
ifstream infile("travellers.dat",ios::binary);
travellers t;
if(!infile)
cout<<"\nFile does not exist\n";
else
{
infile.read((char*)&t,sizeof(t));
while(infile)
{
t.writedata();
infile.read((char*)&t,sizeof(t));
}
infile.close();
}
}
void travellers::searchfile()
{
travellers t;
int t_no,f=0;
cout<<"\tEnter traveller code\n\t";
cin>>t_no;
ifstream infile("travellers.dat",ios::binary);
if(!infile)
cout<<"File does not exits";
else
{
infile.read((char*)&t,sizeof(travellers));
while((infile)&&(f==0))
{
if(t_no==t.t_code)
{
t.writedata();
f++;
}
infile.read((char*)&t,sizeof(travellers));
}
if(f==0)
cout<<"\n\t Traveller code does not exist";
infile.close();
}
}
void travellers::Insert()
{
travellers t1,t2;
int f=0;
ifstream infile("travellers.dat",ios::binary);
ofstream onfile("temp.dat",ios::binary);
if(!infile)
cout<<"\nFile does not exist\n";
else
cout<<"\nEnter traveller's information you want to insert\n";
{
t1.readdata();
infile.read((char*)&t2,sizeof(travellers));
while((infile)&&(f==0))
{	
if(t1.t_code<t2.t_code)
{
f=1;
onfile.write((char*)&t1,sizeof(travellers));
}
else
{
onfile.write((char*)&t2,sizeof(t2));
infile.read((char*)&t2,sizeof(t2));
}
}
}
if(f==1)
{
while(infile)
{
onfile.write((char*)&t1,sizeof(travellers));
infile.read((char*)&t2,sizeof(travellers));
}
}
onfile.write((char*)&t1,sizeof(travellers));
onfile.close();
infile.close();
remove("travellers.dat");
rename("temp.dat","travellers.dat");
}
void travellers::Delete()
{
travellers t2,t1;
int t_no,f=0;
ifstream infile("travellers.dat",ios::binary);
ofstream onfile("temp.dat",ios::binary);
if(!infile)
cout<<"\nFile does not exist\n";
else
{
cout<<"\n\tEnter any traveller code\n\t";
cin>>t_no;
while(infile.read((char*)&t1,sizeof(travellers)))
{
if(t_no==t1.t_code)
f=1;
else
onfile.write((char*)&t1,sizeof(travellers));
}
infile.close();
onfile.close();}
if(f==0)
cout<<"Traveller code does not exist";
else
{
remove("travellers.dat");
rename("temp.dat","travellers.dat");
}
}	
void travellers::modify()
{
ifstream infile("travellers.dat",ios::binary);
ofstream onfile("temp.dat",ios::binary);
travellers t;
int t_no,f=0;
if(!infile)
cout<<"File does not exist";
else
{
cout<<"\tEnter traveller code you want to modify\n";
cin>>t_no;
while(infile.read((char*)&t,sizeof(t)))
{
if(t.t_code==t_no)
{
t.readdata();
onfile.write((char*)&t,sizeof(t));
f=1;
}
else
onfile.write((char*)&t,sizeof(t));
}
onfile.close();
infile.close();
if(f==0)
cout<<"Traveller code not found in our database\n";
else
{
remove("travellers.dat");
rename("temp.dat","travellers.dat");
}
}
}
void train::Input()
{
cout<<"\n\tEnter train number : ";
cin>>f_no;
cout<<"\n\tEnter place of departure : ";
gets(from);
cout<<"\n\tEnter destination place : ";
gets(to);
cout<<"\n\tEnter train charges(Rs.) : ";
cin>>charges;
cout<<"\n\tEnter number of seats : ";
cin>>no_of_seats;
}
void train::Output()
{
cout<<"\t_________________________________________________\n\n";
cout<<"\tTrain number : "<<f_no<<"\n\n";
cout<<"\tPlace of departure : "<<from<<"\n\n";
cout<<"\tDestination place : "<<to<<"\n\n";
cout<<"\tEnter train charges(Rs.) : "<<charges<<"\n\n";
cout<<"\tEnter number of seats : "<<no_of_seats<<"\n\n";
}
void train::writefile()
{
ofstream onfile("train.dat",ios::binary);
train t[10];
int n,i;
cout<<"\n\tEnter total train ";
cin>>n;
for(i=0;i<n;i++)
{
t[i].Input();
cout<<"\n";
onfile.write((char*)&t[i],sizeof(t[i]));
}
onfile.close();
}
void train::readfile()
{
ifstream infile("train.dat",ios::binary);
train t;
if(!infile)
cout<<"File does not exist";
else
{	
while(infile.read((char*)&t,sizeof(t)))
{
t.Output();
}
infile.close();
}
}
void train::searchfile()
{
ifstream infile("train.dat",ios::binary);
train t;
int tno,f=0;
if(!infile)
cout<<"File does not exist";
else
{
cout<<"\n\tEnter train number\n\t";
cin>>tno;
while(infile.read((char*)&t,sizeof(t))&&(f==0))
{
if(t.f_no==tno)
{
f=1;
t.Output();
}
}
if(f==0)
cout<<"Train not exist";
}
infile.close();
}
void train::modifile()
{
ifstream infile("train.dat",ios::binary);
ofstream onfile("Temp.dat",ios::binary);
train t;
int tno,f=0;
if(!infile)
cout<<"File does not exist";
else
{
cout<<"\tEnter train number\n";
cin>>tno;
while(infile.read((char*)&t,sizeof(t)))
{
if(t.f_no==tno)
{
t.Input();
onfile.write((char*)&t,sizeof(t));
f=1;
}
else
onfile.write((char*)&t,sizeof(t));
}
onfile.close();
infile.close();
if(f==0)
cout<<"Train not exist\n";
else
{
remove("train.dat");
rename("Temp.dat","train.dat");
}
}
}
void train::delfile()
{
ifstream infile("train.dat",ios::binary);
ofstream onfile("Temp.dat",ios::binary);
train t;
int tno,f=0;
if(!infile)
cout<<"File does not exist";
else
{
cout<<"\n\n\tEnter train to be deleted ";
cin>>tno;
while(infile.read((char*)&t,sizeof(t)))
{
if(tno==t.f_no)
f=1;
else
onfile.write((char*)&t,sizeof(t));
}
infile.close();
onfile.close();
if(f==0)
cout<<"Train Does Not Exist";
else
{
remove("train.dat");
rename("Temp.dat","train.dat");
}
}
}
void train::insertfile()
{	
train t1,t2;
int f=0;
ifstream infile("train.dat");
ofstream onfile ("temp.dat");
if(!infile)
cout<<"File does not exist ";
else
{		
cout<<"\n\tEnter New Train Information ";
t1.Input();
while((infile.read((char*)&t2,sizeof(t2))&&(f==0)))
{
if (t1.f_no<t2.f_no)
{
f=1;
onfile.write((char*)&t1,sizeof(t1));
}
onfile.write((char*)&t2,sizeof(t2));
}
if(f==1)
{	
while(infile)
{
onfile.write((char*)&t2,sizeof(t2));
infile.read((char*)&t2,sizeof(t2));
}
}
else
{
onfile.write((char*)&t1,sizeof(t1));
onfile.close();
infile.close();
remove("train.dat");
rename("temp.dat","train.dat");
}
}
}	
void startproject()
{
int i;
clrscr();
}
int main()
{
startproject();
int choice,c1,c2,c3;
train f1;
travellers t1;
			i:	
do
{
clrscr();
cout<<"\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";
cout<<"\t\t       |WELCOME TO| \n\t\t     |INDIAN RAILWAYS|  \n";
cout<<"\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";
cout<<"\n\t\t*****************************";
cout<<"\n\t\t* 1.For train details.";
cout<<"\n\t\t* 2.For travellers details.";
cout<<"\n\t\t* 3.Exit.\n";
cout<<"\t\t*****************************\n";
cout<<'\n';
cout<<"\t\tEnter your choice : ";
cin>>choice;
switch (choice)
{
case 2:
do
{
clrscr();
cout<<"\t********************************\n";
cout<<"\t      |Travellers details| \n";
cout<<"\t********************************\n\n";
cout<<"\t**********************************************************";
cout<<"\n\t*  1.Write into the traveller database. ";
cout<<"\n\t*  2.Read from the traveller database. ";
cout<<"\n\t*  3.Search traveller details from database. ";
cout<<"\n\t*  4.Insert a new entry in traveller database. ";
cout<<"\n\t*  5.Delete a traveller information from database. ";
cout<<"\n\t*  6.Modify travellers details in database. ";	
cout<<"\n\t*  7.Exit. \n";
cout<<"\t**********************************************************";
cout<<"\n\n\tEnter your Choice : ";
cin>>c1;
switch(c1)
{
case 1:t1.writefile();
break;
case 2:t1.readfile();
getch();
break;
case 3:t1.searchfile();
getch();
break;
case 4:t1.Insert();	
getch();
break;
case 5:t1.Delete();
getch();
break;
case 6:t1.modify();
getch();
break;
case 7:goto i;
}
 				}
while((c1!=7));
case 1:
do
{
clrscr();
cout<<"\t*******************************\n";
cout<<"\t\t |Train Details|";
cout<<"\n\t*******************************\n\n";
cout<<"\t**********************************************************";
cout<<"\n\t*  1.Write into the train file. ";
cout<<"\n\t*  2.Read from the train file. ";
cout<<"\n\t*  3.Search from the existing train file. ";
cout<<"\n\t*  4.Insert a new entry into the train file. ";
cout<<"\n\t*  5.Delete an existing entry from the train file. ";
cout<<"\n\t*  6.Modify an entry from the train file. ";
cout<<"\n\t*  7.Exit. \n";
cout<<"\t**********************************************************";
cout<<"\n\n\tEnter your choice : ";
cin>>c2;
switch(c2)
{
case 1:f1.writefile();
break;
case 2:f1.readfile();
getch();
break;
case 3:f1.searchfile();
getch();
break;
case 4:f1.insertfile();
getch();
break;
case 5:f1.delfile();
getch();
break;
case 6:f1.modifile();
getch();
break;
case 7:goto i;
}
}	
while((c2!=7));
}
}
while(choice!=3);
}
