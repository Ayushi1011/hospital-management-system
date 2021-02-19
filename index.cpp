#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
using namespace std;
class patient
{
	protected:
		struct rec
		{
			int id;
			char name[10];
			int age;
			char gender;
			char bg[3];
			char contact_no[10];
			int room_no;
		};
		int i;
	public:
		void create();
		void display();
		void search();
		void emergency();
		void getadmit();
		void pathalogy();
		void discharge();
};

class doctor:public patient
{
		int id,day;
		char name[10];
		char department[10];
		string appbook[5][8][3],date;
	public:
		void about();
		void makeappointment();
		void showday();
		void checktime(string);
};

void patient::create()
{		
		int dpt;
		char file[15];
		cout<<"\n1.Cardiology\n2.Intensive care unit(ICU)\n3.Neurology\n4.Gynaecology\n5.Physiotherapy\n6.Urology ";
		cout<<"\n\nPlease enter department :";
		cin>>dpt;
		switch(dpt)
		{
			
			case 1:
				strcpy(file,"Cardiology");
				break;
			case 2:
				strcpy(file,"ICU");
				break;
			case 3:
				strcpy(file,"Neurology");
				break;
			case 4:
				strcpy(file,"Gynaecology");
				break;
			case 5:
				strcpy(file,"Physiotherapy");
				break;
			case 6:
				strcpy(file,"Urology");
				break;
			default:
				cout<<"\nPlease enter valid option :";
				break;
		}
		fstream fp;
		fp.open(file,ios::binary|ios::in);
		if(!fp)
		{
			cout<<"\nFile not found";
		}
		else
		{	
		
			rec r;
			int id,flag=0;
			
			cout<<"\nPlease fill the following details";
			cout<<"\nID: ";
			cin>>id;
		
			while(fp.read((char *)&r,sizeof(r)))
			{
				if(r.id==id){
					flag=1;
					break;
				}
			}
			fp.close();
			if(flag==1)
			{
				cout<<"\nID already exist\nID can't be repeated..\n";
			}
			else
			{	
			r.id=id;
			cout<<"\nName: ";
			cin>>r.name;
			cout<<"\nAge: ";
			cin>>r.age;
			cout<<"\nGender: ";
			cin>>r.gender;
			cout<<"\nBlood Group:";
			cin>>r.bg;
			cout<<"\nContact number:";
			cin>>r.contact_no;
			cout<<"\nRoom Number:";
			cin>>r.room_no;
			
			fp.open(file,ios::app|ios::binary);
			fp.write((char *)&r,sizeof(r));
			cout<<"\n---------------------------------------------\n";
			fp.close();
			cout<<"\nPatient is admitted\n";
		}
	}
	system("pause");
	system("cls");
}
void patient::display()
{
		fstream fp;
		rec t;
		int flag=0;
		int dpt;
		char file[15];
		cout<<"\n1.Cardiology\n2.Intensive care unit(ICU)\n3.Neurology\n4.Gynaecology\n5.Physiotherapy\n6.Urology\n";
		cout<<"\n\nPlease enter department :";
		cin>>dpt;
		switch(dpt)
		{
			case 1:
				strcpy(file,"Cardiology");
				break;
			case 2:
				strcpy(file,"ICU");
				break;
			case 3:
				strcpy(file,"Neurology");
				break;
			case 4:
				strcpy(file,"Gynaecology");
				break;
			case 5:
				strcpy(file,"Physiotherapy");
				break;
			case 6:
				strcpy(file,"Urology");
				break;
			default:
				cout<<"\nPlease enter valid option :";
				break;
		}
	
		//fp.open(file,ios::binary|ios::in);
		// if(fp==NULL)
		// {
		// 	cout<<"\nFile not created..";
		// }
		// else
		// {
			cout<<"\nID\tName\tAge\tGender\tBlood Group\tRoom_no\t\tContact number";
			cout<<"\n-----------------------------------------------------------------------------------------------------\n";
			
			while(fp.read((char *)&t,sizeof(t)))  
			{
				cout<<"\n"<<t.id<<"\t"<<t.name<<"\t"<<t.age<<"\t"<<t.gender<<"\t"<<t.bg<<"\t\t"<<t.room_no<<"\t\t"<<t.contact_no;	
				//fp.read((char *)&t,sizeof(t));
			}			
		// }
		// fp.close();
		cout<<"\n";
		system("pause");
		system("cls");
}

void patient::search()
{
		fstream fp;
		rec q;
		int flag=0;
		int dpt;
		char file[15];
		cout<<"\n1.Cardiology\n2.Intensive care unit(ICU)\n3.Neurology\n4.Gynaecology\n5.Physiotherapy\n6.Urology ";
		cout<<"\n\nPlease enter department :";
		cin>>dpt;
		switch(dpt)
		{
			
			case 1:
				strcpy(file,"Cardiology");
				break;
			case 2:
				strcpy(file,"ICU");
				break;
			case 3:
				strcpy(file,"Neurology");
				break;
			case 4:
				strcpy(file,"Gynaecology");
				break;
			case 5:
				strcpy(file,"Physiotherapy");
				break;
			case 6:
				strcpy(file,"Urology");
				break;
			default:
				cout<<"\nPlease enter valid option :";
				break;
		}
	
		fp.open(file,ios::binary|ios::in);
		if(!fp)
			cout<<"\nFile not found..\n";
		else
		{
			int rl;
			cout<<"\nEnter patient ID to be visited: ";
			cin>>rl;
			
			while(fp.read((char *)&q,sizeof(q)))
			{         
				if(q.id==rl)
				{
					cout<<"\n---------------------------------------------\n";
					cout<<"Patient details are:";
					cout<<"\nID: "<<q.id;
					cout<<"\nName: "<<q.name;
					cout<<"\nAge: "<<q.age;
					cout<<"\nGender: "<<q.gender;
					cout<<"\nBlood Group: "<<q.bg;
					cout<<"\nContact number: "<<q.contact_no;
					cout<<"\nRoom number: "<<q.room_no;
					cout<<"\n-------------------------------------";
					flag=1;
					break;
				}
				//else
					//fp.read((char *)&q,sizeof(q));
			}
			if(flag==0)
				cout<<"\nPatient not found....\n";
		}
		cout<<"\n";
		fp.close();
		system("pause");
		system("cls");
}

void patient::emergency()
{
	fstream fp;
	int ch;
	rec e;
	cout<<"1. Add patient\n2. Display patients\nEnter your choice: ";
	cin>>ch;
	switch(ch){
		case 1:	cout<<"\nEnter patient name:";
				cin>>e.name;
				cout<<"\nEnter blood group:";
				cin>>e.bg;
				fp.open("Emergency",ios::app|ios::binary);
				fp.write((char*)&e,sizeof(e));
				fp.close();
				cout<<"\nPatient is admitted\n";
				break;
		case 2: cout<<"\nName\tBlood Group\n";
				cout<<"\n-------------------------------------";
				fp.open("Emergency",ios::binary|ios::in);
				while(fp.read((char*)&e,sizeof(e)))
				{
					cout<<"\n"<<e.name<<"\t"<<e.bg;
				}
				break;
	}
	cout<<"\n";
	system("pause");
	system("cls");
}

void patient::getadmit()
{
	create();
}

void patient::pathalogy()
{
	int test;
	cout<<"\n1.Blood Test\n2.TSH (Thyroid Stimulating Hormone)\n3.Iron test\n4.Urinalysis\n5.Liver Function Tests\n";
	cout<<"\nWhich test do u wanna to do:";
	cin>>test;
	switch(test)
	{
		case 1:
			cout<<"\nAppointment for Blood test has been confirmed\n";
			break;
		case 2:
			cout<<"\nAppointment for TSh(thyroid Stimulating Harmone) has been confirmed\n";
			break;
		case 3:
			cout<<"\nAppointment for Iron test has been confirmed\n";
			break;
		case 4:
			cout<<"\nAppointment for Urinalysis test has been confirmed\n";
			break;
		case 5:
			cout<<"\nAppointment for Liver function test has been confirmed\n";
			break;
		default:
			cout<<"\nPlease enter valid choice:";
			cout<<"\n";
			break;
	}
	cout<<"\nPlease wait for reports on reception\n";
	system("pause");
	system("cls");
}

void doctor::about()
{
	string str1;
	ifstream infile;
	infile.open("About.txt");
	cout<<"\nMultispeciality hospital specialised in different department like cardiology,neurology,gynaecology and many more , with skilled doctors.";
	cout<<"\n\nWe have following departments:";
	cout<<"\n-->Emergency Department\n-->Cardiology\n-->Intensive care unit(ICU)\n-->Neurology\n-->Gynaecology\n-->Physiotherapy\n-->Urology ";
	cout<<"\n\nSpecialist doctors we have are :";
	cout<<"\nDoctor\t\tDepartment\n";
	cout<<"-----------------------------------------";
	while(!infile.eof())
	{
		getline(infile,str1);
		cout<<"\n"<<str1;
			
	}
	infile.close();
	cout<<"\n";
	system("pause");
	system("cls");
}

void doctor::makeappointment()
{
	string date;
	int day;
	cout<<"\n1.Monday\n2.Tuesday\n3.Wednesday\n4.Thursday\n5.Friday\n6.Saturday\n";
	cout<<"\nSelect the day :";
	cin>>day;

	switch(day)
	{
		case 1:
			date="Monday";
			checktime(date);
			break;
		case 2:
			date="Tuesday";
			checktime(date);
			break;
		case 3:
			date="Wednesday";
			checktime(date);
			break;
		case 4:
			date="Thursday";
			checktime(date);
			break;
		case 5:
			date="Friday";
			checktime(date);
			break;
		case 6:
			date="Saturday";
			checktime(date);
			break;
		default:
			cout<<"\nEnte valid option..";
			break;
	}
	system("pause");
	system("cls");
}
void doctor::checktime(string date)
{
	int time;
	string  patient;
	bool checksum=false;
	do{
		cout<<"\nEnter time for appointment:";
		cin>>time;
		if(appbook[day][time][0]=="")
		{
			cout<<"\nEnter patient name :";
			cin>>patient;
			cout<<"\nEnter Department :";
			cin>>department;
			appbook[day][time][0]=date;
			appbook[day][time][1]=patient;
			appbook[day][time][2]=department;
			checksum=true;			
		}
		else
		{
			cout<<"\nDoctor is not available..\nPlease choose another time: ";
		}	
	}while(checksum==false);
			cout<<appbook[day][time][1]<<" is getting an appointment in "<<appbook[day][time][2]<<" department on "<<appbook[day][time][0]<<" at "<<time;
		cout<<"\n";
}
void patient::discharge()
{
	int dpt;
	char file[15];
	cout<<"\n1.Cardiology\n2.Intensive care unit(ICU)\n3.Neurology\n4.Gynaecology\n5.Physiotherapy\n6.Urology ";
		cout<<"\n\nPlease enter department :";
		cin>>dpt;
		switch(dpt)
		{
			
			case 1:
				strcpy(file,"Cardiology");
				break;
			case 2:
				strcpy(file,"ICU");
				break;
			case 3:
				strcpy(file,"Neurology");
				break;
			case 4:
				strcpy(file,"Gynaecology");
				break;
			case 5:
				strcpy(file,"Physiotherapy");
				break;
			case 6:
				strcpy(file,"Urology");
				break;
			default:
				cout<<"\nPlease enter valid option :";
				break;
		}
		fstream dept, temp;
		int id,flag=0;
		cout<<"\nPlease enter ID: ";
		cin>>id;
		dept.open(file,ios::binary|ios::in);
		rec r;
		while(dept.read((char *)&r,sizeof(r)))
		{
			if(r.id==id)
			{
				flag=1;
				break;
			}
		}
		dept.close();
		if(flag==0)
		{
			cout<<"\nPatient not found..";
		}
		else
		{
			temp.open("temp",ios::binary|ios::out);
			dept.open(file,ios::in|ios::binary);
			while(dept.read((char *)&r,sizeof(r)))
			{
				if(r.id==id)
					continue;
				else
					temp.write((char *)&r,sizeof(r));
			}
			temp.close();
			dept.close();
			dept.open(file,ios::binary|ios::out);
			temp.open("temp",ios::binary|ios::in);
			while(temp.read((char *)&r,sizeof(r)))
			{
				dept.write((char *)&r,sizeof(r));
			}
			dept.close();
			temp.close();
			cout<<"\nPatient is discharged";
		}
		cout<<"\n";
		system("pause");
		system("cls");
}

int main()
{
	
	int ch,c;
	patient p;
	doctor d;
	do
	{
		cout<<"\n\n\n\t\t\t\t\t\t\t**************** APEX MULTISPECIALITY HOSPITAL****************";
		cout<<"\n\n\t\t\t\t\t\t\t-----------------------------------------------------------\n";
		cout<<"\n\t\t\t\t\t\t\tHow may we help you?\n";	
		cout<<"\n\t\t\t\t\t\t\t1  >>   Emergency Services\n\t\t\t\t\t\t\t2  >>	Get admitted\n\t\t\t\t\t\t\t3  >>	Get appointment\n\t\t\t\t\t\t\t4  >>	Display Patients\n\t\t\t\t\t\t\t5  >>	Visit a patient";
		cout<<"\n\t\t\t\t\t\t\t6  >>   Discharge patient\n\t\t\t\t\t\t\t7  >>   Pathology\n\t\t\t\t\t\t\t8  >>	About us\n\t\t\t\t\t\t\t9  >>	Exit";
		cout<<"\n\t\t\t\t\t\t\t------------------------------------------------------------\n";
		cout<<"\t\t\t\t\t\t\tENTER YOUR CHOICE: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				p.emergency();
				system("cls");
				break;
			case 2:			
					p.getadmit();
					break;
				
			case 3:
				d.makeappointment();
				break;	
			case 5:
				p.search();
				break;
			case 7:
				p.pathalogy();
				break;
			case 8:
				d.about();
				break;
			case 4:
				p.display();
				break;
			case 6:
				p.discharge();
				break;
			case 9:
				break;	
		}
	}while(ch!=8);
	

cout<<"\t\t\t\t\t_______________________________________________________________________________________ \n";
cout<<"\t\t\t\t\t                                           		                                \n";
cout<<"\t\t\t\t\t                                           		                                \n";
cout<<"\t\t\t\t\t                                           		                                \n";
cout<<"\t\t\t\t\t                               THANK YOU FOR VISITNG US                                \n";
cout<<"\t\t\t\t\t                                                                                       \n";
cout<<"\t\t\t\t\t                                                                                       \n";
cout<<"\t\t\t\t\t_______________________________________________________________________________________\n";


	return 0;
}




