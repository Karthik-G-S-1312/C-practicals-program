#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

class Student
{
public:
    string name;
    int mark;
    char grade;

    Student(string n, int m, char g = ' ')
    {
        name = n;
        mark = m;
        grade = g;
    }
};

int main()
{
    vector<Student> students =
    {
        {"Karthik", 92, ' '},
        {"Sundar", 84, ' '},
        {"Anush", 73, ' '},
        {"Rakesh", 65, ' '},
        {"Rambabu", 54, ' '}
    };

    // Sort students by marks in descending order
    sort(students.begin(), students.end(),
         [](Student a, Student b)
         {
             return a.mark > b.mark;
         });

    // Assign grades
    transform(students.begin(), students.end(), students.begin(),
              [](Student s)
              {
                  if (s.mark >= 90)
                      s.grade = 'A';
                  else if (s.mark >= 75)
                      s.grade = 'B';
                  else if (s.mark >= 50)
                      s.grade = 'C';
                  else
                      s.grade = 'F';

                  return s;
              });

    // Find the first student scoring above 80
    vector<Student>::iterator it =
        find_if(students.begin(), students.end(),
                [](Student s)
                {
                    return s.mark > 80;
                });

    // Calculate total marks
    int total = accumulate(students.begin(), students.end(), 0,
                           [](int sum, Student s)
                           {
                               return sum + s.mark;
                           });

    double average = static_cast<double>(total) / students.size();

    cout << "Student Grade Analyzer\n";
    cout << "----------------------\n";
    cout << "Name\tMark\tGrade\n";

    for (Student s : students)
        cout << s.name << "\t" << s.mark << "\t" << s.grade << endl;

    if (it != students.end())
        cout << "\nFirst student scoring above 80: " << it->name << endl;

    cout << "Total Marks: " << total << endl;
    cout << "Average Mark: " << average << endl;

    return 0;
}