//
//  Course.h
//  OOP Project
//
//  Created by Shabeeh Abbas on 12/12/2023.
//

#ifndef Course_h
#define Course_h

class Student;

#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "Student.h"

class Course {
    friend class FileHandler;
private:
    string code;
    string name;
    string instructor;
    int credits;
    int capacity;
    int regStudents = 0;
    Student** students;

public:
    static int totalCourses;
    Course(string cd, string n, string inst, int cr, int cap);
    // Add methods to add, remove, display students enrolled in the course, etc.
    
    // getter
    string getCode();
    string getName();
    string getInstructor();
    int getCredits();
    int getCapacity();
    int getRegStudents();
    
    //setter

    void removeStudent(Student* student);
    void addStudent(Student* student);
};
#endif /* Course_h */
