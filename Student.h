//
//  Student.h
//  OOP Project
//
//  Created by Shabeeh Abbas on 12/12/2023.
//


#ifndef Student_h
#define Student_h

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Course;

class Student {
    friend class FileHandler;
private:
    string name;
    string roll_num;
    int age;
    string contact;
    int registeredCourses;
    Course** courses;
    // Add other attributes like attendance and marks as needed

public:
    static int totalStudents;
    Student(string n, string r, int a, string c, int rC);
    void removeCourse(Course* course);
    // Add methods to enroll, register, withdraw, mark attendance, assign marks, etc.
    
    // getters
    string getRollNum();
    string getName();
    int getAge();
    string getContact();
    Course** getCourses();
    
    int getRegisteredCourses();
    
    //setters
    void setName(string str);
    void setRollNum(string rollNum);
    void setAge(int a);
    void setContact(string str);
    void setRegisteredCourses(int rC);
    void addCourse(Course* course);
    
};
#endif /* Student_h */
