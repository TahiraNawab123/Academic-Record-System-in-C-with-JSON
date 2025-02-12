#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
using namespace std;


struct Course{
    string courseName;
    int courseCode;
    //Defaulat Constructor
    Course(): courseName(""), courseCode(0){}
    //Parameterized Constructor
    Course(string s, int code): courseName(s), courseCode(code){}
};

struct Student{
    string name;
    int age;
    float gpa;
    Course course;
    // Default Constructor
    Student(): name(""),age(0), gpa(0.0), course(Course()){}
    //Parameterized Constructor
    Student(string n, int a, float g, Course c): name(n), age(a), gpa(g), course(c){}
};

void assignCourseToStudent(Student& s, const Course& c);
const Student* compareStudents(const Student& s1, const Student& s2);
void saveToFile(const Student& studentObj, const string& filename);
void loadFromFile(Student* studentObj, const string& filename) ;
void updateGPA(Student& s, float newGPA);
#endif //STUDENT_H
