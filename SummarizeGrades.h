/////////////////////////////// FILE HEADER ///////////////////////////////////
//
// Title: Summarize Grades Header
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
// This program is a Grade Summarizer, taking a file as input which contains
// students, grades, totals, and percentages. The program neatly organizes
// all the students information, such as name, total, and percentage, into
// maps, which later are used to output to a new file an organized, formatted
// summary of all the student's grades.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef SUMMARIZEGRADES_H
#define SUMMARIZEGRADES_H

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

// Creates a struct Name with the String values firstName and lastName
struct Name {
	string firstName; // Student's first name
	string lastName; // Student's last name
};

/**
 * Takes a file with specified filepath and processes its contents. Afterwards,
 * it reads the number of students and assignements and stores those values
 * in numberOfStudents and numberOfAssignments respectively. Then, the program
 * processes each student, storing their name in the studentNames map with the
 * key as their student ID and a value a structue {firstName, lastName}.
 * Then, it stores the scores each student's scores in the studentScores map
 * with key as student ID and value as a vector of integers to hold the scores.
 * 
 * @param inputFilepath The filepath for the desired file to be opened
 * @param *numberOfStudents Pointer to an int that stores the number of students
 * @param *numberOfAssignments Pointer to an int that stores the number of
 *		  					   assignments
 * @param &studentNames A map that will contain the students ID's and names
 * @param &studentScores A map that will contain the students ID's and scores
 */
void readGradeFile(const string inputFilepath, int *numberOfStudents, int *numberOfAssignments, 
map<int, Name> &studentNames, map<int, vector<int> > &studentScores);

/**
 * Takes the student names map, changing their first and last names to be
 * correctly formatted (first letter of each string is capitalized). 
 * 
 * @param &names Contains address to the map of the student's names
 */
void formatCaseOfNames(map<int, Name> &names);

/**
 * Computes the total score of the students scores as well as a final percentage,
 * storing them afterwards in the total and percent maps respectively.
 * 
 * @param &scores Address to the map with the student's scores
 * @param &total Address to a map where the student's total score will be added
 * @param &percent Address to a map where the student's final perecentage will be added.
 */
void computeTotalAndPercent(map<int, vector<int> > &scores, map<int, int> &total, map<int, float>
&percent);

/**
 * Writes all results neatly into a new file, organizing it by student, their name, and
 * their respective total score and percentages.
 * 
 * @param outputFilepath The filepath of the file to be written to
 * @param &names Address to the map containing all students names
 * @param &total Address to the map containing all students total score.
 * @param &percent Address to the map containing all students perecentages.
 */
void writeFormattedGrades(const string outputFilepath, map<int, Name> &names, map<int, int> &total,
map<int, float> &percent);

#endif // SUMMARIZEGRADES_H