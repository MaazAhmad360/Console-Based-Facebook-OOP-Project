//
//  Validator.h
//  OOP Project
//
//  Created by Shabeeh Abbas on 12/12/2023.
//

#ifndef Validator_h
#define Validator_h

#include <iostream>
#include <string>
using namespace std;
class Course;
class Student;

class Validator {
private:

public:
    static Course* validateCourse(string courseCode, Course** courses);
    static Student* validateStudent(string studRollNo, Student** students);
    // Add methods to validate the input according to the type and constraints
};

#endif /* Validator_h */
