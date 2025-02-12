#include <iostream>
#include "Student.h"
#include "json.hpp" // Include the JSON library
using namespace std;
using json= nlohmann :: json;

int main(){
    Course course1("OOP", 101);
    Student s1("Charlie", 18, 3.7, course1);

    Course course2("Maths", 102);
    Student s2("John", 18, 3.5, course2);

    const Student* topStudent = compareStudents(s1, s2);
    cout << "\n\t\t\t "<<topStudent->name << "is the top student!" << endl;

    saveToFile(s1, "student.json");
    loadFromFile(&s1, "student.json");
    // Display loaded data
    cout<<"\n\t\t\t=======================Student Data====================="<<endl;
    cout<< "\n\t\t\tName: "<<s1.name<<endl;
    cout<< "\n\t\t\tAge: "<<s1.age<<endl;
    cout<< "\n\t\t\tGPA: "<<s1.gpa<<endl;
    cout<< "\n\t\t\tCourse: "<<s1.course.courseName<<endl;
    cout<< "\n\t\t\tCode: "<<s1.course.courseCode<<endl;

    updateGPA(s1, 3.99) ;
    cout<<"\n\t\t\tAfter update: "<<s1.name<<"'s GPA = "<<s1.gpa<<endl;
    cout<<"\n\t\t\t========================================================"<<endl;

    return 0;
}