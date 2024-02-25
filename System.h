//
//  System.h
//  OOP Project
//
//  Created by Shabeeh Abbas on 12/12/2023.
//

#ifndef System_h
#define System_h

#include "Student.h"
#include "Course.h"

class System {
private:
    Student** students;
    Course** courses;

public:
    //Display Methods
    void displayMainMenu();
    void displayEnrollStudentMenu();
    void displayCourseRegistrationMenu();
    void displayAttendanceMenu();
    void displayMarksMenu();
    void displayCourseWithdrawMenu();
    void performAction(int option);
    void saveDataToFile();
    void displayAllCourses();
    void displayAllEnrolledStudents();
    
    // Memory R/W Methods
    void loadDataFromFiles();
    
    // Enroll Student Menu Methods
    void enrollStudent();
    void removeStudent();
    void editStudent();
    
    // CourseRegistration Menu Methods
    void registerCourse();

    // Course Withdrawal Menu Methods
    void displayEnrolledCourses();
    void withdrawCourse();
};

#endif /* System_h */
