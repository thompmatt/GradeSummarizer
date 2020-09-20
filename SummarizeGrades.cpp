/////////////////////////////// FILE HEADER ///////////////////////////////////
//
// Title: Summarize Grades
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
// This file contains and defines all the functions stated in SummarizeGrades.h
// Contains the following methods:
// - readGradeFile()
// - formatCaseOfNames()
// - computeTotalAndPercent()
// - writeFormattedGrades()
//
///////////////////////////////////////////////////////////////////////////////

#include "SummarizeGrades.h"

void readGradeFile(const string inputFilepath, int *numberOfStudents, int *numberOfAssignments, 
map<int, Name> &studentNames, map<int, vector<int> > &studentScores) {
	ifstream file;
	file.open(inputFilepath);
	string line;
	string temp;
	string firstName;
	string lastName;
	int assignment;
	int ID = 0;
	int index = 0;
	
	if (file.is_open()) {
		while (getline(file, line)) {
			stringstream ss(line);

			// Switches on line of file, doing certain functions on specific lines
			switch (index) {
				case 0: // Adds the number of students
					ss >> temp >> *numberOfStudents;
					break;
				case 1: // Adds the number of assignments
					ss >> temp >> *numberOfAssignments;
					break;
				case 2: // Skips third line
					break;
				default:
					ss >> ID >> firstName >> lastName;

					// Organizes student's names
					Name name;
					name.firstName = firstName;
					name.lastName = lastName;
					studentNames.insert( pair<int, Name>(ID, name) );

					// Organizes student's scores
					vector<int> scores;

					// Adds the assignments to the scores vector
					while (ss >> assignment) {
						scores.push_back(assignment);
					}
					
					studentScores.insert( pair<int, vector<int> > (ID, scores) );

					break;
			}
			++index;
		}
		file.close();
	}
}

void formatCaseOfNames(map<int, Name> &names) {
	string firstName;
	string lastName;

	// Loops through the names map, taking all the names and formatting its case
	for (auto i = names.begin(); i != names.end(); i++) {
		firstName = i->second.firstName;
		lastName = i->second.lastName;

		transform(firstName.begin(), firstName.end(), firstName.begin(), ::tolower);
		transform(lastName.begin(), lastName.end(), lastName.begin(), ::tolower);

		firstName[0] = toupper(firstName[0]);
		lastName[0] = toupper(lastName[0]);

		i->second.firstName = firstName;
		i->second.lastName = lastName;
		cout << firstName << " " << lastName << endl;
	}
}

void computeTotalAndPercent(map<int, vector<int> > &scores, map<int, int> &total, map<int, float>
&percent) {
	float percentage = 0.0;
	double totalGrade = 0.0;
	double divisor = 0.0;
	vector<int> allScores;

	// Loops through the entire scores map
	for (auto i = scores.begin(); i != scores.end(); i++) {
		// Loops through the vector inside scores map
		for (auto j = i->second.begin(); j != i->second.end(); ++j) {
			totalGrade = totalGrade + *j;
		}

		divisor = (i->second.size()) * 10;
		percentage = (totalGrade / divisor) * 100;

		cout << percentage << endl;

		total.insert( pair< int, int >(i->first, totalGrade) );
		totalGrade = 0;

		percent.insert( pair< int, float >(i->first, percentage));
		percentage = 0.0;
	}
}

void writeFormattedGrades(const string outputFilepath, map<int, Name> &names, map<int, int> &total,
map<int, float> &percent) {
	ofstream file;
	file.open(outputFilepath);

	if (file.is_open()) {
		// Loops through the names map, printing every students name
		for (auto i = names.begin(); i != names.end(); i++) {
			file << i->second.lastName << ", " << i->second.firstName;
			file << setw(20 - (i->second.lastName.length() + i->second.firstName.length()));

			// Loops through student's scores and percent, adding it to the file
			for (int j = 1; j < total.size(); j++) {
				file << total.at(i->first);
				file << fixed << setw(7) << setprecision(1);
				double percentage = static_cast<double>(percent.at(i->first));
				file << percentage;

				break;
			}

			file << endl;
		}
	}
}