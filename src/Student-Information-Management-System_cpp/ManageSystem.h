#pragma once

#include <string>
#include <map>
using namespace std;

class Student
{
public:
	string name;
	string id;
	string birth;
	string department;
	string tel;

	Student() : name(""), id(""), birth(""), department(""), tel("") {}

	Student(string name, string id, string birth, string department, string tel)
		: name(name), id(id), birth(birth), department(department), tel(tel) {}
};

bool MainMenu();
void Load();
void Insertion();
void Save(map<string, Student>& students);
void Search();
void SearchByName();
void SearchByID();
void SearchByBirth();
void SearchByDepartment();
void ListAll();
/*  void SortingOption();*/
void PrintStudent(const Student& student);