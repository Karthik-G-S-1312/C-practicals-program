#include <iostream>
#include <string>
using namespace std;
class Student {
private:
    int rollNo;
    std::string name;
public:
    Student(int roll, std::string studentName) : rollNo(roll), name(std::move(studentName)) {
        std::cout << "Student object created\n";
    }
    void display() const {
        std::cout << "Roll Number: " << rollNo << '\n'
                  << "Name: " << name << '\n';
    }
    ~Student() { std::cout << "Student object destroyed\n"; }
};
int main() {
    int nu;
    cout << "Enter the number of students: ";
    cin >> nu;
    for (int i = 0; i < nu; ++i) {
        int id;
        string name;
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> id;
        cout << "Name: ";
        cin >> name;              
        Student stu1 (id, name);
        stu1.display();
    }
    return 0;
}
