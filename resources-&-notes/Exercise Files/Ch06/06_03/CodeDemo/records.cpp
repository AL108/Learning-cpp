#include "records.h"
#include <iostream>
#include <fstream>

using namespace std;

Student::Student(int the_id, string the_name){
	id = the_id;
	name = the_name;
}
int Student::get_id(){
	return id;
}
string Student::get_name(){
	return name;
}

Course::Course(int the_id, string the_name, unsigned char the_credits){
	id = the_id;
	name = the_name;
	credits = the_credits;
}
int Course::get_id(){
	return id;
}
string Course::get_name(){
	return name;
}
int Course::get_credits(){
	return credits;
}


Grade::Grade(int sid, int cid, char grd){
	student_id = sid;
	course_id = cid;
	grade = grd;
}
int Grade::get_student_id(){
	return student_id;
}
int Grade::get_course_id(){
	return course_id;
}
char Grade::get_grade(){
	return grade;
}

void StudentRecords::add_student(int sid, string sname){
	students.push_back(Student(sid, sname));
}

void StudentRecords::add_course(int cid, string cname, unsigned char ccredits){
	courses.push_back(Course(cid, cname, ccredits));
}

void StudentRecords::add_grade(int sid, int cid, char grade){
	grades.push_back(Grade(sid, cid, grade));
}

float StudentRecords::get_num_grade(char letter){
	float num_grd;          // float for the numeric grade
	switch (letter){
	case 'A': num_grd = 4.0f;
		break;
	case 'B': num_grd = 3.0f;
		break;
	case 'C': num_grd = 2.0f;
		break;
	case 'D': num_grd = 1.0f;
		break;
	default:  num_grd = 0.0f;
		break;
	};
	return num_grd;
}

string StudentRecords::get_student_name(int sid){
	int i = 0;
	while (i < students.size() && students[i].get_id() != sid)
		i++;
	return students[i].get_name();
}

unsigned char StudentRecords::get_course_credits(int cid){
	int j = 0;
	while (j < courses.size() && courses[j].get_id() != cid)
		j++;
	return courses[j].get_credits();
}

float StudentRecords::get_GPA(int sid){
	float points = 0.0f, credits = 0.0f;
	for (Grade& grd : grades)
		if (grd.get_student_id() == sid){
			// calculate total credits and points
			unsigned char current_credits = get_course_credits(grd.get_course_id());
			credits += current_credits;
			points += get_num_grade(grd.get_grade()) * current_credits;
		}
	return (points / credits);
}

string StudentRecords::get_course_name(int cid){
	int j = 0;
	while (j < courses.size() && courses[j].get_id() != cid)
		j++;
	return courses[j].get_name();
}

void StudentRecords::report_card(int sid){
	float points = 0.0f, credits = 0.0f;
	cout << endl << "Report Card for " << get_student_name(sid) << endl;
	for (Grade& grd : grades)
		if (grd.get_student_id() == sid){
			cout << get_course_name(grd.get_course_id()) << ": " << grd.get_grade() << endl;
			unsigned char current_credits = get_course_credits(grd.get_course_id());
			credits += current_credits;
			points += get_num_grade(grd.get_grade()) * current_credits;
		}
	cout << "GPA: " << (points / credits) << endl;
}

void StudentRecords::load_records() {
	ifstream inFile;
	string fileErrorMsg = "failed does not exist";
	string inLine = "";
	// read in students
	int sid;
	string name;
	inFile.open("students.txt");
	if (inFile.fail()) cout << fileErrorMsg << endl;
	else {
		while (!inFile.eof()) {
			getline(inFile, inLine);
			sid = stoi(inLine);
			getline(inFile, inLine);
			name = inLine;	
			add_student(sid, name);
		}
	}
	inFile.close();

	// read in grades
	// int sid;
	int cid;
	char grade;
	inFile.open("grades.txt");
	if (inFile.fail()) cout << fileErrorMsg << endl;
	else {
		while (!inFile.eof()) {
			getline(inFile, inLine);
			sid = stoi(inLine);
			getline(inFile, inLine);
			cid = stoi(inLine);
			getline(inFile, inLine);
			grade = inLine[0];
			add_grade(sid, cid, grade);
			// cout << to_string(sid) << " " << to_string(cid) << " " << grade << endl;
		}
	}
	inFile.close();

	// read in courses
	// int cid;
	// string name;
	
	unsigned char credits;
	inFile.open("courses.txt");
	if (inFile.fail()) cout << fileErrorMsg << endl;
	else {
		while (!inFile.eof()) {
			getline(inFile, inLine);
			cid = stoi(inLine);
			cout << "cid: " << to_string(cid) << "|\n";
			getline(inFile, name);
			cout << "name: " << name << "|" << endl;
			getline(inFile, inLine);
			credits = stoi(inLine);
			cout << "cid: " << to_string(cid) << " name: " << name << " credits: " << to_string(credits) << endl;
			add_course(cid, name, 1);
			// cout << to_string(cid) << " " << name << to_string(credits) << endl;
		}
		
	}
	inFile.close();
}