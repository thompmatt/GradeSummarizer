/////////////////////////////// FILE HEADER ///////////////////////////////////
//
// Title: Summarize Grades Demo
// Files: SummarizeGrades.h, SummarizeGrades.cpp, demo.cpp, Makefile, README.md
// Course: CS 368, Spring 2020
//
// Author: Matt Thompson
// Student ID: 9081263262
// Email: mathompson23@wisc.edu
// Lecturer's Name: Marc Renault
//
// Online Sources: 
// - https://www.geeksforgeeks.org/inserting-elements-in-stdmap-insert-emplace
//	 	-and-operator/
//
// - https://www.geeksforgeeks.org/traversing-a-map-or-unordered_map-in-cpp-stl/
// 
// - https://stackoverflow.com/questions/8530529/convert-first-letter-in-string
// 		-to-uppercase
// 
// - http://www.cplusplus.com/reference/iomanip/setprecision/
// 
//////////////////////////// FILE DESCRIPTION /////////////////////////////////
// 
// This file demo's all the functions in the Grade Summarizer, calling all
// the functions in SummarizeGrades.cpp.
//
///////////////////////////////////////////////////////////////////////////////

#include "SummarizeGrades.h"
#include <iostream>

int main() {
	int * numberStudents = new int;
	int * numberAssignments = new int;
	map<int, Name> studentNames;
	map<int, vector<int> > studentScores;
	map<int, int> totals;
	map<int, float> percent;

	readGradeFile("unformatted_grades.txt", numberStudents, numberAssignments, studentNames, studentScores);
	formatCaseOfNames(studentNames);
	computeTotalAndPercent(studentScores, totals, percent);
	writeFormattedGrades("output.txt", studentNames, totals, percent);

	return 0;
}