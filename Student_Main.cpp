/*
Grant Slape
Programming Fundamentals II
Dr. Karina Hernandez
12/4/14
*/

#include "Student_Record.h"
#include <cstring>
#include <cstdlib>
#include <time.h>

using namespace std;

bool login();
int getChoice(char);
int getInput();
void displayMenu();
void addNode(StudentRecord &);

int main()
{
	while(!login())
	{}
	
	srand(time(NULL));
	const char MAX_CHOICE = '6';
	StudentRecord ourList;
	Student temp;
	string tempID;
	
	fstream dataFile("student_records.txt", ios::in);
	if(!dataFile)
		{
			cout<<"Creating new record!\n";
		}
	else
	{
		do
		{
			getline(dataFile, tempID, '$');
			temp.ID = atoi(tempID.c_str());
			getline(dataFile, temp.name, '$');
			getline(dataFile, temp.email, '$');
			getline(dataFile, temp.phone, '$');
			getline(dataFile, temp.major, '$');
			getline(dataFile, temp.status, '$');
			ourList.add(temp);
		}while(!dataFile.fail());
	}
	dataFile.close();
	ourList.remove(0); //Not sure why a dummy of the last value is being read it but this will remove it.
	char choice;
	int input;
	do
	{
		displayMenu();
		choice = getChoice(MAX_CHOICE);
		switch(choice)
		{
			case '1':	addNode(ourList);		//ADD STUDENT
			        	break;
			        	
			case '2':	cout<<"UPDATE\n";
						ourList.update(getInput());
						break;
			
			case '3':	cout<<"SEARCH\n";
						ourList.search(getInput());
						cout<<"Hit Enter to Continue:\n";
						cin.get();
						break;
					
			case '4':	cout<<"DELETE\n";
						ourList.remove(getInput());
						break;
						
			case '5':	ourList.displayAll();
						cout<<"Hit Enter to Continue:\n";
						cin.get();
						break;
		}
	}while(choice != '6');
	
	//Write the updated list to the file.
	ofstream outFile("student_records.txt");
	ourList.writeList(outFile);
	outFile.close();
	return 0;
}

void addNode(StudentRecord & aList)
{
	Student newStudent;
	int randID;
	do
	{
		randID = rand() % 90000 + 10000;
	}while(!aList.free(randID));//Checking if ID is taken
	
	newStudent.ID = randID;
	cout<<"Student #"<<randID <<endl;
	cout<<"Enter student name: ";
	getline(cin, newStudent.name);
	cout<<endl;
	newStudent.email = aList.getEmail();
	newStudent.phone = aList.getPhone();
	newStudent.major = aList.getMajor();
	newStudent.status = aList.getStatus();
	//add student to list
	aList.add(newStudent);
}

//Simple log on function.  
bool login()
{
	const string PASS = "hr_acc_2014";
	
	cout << "Please enter user name: ";
	string pword, user;
	getline(cin, user);
	cout << "Password: ";
	getline(cin, pword);
	for(int a = 0; a<user.length()-1; a++)
	{
		
		if(user.at(a) < 65 || (user.at(a) > 90 && user.at(a) <97) || user.at(a) > 122)	//Can be reused.  Checks that each char is a letter.
		{
				cout<<"Username incorrect!\n";
				return false;
		}
	}
	if(pword.compare(PASS) == 0)	return true;
	cout<<"Password incorrect!\n";
	return false;
}

void displayMenu()
{
	cout<<"*****ACC HR STUDENT MANAGEMENT*********\n"
		<<"Please select an option:\n"
		<<"1: Add new student\n"
		<<"2: Update student information\n"
		<<"3: Search record\n"
		<<"4: Delete a student\n"
		<<"5: Display complete record\n"
		<<"6: Exit\n";
}

int getChoice(char max)
{
	int choice = cin.get();
	cin.ignore();									
	while (choice < '1' || choice > max)
	{
		cout << "Please make a selection between 1 and " << max << endl;
		choice = cin.get();
	}//while (choice < 1 || choice > max)
	return choice;
} //int getChoice(max)

int getInput()
{
	int input;
	cout << "Please enter ID # ";
	cin>>input;
	cin.ignore();
	return input;
}
