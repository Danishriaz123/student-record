/*
Grant Slape
Programming Fundamentals II
Dr. Karina Hernandez
12/4/14

StudentRecord class definitions
*/

#include "Student_Record.h"

StudentRecord::~StudentRecord()
{
	deleteAll();
}
//Copy of destructor.
void StudentRecord::deleteAll()
{
	Student * nodePtr = head;
	while(nodePtr != NULL)//iterates til last pointer
	{					//Maybe write recursive version?
		Student *trash = nodePtr;
		nodePtr = nodePtr->next;
		delete trash;
	}
}

//display function used in search as well as update.
void StudentRecord::display(Student * ptr)
{
	if(ptr != NULL)
		cout << "ID #" << ptr->ID << "\t\t" << "Name: " <<setw(25) << ptr->name << endl
			<< "Email: " << setw(30) << ptr->email << "\t\tPh. #" << ptr->phone << endl
			<< "Major: " << ptr->major << "\t\tStatus(Full/Part): " << ptr->status <<endl;
	else
		cout<<"Student not found!\n";
}
/*
non recursive node adding function.
*/
Student * StudentRecord::add(Student * aList, Student newStudent)
{
	Student * nodePtr, *previousPtr;
	
	if(aList == NULL || aList->ID >= newStudent.ID)
		return new Student(newStudent, aList); //returns the new list to the head pointer
	else
	{
		previousPtr = head;
		nodePtr = head->next;
		
		while(nodePtr != NULL && nodePtr->ID < newStudent.ID)
		{
			previousPtr = nodePtr;	//Sorted insert
			nodePtr = nodePtr->next;
		}
		previousPtr->next = new Student(newStudent, nodePtr);	//Custom copy constructor takes second arg as pointer to next
	}
	
	return aList;
}
/*
recursive node removing function
*/
Student *StudentRecord::remove(Student * aList, int value)
{
	if(aList == NULL) return NULL;
	
	if(aList->ID == value)
	{
		Student *tail = aList->next;
		delete aList;
		return tail;
	}
	else
	{
		aList->next = remove(aList->next, value);	//VERY IMPORTANT THAT IT WORKS LIKE THIS
		return aList;	//THIS IS THE BASE CASE OF NOT BEING IN LIST  
	}
	
}

Student *StudentRecord::search(Student *aList, int value)
{
	if(aList == NULL) return NULL;		//recursive search.
	
	if(aList->ID == value)
		return aList;
	else
	{
		aList = search(aList->next, value);
		return aList;
	}
}

void StudentRecord::update(int value)
{
	Student *ptr = search(head, value);
	if(ptr == NULL)
	{
		cout<<"Student not found!";
	}
	else
	{
		display(ptr);
		cout<<"Which field would you like to edit?\n"
		<<" 1: Name\t 2: Email\n 3: Phone #\t 4: Major\n 5: Status\t 6: Exit\n";
		char choice = cin.get();
		cin.ignore();									
		while (choice < '1' || choice > '6')
		{
			cout << "Please make a selection between 1 and 6" << endl;
			choice = cin.get();
		}//while (choice < 1 || choice > max)
		
		switch(choice)
		{
			case '1':	cout<<"Please enter new name: ";
						getline(cin, ptr->name);
						break;
			
			case '2': 	ptr->email = getEmail();
						break;
			
			case '3':	ptr->phone = getPhone();
						break;
						
			case '4':	ptr->major = getMajor();
						break;
						
			case '5': 	ptr->status = getStatus();
						break;
		}
	}
}

void StudentRecord::displayAll()
{
	Student * nodePtr = head;
	cout<<"****COMPLETE STUDENT DATABASE*****\n";
	while(nodePtr != NULL)
	{
		display(nodePtr);
		nodePtr = nodePtr->next;
	}
}

void StudentRecord::writeList(ofstream & oFile)
{
	Student * ptr = head;
	while(ptr != NULL)
	{
		oFile<<ptr->ID<<'$'
			 <<ptr->name<<'$'
			 <<ptr->email<<'$'
			 <<ptr->phone<<'$'
			 <<ptr->major<<'$'
			 <<ptr->status<<"$\n";
		ptr = ptr->next;	
	}
}

string StudentRecord::getEmail()
{
	string temp;
	cout<<"Please enter new email address: ";
	cin>>temp;
	while(temp.find('@') == string::npos)
	{
		cout<<"Not a valid email! Please reenter:\n";
		cin>>temp;
	}
	return temp;
}

string StudentRecord::getPhone()
{
	string temp;
	bool flag;
	cout<<"Please enter new phone number(digits only): ";
	cin>>temp;
	cin.ignore();
	do
	{	
		flag = true;
		if(temp.length() != 10)
		{
			cout<<"Invalid length!\n";
			flag = false;
		}
		else
		{
			for(int a = 0; a < temp.length()-1; a++)
			{
				if (temp[a] < 48 || temp[a] > 57)
					flag =false;
			}
		}
		if(!flag)
		{
			cout<<"Reenter phone number(digits only): ";
			cin>>temp;
		}
	}while(!flag);
	return temp;
}

string StudentRecord::getMajor()
{   
	string temp;         
	cout<<"Please select a major:\n"
		<<"1: Computer Information Technology (CI)\n"
		<<"2: Visual Communication (VC)\n"
		<<"3: Business Administration (BA)\n";
	char choice = cin.get();
	cin.ignore();									
	while (choice < '1' || choice > '3')
	{
		cout << "Please make a selection between 1 and 3" << endl;
		choice = cin.get();
		cin.ignore();
	}//while (choice < 1 || choice > max)
	switch(choice)
	{
		case '1':	temp = "CI";
					break;
		case '2':	temp = "VC";
					break;
		case '3':	temp = "BA";
					break;
	}
	return temp;	
}

string StudentRecord::getStatus()
{
	string temp;
	cout<<"Full-time or Part-time student?\n"
		<<"1: FULL-TIME\n"
		<<"2: PART-TIME\n";
	int choice = cin.get();	
	cin.ignore();								
	while (choice < '1' || choice > '2')
	{
		cout << "Please make a selection between 1 and 2" << endl;
		choice = cin.get();
		cin.ignore();
	}//while (choice < 1 || choice > max)
	if(choice == '1')
		temp = "FT";
	else
		temp = "PT";
	return temp;
}

bool StudentRecord::free(int value)
{
	if(search(head, value) == NULL)
		return true;
	else
		return false;
}

