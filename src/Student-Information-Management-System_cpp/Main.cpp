#include <bits/stdc++.h>
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

class MainClass
{
public:
	static map<string, Student> students;
	static bool MainMenu();
	static void Load();
	static void Insertion();
	static void Save(map<string, Student>& students);
	static void Search();
	static void SearchByName();
	static void SearchByID();
	static void SearchByBirth();
	static void SearchByDepartment();
	static void ListAll();
	/*static void SortingOption();*/
	static void PrintStudent(const Student& student);
};

map<string, Student> MainClass::students;

void MainClass::Load()
{
	ifstream reader("file1.txt");
	if (reader.is_open())
	{
		string line;
		while (getline(reader, line))
		{
			istringstream ss(line);
			string name, id, birth, department, tel;
			getline(ss, name, ',');
			getline(ss, id, ',');
			getline(ss, birth, ',');
			getline(ss, department, ',');
			getline(ss, tel);

			Student student(name, id, birth, department, tel);
			students[id] = student;
		}
		reader.close();
	}
}

bool MainClass::MainMenu()
{
	cout << "1. Insertion" << endl;
	cout << "2. Search" << endl;
	cout << "3. Sorting Option" << endl;
	cout << "4. Exit" << endl;
	cout << ">" << endl;

	int input;
	cin >> input;

	bool terminateFlag = true;
	switch (input)
	{
	case 1:
		Insertion();
		break;

	case 2:
		Search();
		break;

	/*case 3:
		SortingOption();
		break;*/

	case 4:
		cout << "프로그램을 종료합니다.";
		terminateFlag = false;
		break;
	}

	return terminateFlag;
}

void MainClass::Insertion()
{
	cout << "Name ";
	string name;
	cin.ignore();
	getline(cin, name);

	if (name.length() > 15)
	{
		throw invalid_argument("Student ID must be 10 digits");
	}

	cout << "Student ID (10 digits) ";
	string id;
	getline(cin, id);

	if (id.length() != 10)
	{
		throw invalid_argument("Student ID must be 10 digits");
	}

	cout << "Birth Year (4 digits) ";
	string birth;
	getline(cin, birth);

	if (birth.length() != 4)
	{
		throw invalid_argument("birth length must be 4 characters");
	}

	cout << "Department ";
	string department;
	getline(cin, department);

	cout << "Tel ";
	string tel;
	getline(cin, tel);

	if (students.find(id) != students.end())
	{
		cout << endl << "Error : Already inserted" << endl;
	}
	else
	{
		Student student(name, id, birth, department, tel);
		students[id] = student;
		/*students = SortByName(students);*/
		Save(students);
	}
	cout << endl;
}

void MainClass::Save(map<string, Student>& students)
{
	ofstream writer("file1.txt");
	if (writer.is_open())
	{
		for (const auto& studentPair : students)
		{
			const Student& student = studentPair.second;
			writer << student.name << "," << student.id << "," << student.birth << "," << student.department << "," << student.tel << endl;
		}
		writer.close();
	}
}

void MainClass::Search()
{
	cout << "1. Search by name" << endl;
	cout << "2. Search by student ID (10 numbers)" << endl;
	cout << "3. Search by admission year (4 numbers)" << endl;
	cout << "4. Search by department name" << endl;
	cout << "5. List All" << endl;
	cout << ">" << endl;

	int input;
	cin >> input;

	cout << endl;
	switch (input)
	{
	case 1:
		SearchByName();
		break;

	case 2:
		SearchByID();
		break;

	case 3:
		SearchByBirth();
		break;

	case 4:
		SearchByDepartment();
		break;

	case 5:
		ListAll();
		break;
	}
	cout << endl;
}

void MainClass::SearchByName()
{
	std::cout << "Name keyword? ";
	std::string name;
	std::cin.ignore();
	getline(std::cin, name);
	std::cout << std::endl;

	bool dataExist = false;

	for (const auto& studentPair : students) {
		const Student& student = studentPair.second;
		if (student.name == name) {
			PrintStudent(student);
			dataExist = true;
		}
	}
	if (!dataExist) {
		std::cout << "Data does not exist." << std::endl;
	}
}

void MainClass::SearchByID()
{
	cout << "ID keyword? ";
	string id;
	cin.ignore();
	getline(cin, id);
	cout << endl;

	bool dataExist = false;

	for (const auto& studentPair : students)
	{
		const Student& student = studentPair.second;
		if (student.id == id)
		{
			PrintStudent(student);
			dataExist = true;
		}
	}
	if (!dataExist)
	{
		cout << "Data does not exist." << endl;
	}
}

void MainClass::SearchByBirth()
{
	cout << "Birth keyword? ";
	string birth;
	cin.ignore();
	getline(cin, birth);
	cout << endl;

	bool dataExist = false;

	for (const auto& studentPair : students)
	{
		const Student& student = studentPair.second;
		if (student.birth == birth)
		{
			PrintStudent(student);
			dataExist = true;
		}
	}
	if (!dataExist)
	{
		cout << "Data does not exist." << endl;
	}
}

void MainClass::SearchByDepartment()
{
	cout << "Department name keyword? ";
	string department;
	cin.ignore();
	getline(cin, department);
	cout << endl;

	bool dataExist = false;

	for (const auto& studentPair : students)
	{
		const Student& student = studentPair.second;
		if (student.department == department)
		{
			PrintStudent(student);
			dataExist = true;
		}
	}
	if (!dataExist)
	{
		cout << "Data does not exist." << endl;
	}
}

void MainClass::ListAll()
{
	for (const auto& studentPair : students)
	{
		const Student& student = studentPair.second;
		PrintStudent(student);
	}
}

//void MainClass::SortingOption()
//{
//	cout << "1. Sort by name" << endl;
//	cout << "2. Sort by student ID" << endl;
//	cout << "3. Sort by Admission Year" << endl;
//	cout << "4. Sort by Department name" << endl;
//	cout << ">" << endl;
//
//	int input;
//	cin >> input;
//
//	cout << endl;
//	switch (input)
//	{
//	case 1:
//		students = SortByName(students);
//		cout << "Sort by name complete" << endl;
//		break;
//
//	case 2:
//		students = SortByID(students);
//		cout << "Sort by ID complete" << endl;
//		break;
//
//	case 3:
//		students = SortByBirth(students);
//		cout << "Sort by Admission Year complete" << endl;
//		break;
//
//	case 4:
//		students = SortByDepartment(students);
//		cout << "Sort by Department name complete" << endl;
//		break;
//	}
//	cout << endl;
//}

void MainClass::PrintStudent(const Student& student) {
	cout << student.name << " " << student.id << " " << student.department << " " << student.birth << " " << student.tel << endl;
}

int main() {
	if (ifstream("file1.txt")) {
		MainClass::Load();
	}

	while (MainClass::MainMenu()) {}

	return 0;
}
