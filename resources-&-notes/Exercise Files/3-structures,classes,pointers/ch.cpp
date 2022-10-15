# include <iostream>

using namespace std;

class Student {
    public:
        Student(string id_, string name_) {
            id=id_;
            name=name_;
        }
    public:
        string get_name() {
            return name;
        }
    private:
        string name;
        string id;
};

class Course {
    public:
        Course(string id_, string name_, int credits_) {
            id=id_;
            name=name_;
            credits=credits_;
        }

    private:
        string id;
        string name;
        int credits;
};

int main() {
    Student* me = new Student("12345", "Alien");
    cout << me->get_name() << "\n";
    return 0;
}