#include<iostream>
#include<windows.h>
#include<string>
#include<conio.h>
#include<fstream>
#include<stdio.h>
using namespace std;
ofstream out;
ifstream in;

struct prob
{
	string registration;
	string problem;

}prob[100];
struct srudent_personal_information
{
	string name;
	string father_name;
	char day1, day2, month1, month2, year1, year2, year3, year4;
}bio[100];
struct student_record_by_institution
{
	string reg_no;
	string batch;
	char d1, d2, m1, m2, y1, y2, y3, y4;
	string department;

}reg[100];
struct student_record     //Structure declaration
{
	int atten[10];
	float gpa;
	string Disciplinary_Issues, jarmana;
	char da1, da2, mo1, mo2, ye1, ye2, ye3, ye4;
}student1[100]; // create array of sturture
void probi(int i)
{

	for (int j = i; j < i; j++)
	{
		if (true)
		{
			cout << "-------CHOOSE YOUR OPTION-------" << endl << endl << endl;
			cout << "1) Show Bio Data ." << endl;
			cout << "2) show records ." << endl;
			cout << "3) show your Disciplinary Issues. " << endl;
			cout << "4) submit any application to the HOD. " << endl;
			int v;
			cin >> v;
			switch (v)
			{
			case 1:
			{
				cout << "\n\n\n---------------------------------------------------------------------------\n\n";
				cout << "\n\t\t\t--{ BIO DATA }--\n\n\n";
				cout << "Student's Name :  " << bio[j].name << endl;
				cout << "Father's Name  :  " << bio[j].father_name << endl;
				cout << "Date of Birth  :  " << bio[j].day1 << bio[j].day2 << "/" << bio[j].month1 << bio[j].month2 << "/" << bio[j].year1 << bio[j].year2 << bio[j].year3 << bio[j].year4 << endl;
				cout << "\n\n\n---------------------------------------------------------------------------\n\n";
				cout << "\n\n\n---------------------------------------------------------------------------\n\n";
				out << "\n\t\t\t--{ BIO DATA }--\n\n\n";
				out << "Student's Name :  " << bio[j].name << endl;
				out << "Father's Name  :  " << bio[j].father_name << endl;
				out << "Date of Birth  :  " << bio[j].day1 << bio[j].day2 << "/" << bio[j].month1 << bio[j].month2 << "/" << bio[j].year1 << bio[j].year2 << bio[j].year3 << bio[j].year4 << endl;
				out << "\n\n\n---------------------------------------------------------------------------\n\n";

				break; }
			case 2:
			{
				cout << "\n\t\t\t--{Student's Record }--\n\n\n";
				cout << "Roll no        :  " << reg[j].batch << "i-";
				if (j > 9)
				{
					cout << "00" << j + 1;
				}
				else
				{
					cout << "000" << j + 1;
				}
				cout << "\n";
				cout << "Enrollment date:  " << reg[j].d1 << reg[j].d2 << "/" << reg[j].m1 << reg[j].m2 << "/" << reg[j].y1 << reg[j].y2 << reg[j].y3 << reg[j].y4 << endl;
				cout << "Batch          :  " << reg[j].batch << endl;
				cout << "department     :  " << reg[j].department << endl;
				cout << "GPA            :  " << student1[j].gpa; if (student1[j].gpa < 2.0){ cout << " (warning) "; }cout << endl;
				cout << "\n\n\n---------------------------------------------------------------------------\n\n";

				out << "\n\t\t\t--{Student's Record }--\n\n\n";
				out << "Roll no        :  " << reg[j].batch << "i-";
				if (j > 9)
				{
					out << "00" << j + 1;
				}
				else
				{
					out << "000" << j + 1;
				}

				out << "Enrollment date:  " << reg[j].d1 << reg[j].d2 << "/" << reg[j].m1 << reg[j].m2 << "/" << reg[j].y1 << reg[j].y2 << reg[j].y3 << reg[j].y4 << endl;
				out << "Batch          :  " << reg[j].batch << endl;
				out << "department     :  " << reg[j].department << endl;
				out << "GPA            :  " << student1[j].gpa; if (student1[j].gpa < 2.0){ cout << " (warning) "; }cout << endl;
				out << "\n\n\n---------------------------------------------------------------------------\n\n";

				break; }
			case 3:
			{
				cout << "\n\n\t\t\t--{Disciplinary_Issues }--\n\n";
				cout << "Disciplinary_Issues : " << student1[j].Disciplinary_Issues << endl;
				cout << "Fine                :    RS " << student1[j].jarmana << endl;
				cout << "Date of conduction  : " << student1[j].da1 << student1[j].da2 << "/" << student1[j].mo1 << student1[j].mo2 << "/" << student1[j].ye1 << student1[j].ye2 << student1[j].ye3 << student1[j].ye4;
				cout << "\n\n\n--------------------------------------------------------" << endl << endl;

				break; }
			case 4:
			{
				int l;
				cout << "______please select any of the following_____" << endl;
				cout << "1) leave. " << endl;
				cout << "2) Semester freeze" << endl;
				cout << "3) Permission for any EVENT organising." << endl;
				cout << "4) others" << endl;
				cin >> l;
				if (l == 1)
				{
					int b;
					cout << "----Reason for Leave----" << endl << endl << endl;
					cout << "1) Medical reasons " << endl;
					cout << "2) Wedding of blood relative" << endl;
					cout << "3) Death of blood relative" << endl;
					cout << "4) Family Problems" << endl;
					cin >> b;
					{
						if (b == 1)
						{
							prob[i].problem = "leave due to Medical reasons ";
						}
						if (b == 2)
						{
							prob[i].problem = "leave due to Wedding of blood relative";
						}
						if (b == 3)
						{
							prob[i].problem = "leave due to Death of blood relative";
						}
						if (b == 4)
						{
							prob[i].problem = "leave due to Family Problems";
						}
					}
								{
									if (l == 2)
									{
										prob[i].problem = "application for semester freeze ";
									}
									if (l == 3)
									{
										prob[i].problem = "permission for the organization of an EVENT in the University.";
									}
									if (l == 4)
									{
										string new_problem;
										cin >> new_problem;
										prob[i].problem = new_problem;
									}
								}
				}
				break; }
			default:
				cout << "please select the above mentioned applications , other wise meet the HOD." << endl;
				break;
			}
		}
		else{
			cout << "\n\n\t\t\tStudent data is not  found  " << endl;
			Beep(1000, 1000);
		}
	}
}

void disciplinary_Issues(int g)
{
	int l;
	string fine;
	char din1, din2, mahena1, mahena2, saal1, saal2, saal3, saal4;
	string issue;
	cout << "\n\n\t\tDisobedience\n\n" << endl;
	cout << "1)smoking      " << endl;
	cout << "2)No id card   " << endl;
	cout << "3)Fight        " << endl;
	cout << "4)misbehaviour " << endl;
	cout << "5)others       " << endl;
	cin >> l;

	if (l == 1){ fine = "500"; cout << "enter the date: "; din1 = _getch(); cout << din1; din2 = _getch(); cout << din2; cout << "/"; mahena1 = _getch(); cout << mahena1; mahena2 = _getch(); cout << mahena2; cout << "/"; saal1 = _getch(); cout << saal1; saal2 = _getch(); cout << saal2;  saal3 = _getch(); cout << saal3; saal4 = _getch(); cout << saal4 << "\n"; issue = "smoking"; }
	else if (l == 2){ fine = "200"; cout << "enter the date: "; din1 = _getch(); cout << din1; din2 = _getch(); cout << din2; cout << "/"; mahena1 = _getch(); cout << mahena1; mahena2 = _getch(); cout << mahena2; cout << "/"; saal1 = _getch(); cout << saal1; saal2 = _getch(); cout << saal2;  saal3 = _getch(); cout << saal3; saal4 = _getch(); cout << saal4 << "\n"; issue = "No id card"; }
	else if (l == 3){ fine = "1000";  cout << "enter the date: "; din1 = _getch(); cout << din1; din2 = _getch(); cout << din2; cout << "/"; mahena1 = _getch(); cout << mahena1; mahena2 = _getch(); cout << mahena2; cout << "/"; saal1 = _getch(); cout << saal1; saal2 = _getch(); cout << saal2;  saal3 = _getch(); cout << saal3; saal4 = _getch(); cout << saal4 << "\n"; issue = "Fight"; }
	else if (l == 4){ fine = "5000"; cout << "enter the date: "; din1 = _getch(); cout << din1; din2 = _getch(); cout << din2; cout << "/"; mahena1 = _getch(); cout << mahena1; mahena2 = _getch(); cout << mahena2; cout << "/"; saal1 = _getch(); cout << saal1; saal2 = _getch(); cout << saal2;  saal3 = _getch(); cout << saal3; saal4 = _getch(); cout << saal4 << "\n"; issue = "misbehaviour"; }
	else if (l == 5){ cout << "mention the act of misbehaviour : "; cin >> issue; cout << "\nenter the amount of fine : "; cin >> fine; cout << "enter the date: "; din1 = _getch(); cout << din1; din2 = _getch(); cout << din2; cout << "/"; mahena1 = _getch(); cout << mahena1; mahena2 = _getch(); cout << mahena2; cout << "/"; saal1 = _getch(); cout << saal1; saal2 = _getch(); cout << saal2;  saal3 = _getch(); cout << saal3; saal4 = _getch(); cout << saal4 << "\n"; }
	if (l == 1){ fine = "500"; out << "enter the date: "; din1 = _getch(); out << din1; din2 = _getch(); out << din2; out << "/"; mahena1 = _getch(); out << mahena1; mahena2 = _getch(); out << mahena2; out << "/"; saal1 = _getch(); out << saal1; saal2 = _getch(); out << saal2;  saal3 = _getch(); out << saal3; saal4 = _getch(); out << saal4 << "\n"; issue = "smoking"; }
	else if (l == 2){ fine = "200"; out << "enter the date: "; din1 = _getch(); out << din1; din2 = _getch(); out << din2; out << "/"; mahena1 = _getch(); out << mahena1; mahena2 = _getch(); out << mahena2; out << "/"; saal1 = _getch(); out << saal1; saal2 = _getch(); out << saal2;  saal3 = _getch(); out << saal3; saal4 = _getch(); out << saal4 << "\n"; issue = "No id card"; }
	else if (l == 3){ fine = "1000";  out << "enter the date: "; din1 = _getch(); out << din1; din2 = _getch(); out << din2; out << "/"; mahena1 = _getch(); out << mahena1; mahena2 = _getch(); out << mahena2; out << "/"; saal1 = _getch(); out << saal1; saal2 = _getch(); out << saal2;  saal3 = _getch(); out << saal3; saal4 = _getch(); out << saal4 << "\n"; issue = "Fight"; }
	else if (l == 4){ fine = "5000"; out << "enter the date: "; din1 = _getch(); out << din1; din2 = _getch(); out << din2; out << "/"; mahena1 = _getch(); out << mahena1; mahena2 = _getch(); out << mahena2; out << "/"; saal1 = _getch(); out << saal1; saal2 = _getch(); out << saal2;  saal3 = _getch(); out << saal3; saal4 = _getch(); out << saal4 << "\n"; issue = "misbehaviour"; }
	else if (l == 5){ out << "mention the act of misbehaviour : "; cin >> issue; out << "\nenter the amount of fine : "; cin >> fine; out << "enter the date: "; din1 = _getch(); out << din1; din2 = _getch(); out << din2; out << "/"; mahena1 = _getch(); out << mahena1; mahena2 = _getch(); out << mahena2; out << "/"; saal1 = _getch(); out << saal1; saal2 = _getch(); out << saal2;  saal3 = _getch(); out << saal3; saal4 = _getch(); out << saal4 << "\n"; }
	student1[g].Disciplinary_Issues = issue;
	student1[g].jarmana = fine;
	student1[g].da1 = din1;
	student1[g].da2 = din2;
	student1[g].mo1 = mahena1;
	student1[g].mo2 = mahena2;
	student1[g].ye1 = saal1;
	student1[g].ye2 = saal2;
	student1[g].ye3 = saal3;
	student1[g].ye4 = saal4;
}
void HOD_issues(int i)
{
	for (int k = 0; k<3; k++)
	{
		for (int j = 0; j<i; j++)
		{
			cout << "the application number " << j+1 << "is :" << prob[i].problem[j];
		}cout << endl;
	}
	char w;
	do
	{
		cout << "please select the application to take a review ";
		int g;
		cin >> g;
		prob[i].problem = "  ";
		cout << prob[i].problem << " is reviewed , and the meeting is held ! ";
		cout << "\nenter n to exit \n";
		cin >> w;
	} while (w != 'n');

}

void view_record_student(int i)
{

	for (int j = 0; j < i; j++)
	{
		if (true)
		{
			cout << "\n\n\n---------------------------------------------------------------------------\n\n";
			cout << "\n\t\t\t--{ BIO DATA }--\n\n\n";
			cout << "Student's Name :  " << bio[j].name << endl;
			cout << "Father's Name  :  " << bio[j].father_name << endl;
			cout << "Date of Birth  :  " << bio[j].day1 << bio[j].day2 << "/" << bio[j].month1 << bio[j].month2 << "/" << bio[j].year1 << bio[j].year2 << bio[j].year3 << bio[j].year4 << endl;
			cout << "\n\n\n---------------------------------------------------------------------------\n\n";
			cout << "\n\t\t\t--{Student's Record }--\n\n\n";
			cout << "Roll no        :  " << reg[j].batch << "i-";




			if (j > 9)
			{
				cout << "00" << j + 1;
			}
			else
			{
				cout << "000" << j + 1;
			}


			cout << "\n";
			cout << "Enrollment date:  " << reg[j].d1 << reg[j].d2 << "/" << reg[j].m1 << reg[j].m2 << "/" << reg[j].y1 << reg[j].y2 << reg[j].y3 << reg[j].y4 << endl;
			cout << "Batch          :  " << reg[j].batch << endl;
			cout << "department     :  " << reg[j].department << endl;
			cout << "GPA            :  " << student1[j].gpa; if (student1[j].gpa < 2.0){ cout << " (warning) "; }cout << endl;
			cout << "\n\n\n---------------------------------------------------------------------------\n\n";
			cout << "\n\n\t\t\t--{Disciplinary_Issues }--\n\n";
			cout << "Disciplinary_Issues : " << student1[j].Disciplinary_Issues << endl;
			cout << "Fine                :    RS " << student1[j].jarmana << endl;
			cout << "Date of conduction  : " << student1[j].da1 << student1[j].da2 << "/" << student1[j].mo1 << student1[j].mo2 << "/" << student1[j].ye1 << student1[j].ye2 << student1[j].ye3 << student1[j].ye4;
			cout << "\n\n\n--------------------------------------------------------" << endl << endl;

			out << "\n\n\n---------------------------------------------------------------------------\n\n";
			out << "\n\t\t\t--{ BIO DATA }--\n\n\n";
			out << "Student's Name :  " << bio[j].name << endl;
			out << "Father's Name  :  " << bio[j].father_name << endl;
			out << "Date of Birth  :  " << bio[j].day1 << bio[j].day2 << "/" << bio[j].month1 << bio[j].month2 << "/" << bio[j].year1 << bio[j].year2 << bio[j].year3 << bio[j].year4 << endl;
			out << "\n\n\n---------------------------------------------------------------------------\n\n";
			out << "\n\t\t\t--{Student's Record }--\n\n\n";
			out << "Roll no        :  " << reg[j].batch << "i-";




			if (j > 9)
			{
				out << "00" << j + 1;
			}
			else
			{
				out << "000" << j + 1;
			}


			out << "\n";
			out << "Enrollment date:  " << reg[j].d1 << reg[j].d2 << "/" << reg[j].m1 << reg[j].m2 << "/" << reg[j].y1 << reg[j].y2 << reg[j].y3 << reg[j].y4 << endl;
			out << "Batch          :  " << reg[j].batch << endl;
			out << "department     :  " << reg[j].department << endl;
			out << "GPA            :  " << student1[j].gpa; if (student1[j].gpa < 2.0){ cout << " (warning) "; }cout << endl;
			out << "\n\n\n---------------------------------------------------------------------------\n\n";
			out << "\n\n\t\t\t--{Disciplinary_Issues }--\n\n";
			out << "Disciplinary_Issues : " << student1[j].Disciplinary_Issues << endl;
			out << "Fine                :    RS " << student1[j].jarmana << endl;
			out << "Date of conduction  : " << student1[j].da1 << student1[j].da2 << "/" << student1[j].mo1 << student1[j].mo2 << "/" << student1[j].ye1 << student1[j].ye2 << student1[j].ye3 << student1[j].ye4;
			out << "\n\n\n--------------------------------------------------------" << endl << endl;

		}
	}
}

void showsomefunnigga(int i)
{
	if (i == 1)
		cout << "\n\n\n\n\n\n\n\t\t\t\tLOADING";
	for (int i = 0; i < 5; i++)
	{
		cout << ".";
		Sleep(500);
	}
	Sleep(1000);
	system("cls");

}
int add_record(int i)  //function defination
{
	cout << "\n\n\n---------------------------------------------------------------------------\n\n\n";
	cout << "\n\t\t\t--{ BIO DATA }--\n\n\n";
	cout << "Student's  Name               :   ";
	cin >> bio[i].name;
	out << bio[i].name;
	cout << "Father's Name                 :   ";
	cin >> bio[i].father_name;
	out << bio[i].father_name;
	cout << "Date of birth of the student  :   ";
	bio[i].day1 = _getch(); cout << bio[i].day1; bio[i].day2 = _getch(); cout << bio[i].day2; cout << "/";  bio[i].month1 = _getch(); cout << bio[i].month1; bio[i].month2 = _getch(); cout << bio[i].month2; cout << "/"; bio[i].year1 = _getch(); cout << bio[i].year1; bio[i].year2 = _getch(); cout << bio[i].year2;  bio[i].year3 = _getch(); cout << bio[i].year3; bio[i].year4 = _getch(); cout << bio[i].year4 << "\n";
	//out<<bio[i].day1 = _getch(); out << bio[i].day1; bio[i].day2 = _getch(); out << bio[i].day2; out << "/";  bio[i].month1 = _getch(); out << bio[i].month1; bio[i].month2 = _getch(); out << bio[i].month2; out << "/"; bio[i].year1 = _getch(); out << bio[i].year1; bio[i].year2 = _getch(); out << bio[i].year2;  bio[i].year3 = _getch(); out << bio[i].year3; bio[i].year4 = _getch(); out << bio[i].year4 << "\n";
	cout << "\n\n\n---------------------------------------------------------------------------\n\n\n";
	cout << "\n\t\t\t--{ REGISTERATION DATA }--\n\n\n";
	cout << "enter the date of enrolment   :   ";
	reg[i].d1 = _getch(); cout << reg[i].d1; reg[i].d2 = _getch(); cout << reg[i].d2; cout << "/";  reg[i].m1 = _getch(); cout << reg[i].m1; reg[i].m2 = _getch(); cout << reg[i].m2; cout << "/"; reg[i].y1 = _getch(); cout << reg[i].y1; reg[i].y2 = _getch(); cout << reg[i].y2; reg[i].y3 = _getch(); cout << reg[i].y3; reg[i].y4 = _getch(); cout << reg[i].y4 << "\n";
	reg[i].d1 = _getch(); out << reg[i].d1; reg[i].d2 = _getch(); out << reg[i].d2; out << "/";  reg[i].m1 = _getch(); out << reg[i].m1; reg[i].m2 = _getch(); out << reg[i].m2; out << "/"; reg[i].y1 = _getch(); out << reg[i].y1; reg[i].y2 = _getch(); out << reg[i].y2; reg[i].y3 = _getch(); out << reg[i].y3; reg[i].y4 = _getch(); out << reg[i].y4 << "\n";
	cout << "enter the department          :   ";
	cin >> reg[i].department;
	out << reg[i].department;
	cout << "enter the batch number        :   ";
	cin >> reg[i].batch;
	out << reg[i].batch;
	cout << "\n\n\n---------------------------------------------------------------------------\n\n\n";
	cout << "\n\t\t\t--{ STUDENT RECORD }--\n\n\n";
	cout << "Enter the gpa                 :   ";
	cin >> student1[i].gpa;
	out << student1[i].gpa;
	cout << "any Disciplinary Issues       :   ";
	char d;
	cout << "if any issues enter y if not n:   ";
	cin >> d;
	if (d == 'y' || d == 'Y')
	{
		disciplinary_Issues(i);

	}
	else
	{
		student1[i].Disciplinary_Issues = "no issues yet\n\n";
	}
	cout << endl << "-----------------------" << endl << endl;;
	cout << "student is Registered at ARN of : " << reg[i].batch << "i-";
	i = i + 1;
	if (i > 9)
	{
		cout << "00" << i;
	}
	else
	{
		cout << "000" << i;
	}
	cout << endl << "-----------------------" << endl << endl;


	out << endl << "-----------------------" << endl << endl;;
	out << "student is Registered at ARN of : " << reg[i].batch << "i-";
	i = i + 1;
	if (i > 9)
	{
		out << "00" << i;
	}
	else
	{
		out << "000" << i;
	}
	out << endl << "-----------------------" << endl << endl;

	return i;
}

void del_record()
{
	int index;
	cout << "Enter the ARN you want to delete\n";
	cout << "enter only enrollment number -i-0"; cin >> index;
	int i = index - 1;
	if (index > 9)
	{
		cout << reg[index].batch << "i-00" << index << endl;
	}
	else
	{
		cout << reg[index].batch << "i-000" << index << endl;
	}
	cout << endl << endl;

	bio[i].name = " ";
	reg[i].d1 = '-'; reg[i].d2 = '-'; cout << "/"; reg[i].m1 = '-'; reg[i].m2 = '-'; reg[i].y1 = '-'; reg[i].y2 = '-'; reg[i].y3 = '-'; reg[i].y4 = '-';
	reg[i].batch = " ";
	reg[i].department = " ";
	bio[i].day1 = '-'; bio[i].day2 = '-'; cout << "/"; bio[i].month1 = '-'; bio[i].month2 = '-'; bio[i].year1 = '-'; bio[i].year2 = '-'; bio[i].year3 = '-'; bio[i].year4 = '-';
	bio[i].father_name = " ";
	student1[i].gpa = 0.0;
	student1[i].Disciplinary_Issues = " ";
	student1[i].da1 = '-'; student1[i].da2 = '-'; cout << "/"; student1[i].mo1 = '-'; student1[i].mo2 = '-'; student1[i].ye1 = '-'; student1[i].ye2 = '-'; student1[i].ye3 = '-'; student1[i].ye4 = '-';;

}
void attendshow(char haaa[], int x)
{
	x = 20;
	cout << "date : ";
	for (int b = 1; b <= 23; b++)
	{
		if (b % 7 == 0)
		{
			continue;
		}
		else
		{
			cout << "[ " << b << " ]";
		}


	}
	cout << "\nAttendence:";
	for (int q = 0; q < 20; q++)
	{

		cout << "[ " << haaa[q] << " ]";
	}
}
void subjpres(int o){


	string j;
	for (int i = 0; i < 6; i++)
	{
		if (i == 0)
		{
			j = "Linear Algebra";
		}
		else if (i == 1)
		{
			j = "ITC";
		}
		else if (i == 2)
		{
			j = "ITC Lab";
		}
		else if (i == 3)
		{
			j = "Calculus";
		}
		else if (i == 4)
		{
			j = "Basic Electronic";
		}
		else if (i == 5)
		{
			j = "English";
		}
		int present = 0, absent = 0, late = 0;
		char hawhae[20];
		for (int q = 0; q < 20; q++)
		{
			cout << "subject: " << j << " :  " << "enter attendence A / P / L : "; hawhae[q] = _getch(); cout << hawhae[q] << "\n";
		}
		for (int q = 0; q < 20; q++)
		{
			if (hawhae[q] == 'P' || hawhae[q] == 'p')
			{
				present = present + 1;
			}
			else if (hawhae[q] == 'A' || hawhae[q] == 'a')
			{
				absent = absent + 1;
			}
			else if (hawhae[q] == 'L' || hawhae[q] == 'l')
			{
				late = late + 1;
			}
			else
			{
				q--;
				cout << "please enter again this is invalid key " << endl << endl;
			}
		}
		present = (((present + (late / 2)) * 100) / 20);
		(student1[o].atten[i] = present); cout << "\n\n--------------------------------------------------------\n\n"; cout << "subject: " << j << " : ";
		attendshow(hawhae, 20);
		cout << endl;
		cout << "--------------------------------------------------------" << endl << endl;
	}

}
int main()
{
	system("color 71");
	int a = 1;
	showsomefunnigga(a);
	cout << "\n\n\n\n\n\t\t\t\t W E L C O M E ";
	Sleep(5000);
	system("cls");
	out.open("noman.txt");
	int op = 0;
	int arn = 0;
	int count = 0, choice = 0;
	char option;
	while (op != 4){
		cout << "\n\n       ***Student Record***\n\n" << endl << endl;
		cout << "1)	 Head Of Department(HOD)" << endl;
		cout << "2)	 Faculity member        " << endl;
		cout << "3)	 Student                " << endl;
		cout << "4)	 Exit the programme     " << endl;
		cin >> op;
		Beep(500, 100);

		if (op == 1)
		{
			char pasword[6];
			cout << "enter the pasword to proceed " << endl;
			cout << "pasword :                    "; for (int i = 0; i < 6; i++){ pasword[i] = _getch(); cout << "*"; }                                         //pasword is hey123
			cout << "\n\n\n\n" << endl;
			if (pasword[0] == 'h'&&pasword[1] == 'e'&&pasword[2] == 'y'&&pasword[3] == '1'&&pasword[4] == '2'&&pasword[5] == '3')
			{

				system("color F0");
				cout << "\n\n\t\tWelcome...!\n\n" << endl << endl;
				while (choice != 4 && choice != 5)
				{

					cout << "***Student Record***" << endl << endl;
					cout << "Press 1 to Enter Record\n";
					cout << "Press 2 to Delete Record\n";
					cout << "Press 3 to View All records\n";
					cout << "Press 4 to back to Menu" << endl;
					cout << "Enter 5 to Quit\n";
					cout << "____________________________\n";
					cin >> choice;
					Beep(500, 100);
					if (choice == 1)
					{
						add_record(arn);
						arn++;

					}
					if (choice == 2)
					{
						del_record();
					}
					if (choice == 3)
					{
						view_record_student(arn);
						cout << "\n\n\n-------------------------------------\n\n\n";
						HOD_issues(arn);
					}

				}
			}
			else{
				system("cls");
				Beep(1000, 800);
				system("color 7C");
				cout << "\n\n\n\n\n\t\t\tinvalid pasword \n\n\n" << endl;
				Sleep(1000);
				system("cls");
			}
			system("color 71");
		}


		if (op == 3)
		{
			system("color F1");
			cout << "\n\n\t\t***Student Record***\n\n" << endl << endl;
			cout << "enter only enrollment number: i-0";
			int p;
			cin >> p;
			view_record_student(p);
			probi(p);
			cout << endl;
			string j;
			char stu[20];
			for (int i = 0; i < 6; i++)
			{
				if (i == 0)
				{
					j = "Linear Algebra";
				}
				else if (i == 1)
				{
					j = "ITC";
				}
				else if (i == 2)
				{
					j = "ITC Lab";
				}
				else if (i == 3)
				{
					j = "Calculus";
				}
				else if (i == 4)
				{
					j = "Basic Electronic";
				}
				else if (i == 5)
				{
					j = "English";
				}
				cout << "subject" << j << "\t:" << student1[p].atten[i] << "% ="; if (student1[p].atten[i] < 80){ cout << "your attendence is short your in debar list\n\n "; }
				cout << endl;
			}
			cout << "\n\n\n----------------------------------------------------------------\n\n\n" << endl;
		}
		if (op == 2)
		{
			system("color F0");
			char pascode[6];
			cout << "enter the pasword to proceed " << endl;
			cout << "pasword :                    "; for (int i = 0; i <6; i++){ pascode[i] = _getch(); cout << "*"; }             //pascode is why123
			if (pascode[0] == 'w'&&pascode[1] == 'h'&&pascode[2] == 'y'&&pascode[3] == '1'&&pascode[4] == '2'&&pascode[5] == '3')
			{
				system("color F0");
				cout << "\n\n\t\tWelcome...!";
				cout << "\n\n\n";
				while (choice != 5 && choice != 6)
				{

					cout << "\t\t\t***Student Record***\n\n" << endl;
					cout << "Press 1 to Enter Record\n";
					cout << "press 2 to enter attendence\n";
					cout << "Press 3 to Delete Record\n";
					cout << "Press 4 to View All records\n";
					cout << "Press 5 to back to Menu" << endl;
					cout << "Enter 6 to Quit\n";
					cout << "____________________________\n";
					cin >> choice;

					if (choice == 1)
					{
						add_record(arn);
					}
					if (choice == 2)
					{
						int r = 0;
						cout << "enter entrollment number  i-0";
						cin >> r;
						subjpres(r);

					}
					if (choice == 3)
					{
						del_record();
					}
					if (choice == 4)
					{
						view_record_student(arn);
					}

				}

			}
			else
			{
				system("cls");
				Beep(1000, 800);
				system("color 7C");
				cout << "\n\n\n\n\n\t\t\tinvalid pasword \n\n\n" << endl;
				Sleep(1000);
				system("cls");

			}
			system("color 71");
		}
	}
	out.close();
	return 0;
}
