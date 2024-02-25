//
//  System.cpp
//  OOP Project
//
//  Created by Shabeeh Abbas on 12/12/2023.
//

#include "Validator.h"
#include "System.h"
#include "FileHandler.h"


void System::displayMainMenu() {
    int option;
    do {
        std::cout << "Main Menu\n\n";
        std::cout << "1- Enroll a student\n";
        std::cout << "2- Course Registration\n";
        std::cout << "3- Attendance\n";
        std::cout << "4- Marks\n";
        std::cout << "5- Course Withdraw\n";
        std::cout << "6- Exit\n";
        std::cout << "Press 1 to 6 to select an option: ";

        std::cin >> option;

        switch (option) {
            case 1:
                displayEnrollStudentMenu();
                break;
            case 2:
                displayCourseRegistrationMenu();
                break;
            case 3:
                //displayAttendanceMenu();
                break;
            case 4:
                //displayMarksMenu();
                break;
            case 5:
                displayCourseWithdrawMenu();
                break;
            case 6:
                std::cout << "Exiting...\n";
                
                break;
            default:
                std::cout << "Invalid option. Please select again.\n";
                break;
        }
    } while (option != 6);
}

void System::displayEnrollStudentMenu() {
    int option;
    do {
        cout << "\nEnroll a Student\n\n";
        cout << "1- Display already enrolled students\n";
        cout << "2- Add a student\n";
        cout << "3- Remove a student\n";
        cout << "4- Edit student details\n";
        cout << "5- Back\n";
        cout << "Press 1 to 5 to select an option: ";

        cin >> option;

        switch (option) {
            case 1:
                displayAllEnrolledStudents();
                break;
            case 2:
                enrollStudent();
                break;
            case 3:
                removeStudent();
                break;
            case 4:
                editStudent();
                break;
            case 5:
                std::cout << "Going back to the main menu...\n";
                return; // Return to the main menu
            default:
                std::cout << "Invalid option. Please select again.\n";
                break;
        }
    } while (option != 5);
}

void System::displayCourseRegistrationMenu()
{
    int option;
    do {
        cout << "\Course Registration\n\n";
        cout << "1- Display All Courses\n";
        cout << "2- Register a Course\n";
        cout << "3- Back\n";
        cout << "Press 1 to 3 to select an option: ";

        cin >> option;

        switch (option) {
        case 1:
            displayAllCourses();
            break;
        case 2:
            registerCourse();
            break;
        case 3:
            std::cout << "Going back to the main menu...\n";
            return; // Return to the main menu
        default:
            std::cout << "Invalid option. Please select again.\n";
            break;
        }
    } while (option != 5);
}

void System::displayCourseWithdrawMenu()
{
    int option;
    do {
        cout << "\Course Withdrawal\n\n";
        cout << "1- Display All Enrolled Courses\n";
        cout << "2- Withdraw a Course\n";
        cout << "3- Back\n";
        cout << "Press 1 to 3 to select an option: ";

        cin >> option;

        switch (option) {
        case 1:
            displayEnrolledCourses();
            break;
        case 2:
            withdrawCourse();
            break;
        case 3:
            std::cout << "Going back to the main menu...\n";
            return; // Return to the main menu
        default:
            std::cout << "Invalid option. Please select again.\n";
            break;
        }
    } while (option != 5);
}

void System::displayAllEnrolledStudents() {
    cout << "\nList of Enrolled Students\n";

    // Loop through the 'students' vector and display student details
    for (int i = 0; i < Student::totalStudents; i++) {
        cout << "Name: " << students[i]->getName() << endl;
        cout << "Roll Number: " << students[i]->getRollNum() << endl;
        cout << "Age: " << students[i]->getAge() << endl;
        cout << "Contact: " << students[i]->getContact() << endl;

        // Display enrolled courses
        std::cout << "Enrolled Courses:\n\n";
        Course** courses = students[i]->getCourses();
        int n = students[i]->getRegisteredCourses();
        for (int i = 0; i < n; i++) {
            cout << " - " << courses[i]->getName() << endl;
        }

        cout << "-----------------\n\n";
    }
}

void System::displayAllCourses()
{
    cout << "\nList of Availaible Courses\n";
    int size = Course::totalCourses;
    for (int i = 0; i < size; i++)
    {
        cout << "Name: " << courses[i]->getName() << endl;
        cout << "Code: " << courses[i]->getCode() << endl;
        cout << "Instructor: " << courses[i]->getInstructor() << endl;
        cout << "Credit Hours: " << courses[i]->getCredits() << endl;
        cout << "Total Registered Students: " << courses[i]->getRegStudents() << endl;
        cout << "Capacity: " << courses[i]->getCapacity() << endl;

        cout << "---------------------------------------------------\n\n";
    }
}

void System::displayEnrolledCourses()
{
    string rollNo;
    cout << "Enter Roll Number of Student: ";
    cin >> rollNo;

    Student* student = Validator::validateStudent(rollNo, students);
    if (student != NULL)
    {
        Course** courses = student->getCourses();
        cout << "Enrolled Courses:\n\n";
        int n = student->getRegisteredCourses();
        for (int i = 0; i < n; i++) {
            cout << " - " << courses[i]->getName() << " | " << courses[i]->getCode() << endl;
        }

        cout << "-----------------\n\n";
    }
    else
    {
        cout << "Student Does Not Exist\n";
    }
}

void System::withdrawCourse()
{
    string rollNo;
    cout << "Enter Roll Number of Student: ";
    cin >> rollNo;

    Student* student = Validator::validateStudent(rollNo, students);
    if (student != NULL)
    {
        string courseCode;
        cout << "Enter Code of Course: ";
        cin >> courseCode;

        Course* course = Validator::validateCourse(courseCode, courses);
        if (course != NULL)
        {
            student->removeCourse(course); // pointing the student to the course
            course->removeStudent(student);
            cout << "Student Registered Successfully\n";
        }
        else
        {
            cout << "Either Course Does Not Exist or the Input is Entered Incorrectly!\n";
        }

    }
    else
    {
        cout << "Student Does Not Exist\n";
    }
}

void System::loadDataFromFiles()
{
    string filename = "courses.txt";
    courses = FileHandler::readCoursesFromFile(filename);
    filename = "students.txt";
    students = FileHandler::readStudentFromFile(filename, courses);
    cout << "less go";
}

void System::enrollStudent()
{
    if(true)
    {
        string name, rollNo, contact;
        int age, registeredCourses;
        cout << "Enter Student Name: ";
        cin >> name;
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Contact Number: ";
        cin >> contact;
        cout << "Enter Number of Registered Courses: ";
        cin >> registeredCourses;
        
        Student* student = new Student(name, rollNo, age, contact, 0);
        
        for (int i = 0; i < registeredCourses; i++)
        {
            string courseCode;
            cout << "Enter Course Code for Course #" << i + 1 << ": ";
            cin >> courseCode;
            Course* course = Validator::validateCourse(courseCode, courses);
            if (course != NULL)
            {
                student->addCourse(course);
                course->addStudent(student);
            }
            else
            {
                cout << "Either Course Does Not Exist or the Input is entered Incorrectly!\n";
                i--;
                continue;
            }
            
        }

        Student** temp = new Student*[Student::totalStudents];
        for (int i = 0; i < Student::totalStudents; i++)
            temp[i] = students[i];
        students = NULL;
        students = new Student * [Student::totalStudents + 1];
        for (int i = 0; i < Student::totalStudents; i++)
            students[i] = temp[i];
        students[Student::totalStudents++] = student;
        
        // Aggregation is needed right now
        // validation is also needed
    }
}
void System::removeStudent()
{
    string rollNo;
    cout << "Enter Roll Numnber of Student(22L-6666): ";
    cin >> rollNo;
    
    // validate here
    if(true)
    {
        int index;
        for (int i = 0; i < Student::totalStudents; i++)
        {
            if (rollNo ==  students[i]->getRollNum())
                index = i;
        }
        Student* temp = students[index];
        for (int i = index; i < Student::totalStudents - 1; i++)
            students[i] = students[i + 1];
        
        Course** studCourses = temp->getCourses();
        for (int j = 0; j < temp->getRegisteredCourses(); j++)
            studCourses[j]->removeStudent(temp);
        
        // need to remove from courses as well
        delete temp;
        Student::totalStudents--;
        
        cout << "Student Removed Successfully\n";
    }
    
}
void System::editStudent()
{
    string rollNo;
    cout << "Enter Roll Number of the Student to Edit its Details: ";
    cin >> rollNo;

    Student* student = Validator::validateStudent(rollNo, students);
    if (student != NULL)
    {
        int option;
        do {
            cout << "\nWhich Detail do you Want to Change?\nNOTE: To Change Registered Courses, Go to Course Registration Menu\n\n";
            cout << "1- Name\n";
            cout << "2- Roll Number\n";
            cout << "3- Age\n";
            cout << "4- Contact\n";
            cout << "5- Back\n";
            cout << "Press 1 to 5 to select an option: ";

            cin >> option;
            string str;
            switch (option) {
            case 1:
                cout << "Enter New Name: ";
                cin >> str;
                student->setName(str);
                break;
            case 2:
                cout << "Enter New Roll No: ";
                cin >> str;
                student->setRollNum(str);
                break;
            case 3:
                cout << "Enter New Name: ";
                int age;
                cin >> age;
                student->setAge(age);
                break;
            case 4:
                cout << "Enter New Contact: ";
                cin >> str;
                student->setContact(str);
                break;
            case 5:
                std::cout << "Going back to the main menu...\n";
                return; // Return to the main menu
            default:
                std::cout << "Invalid option. Please select again.\n";
                break;
            }
        } while (option != 5);
    }
    else
    {
        cout << "Either Student Does Not Exist or the Roll Number was Entered Incorrectly!\n";
    }
}

void System::registerCourse()
{
    
    string rollNo;
    cout << "Enter Roll Numnber of Student(22L-6666): ";
    cin >> rollNo;
    
    Student* student = Validator::validateStudent(rollNo, students);
    if(student != NULL)
    {
      /*  int index;
        for (int i = 0; i < Student::totalStudents; i++)
        {
            if (rollNo ==  students[i]->getRollNum())
                index = i;
        }*/
        
        string courseCode;
        cout << "Enter Code of Course: ";
        cin >> courseCode;

        Course* course = Validator::validateCourse(courseCode, courses);
        if (course != NULL)
        {
            student->addCourse(course); // pointing the student to the course
            course->addStudent(student);
            cout << "Student Registered Successfully\n";
        }
        else
        {
            cout << "Either Course Does Not Exist or the Input is Entered Incorrectly!\n";
        }
        
    }
    else
    {
        cout << "Either Student Does Not Exist or the Input is Entered Incorrectly!\n";
    }
}
