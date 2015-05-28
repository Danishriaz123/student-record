/*
Grant H Slape
Programming Fundamentals II
Dr. Karina Hernandez
12/4/14

Student Record class:
Will contain structure for new list nodes.  will also contain adding and sorting methods.  
*/
#ifndef STUDENT_RECORD_H
#define STUDENT_RECORD_H
#include <string>
#include <fstream>
#include <iostream>
#include <cstddef>
#include <iomanip>
using namespace std;

	struct Student
	{
		int ID;
		string name;
		string email;
		string phone;
		string major;
		string status;
		Student * next;
		Student(int a=12345, string b="Testy", string c="fixthis@hotmail.com", string d="5129487222", string e="CI", string f="FT", Student * n = NULL)	//Constructor
		{
			ID = a;		name = b;	email = c;	phone = d;	major = e;	status = f;	next = n;
		}
		Student(const Student&old, Student * ptr = NULL)	//Special copy constructor so that pointers are not copied.
		{
			ID = old.ID;	name=old.name;	email=old.email;	phone = old.phone;	major = old.major;	status = old.status;	next = 	ptr;
		}
	};
class StudentRecord
{
	protected:
		Student *head; //Must have a head
		Student * add(Student * aList, Student newStudent);	//Private function because main does not need to interact with the list except
		Student * remove(Student * aList, int value);		//With the class object itself.
		Student * search(Student * aList, int value);
		void display(Student * ptr);
		void edit(Student * ptr);	
	
	public:
		StudentRecord(){	head = NULL;	}	//Default constructor for empty list
		~StudentRecord(); 						//Destructor will traverse and delete
		
		void add(Student newStudent) {	head = add(head, newStudent);	}	//Returns a modified list to be pointed to by head
		void remove(int value)	{	head = remove(head, value);}
		void deleteAll();
		void displayAll();
		void search(int value)	{	display(search(head, value));}	//Will search and display selected record.
		void update(int value);
		string getEmail();
		string getPhone();
		string getMajor();
		string getStatus();
		bool free(int value);
		void writeList(ofstream & oFile);
	
};

#endif
