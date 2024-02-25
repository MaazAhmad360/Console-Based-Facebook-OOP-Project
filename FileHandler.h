//
//  FileHandler.h
//  OOP Project
//
//  Created by Shabeeh Abbas on 12/12/2023.
//

#ifndef FileHandler_h
#define FileHandler_h

#include <string>
#include <fstream>
using namespace std;

class Student;
class Course;

class FileHandler {
private:

public:
    static Student** readStudentFromFile(string filename, Course** courses);
    static Course** readCoursesFromFile(string filename);
    // Add methods to read and write data to and from the file
};
#endif /* FileHandler_h */
