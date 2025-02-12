//test_functions.cpp
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
#include "catch.hpp"
#include "Student.h"

TEST_CASE("Assign course to student") {
    Course c1("Mathematics", 101);
    Student s1("Alice", 20, 3.5, c1);
    
    Course newCourse("Computer Science", 103);
    assignCourseToStudent(s1, newCourse);
    
    REQUIRE(s1.course.courseName == "Computer Science");
    REQUIRE(s1.course.courseCode == 103);
}

TEST_CASE("Compare students") {
    Course c1("Mathematics", 101);
    Course c2("Physics", 102);
    
    Student s1("Alice", 20, 3.5, c1);
    Student s2("Bob", 22, 3.8, c2);

    const Student* topStudent = compareStudents(s1, s2);
    REQUIRE(topStudent->name == "Bob");
}

TEST_CASE("Save student to file and load student from file") {
    Course c("Software Engineering", 201);
    Student s("Charlie", 21, 3.2, c);
    
    const string filename = "student_test.json";
    saveToFile(s, filename);
    
    Student loadedStudent;
    loadFromFile(&loadedStudent, filename);
    
    REQUIRE(loadedStudent.name == "Charlie");
    REQUIRE(loadedStudent.age == 21);
    REQUIRE(loadedStudent.gpa == 3.2f);
    REQUIRE(loadedStudent.course.courseName == "Software Engineering");
    REQUIRE(loadedStudent.course.courseCode == 201);
}

TEST_CASE("Update student GPA") {
    Course c("Software Engineering", 201);
    Student s("Charlie", 21, 3.2, c);
    
    updateGPA(s, 3.9);
    REQUIRE(s.gpa == 3.9f);
}
