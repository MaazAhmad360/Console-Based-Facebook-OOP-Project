//
//  Validator.cpp
//  OOP Project
//
//  Created by Shabeeh Abbas on 12/12/2023.
//
#include "Course.h"
#include "Student.h"
#include "Validator.h"

Course* Validator::validateCourse(string courseCode, Course** courses)
{
	for (int i = 0; i < Course::totalCourses; i++)
	{
		if (courses[i]->getCode() == courseCode)
			return courses[i];
	}
	return NULL;
}
Student* Validator::validateStudent(string studRollNo, Student** students)
{
	for (int i = 0; i < Student::totalStudents; i++)
	{
		if (students[i]->getRollNum() == studRollNo)
			return students[i];
	}
	return NULL;
}