#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void login();
void registration();
void forgot();

int main(){
	int c;
	cout<<"\t\t\t___________________________________"<<endl;
	cout<<"\t\t\t       Welcome To The page         "<<endl;
	cout<<"\t\t\t______________MENU___________"<<endl;
	cout<<"                                   "<<endl;
	cout<<"\t| 1. To log in        |"<<endl;
	cout<<"\t| 2. To Sign in       |"<<endl;
	cout<<"\t| 3. Forgot password  |"<<endl;
	cout<<"\t| 4. To Exit          |"<<endl;
	cout<<"\tEnter your choice : ";
	cin>>c;
	cout<<endl;
	
	
	switch(c)
	{
		case 1:
			login();
			break;
		case 2:
			registration();
			break;
		case 3:
			forgot();
			break;
		case 4:
			cout<<"Thanks for your Time!!Visit Again"<<endl;
			break;
		default:
			system("cls");
			cout<<"Invalid Choice"<<endl;
			main();			
	}
}


void login(){
	int count;
	string u_id,password,id,pass;
	system("cls");
	cout<<"\t\t\tPlease Enter the username & Password"<<endl;
	cout<<"\t\t\tUSERNAME :";
	cin>>u_id;
	cout<<"\t\t\tPassword :";
	cin>>password;
	
	ifstream input("records.txt");
	
	while(input>>id>>pass){
		if(id==u_id && pass==password)
		{
			count=1;
			system("cls");
		}
	}
	input.close();
	
	if(count==1){
		cout<<u_id<<"\nYour login is successfull\n";
		main();
	}
	else{
		cout<<"\nPlease give correct username and password\n";
		main();
	}
	
}

void registration()
{
	string ru_id,rpw,rid,rpass;
	system("cls");
	cout<<"\t\t\tEnter the username: ";
	cin>>ru_id;
	cout<<"\t\t\tEnter password: ";
	cin>>rpw;
	
	ofstream output("records.txt",ios::app);
	output<<ru_id<<' '<<rpw<<endl;
	system("cls");
	cout<<"\nRegistration is Successfull!!\n";
	main();
}

void forgot(){
	int option;
	system("cls");
	cout<<"\t\t\t1. Search id by Username"<<endl;
	cout<<"\t\t\t2. Go back to the main menu "<<endl;
	cout<<"\t\t\t Enter your choice: ";
	cin>>option;
	
	switch(option)
	{
		case 1:
		{
			int count=0;
			string su_id,sid,spass;
			cout<<"\t\t\tEnter the username: ";
			cin>>su_id;
			
			ifstream f2("records.txt");
			while(f2>>sid>>spass)
			{
				if(sid==su_id)
				{
					count=1;
				}
			}
			f2.close();
			if(count==1)
			{
				cout<<"Account is found!!!"<<endl;
				cout<<"password is : "<<spass;
				main();
			}
			else
			{
				cout<<"Give correct username "<<endl;
				main();
			}
			
		}
		break;
		
		case 2:
			main();
		default:
		    cout<<"Invalid Choice"<<endl;
			forgot();	
		
	}
}