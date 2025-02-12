#include <iostream>
#include "Student.h"
#include <fstream>
#include "json.hpp" // Include the JSON library
using namespace std;
using json= nlohmann :: json;

void assignCourseToStudent(Student& s, const Course& c){
    s.course = c;
}
const Student* compareStudents(const Student& s1, const Student& s2){
    if(s1.gpa >= s2.gpa){
        //cout<<"\n\t\t\tStudent 1"<<endl;
        return &s1;
    }else{
        //cout<<"\n\t\t\tStudent 2"<<endl;
        return &s2;
    }
}

void saveToFile(const Student& studentObj, const string& filename) {
    json j;
    j["name"] = studentObj.name;
    j["age"] = studentObj.age;
    j["gpa"] = studentObj.gpa;
    j["course"]["courseName"] = studentObj.course.courseName;
    j["course"]["code"] = studentObj.course.courseCode;

    ofstream file(filename);
    if(file.is_open()){
        file<<j.dump(4);
        file.close();
        cout<<"\n\t\t\tStudent data saved to "<<filename<<endl;
    } else
        cout<<"Error opening file!"<<endl;
}

void loadFromFile(Student* studentObj, const string& filename) {
    ifstream Myfile(filename);
    if(!Myfile.is_open()){
        cout<<"Error opening file!"<<endl;
        return;
    }
    json j;
    Myfile>>j;
    studentObj->name = j["name"];
    studentObj->age = j["age"];
    studentObj->gpa = j["gpa"];
    studentObj->course.courseName = j["course"]["courseName"];
    studentObj->course.courseCode = j["course"]["code"];
    Myfile.close();
    cout<<"\n\t\t\tStudent data loaded from "<<filename<<endl;
}
void updateGPA(Student& s, float newGPA) {
    s.gpa = newGPA;
    cout<<"\n\t\t\tGPA of "<<s.name<<" updated to: "<<s.gpa<<endl;
}





