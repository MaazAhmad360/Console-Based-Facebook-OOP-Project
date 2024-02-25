//
//  Course.cpp
//  OOP Project
//
//  Created by Shabeeh Abbas on 12/12/2023.
//

#include "Course.h"


int Course::totalCourses = 0;

Course::Course(string cd, string n, string inst, int cr, int cap)
{
    code = cd;
    name = n;
    instructor = inst;
    credits = cr;
    capacity = cap;
}

string Course::getCode()
{
    return code;
}
string Course::getName()
{
    return name;
}
string Course::getInstructor()
{
    return instructor;
}
int Course::getCredits()
{
    return credits;
}
int Course::getCapacity()
{
    return capacity;
}
int Course::getRegStudents()
{
    return regStudents;
}

void Course::removeStudent(Student* student)
{
    if (true)
    {
        int index;
        for (int i = 0; i < regStudents; i++)
            if (students[i] == student)
            {
                for (int j = i; j < regStudents - 1; j++)
                    students[i] = students[i + 1];
                regStudents--;
            }
    }

}

void Course::addStudent(Student* student)
{
    
    if (regStudents > 0)
    {
        Student** temp = new Student*[regStudents];
        
        // expanding the array by first copying, deleting and increasing the size
        for (int i = 0; i < regStudents; i++)
        {
            temp[i] = students[i];
        }
        students = NULL;
        students = new Student*[regStudents + 1];
        
        
        for (int i = 0; i < regStudents; i++)
        {
            students[i] =  temp[i];
        }
    }
    else{
        students = new Student*[1];
    }
    
    students[regStudents] = student;
    regStudents++;
}

