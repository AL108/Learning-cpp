// Learning C++ 
// Challenge 04_05
// Calculate a GPA, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include "records.h"

using namespace std;

vector<Student> students = {Student(1,"George P. Burdell"),
							Student(2,"Nancy Rhodes")};

vector<Course> courses = {Course(1,"Algebra",5),
						  Course(2,"Physics",4),
						  Course(3,"English",3),
						  Course(4,"Economics",4)};

vector<Grade> grades = {Grade(1,1,'B'),	Grade(1,2,'A'),	Grade(1,3,'C'),
						Grade(2,1,'A'),	Grade(2,2,'A'), Grade(2,4,'B')};

float GPA = 0.0f;
int id;

int main(){
	cout << "Enter a student ID: ";
	cin >> id;

	// Calculate the GPA for the selected student.
	// Write your code here

	string student_str;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].get_id() == id) {
			student_str = students[i].get_name();
		}
	}
	int credits = 0;	
	int cur_credits = 0;
	for (int i = 0; i < grades.size(); i++) {
		if (grades[i].get_student_id() == id) {
			for (int j = 0; j < courses.size(); j++) {
				if (courses[j].get_id() == grades[i].get_course_id()) {
					cur_credits = courses[j].get_credits();
					credits += cur_credits;
					break;
				}
			}
			GPA += ((4 - (grades[i].get_grade() - 65)) * cur_credits); // ascii offset
		}
	}
	GPA /= credits;
	cout << "The GPA for " << student_str << " is " << GPA << endl;
	return (0);
}




