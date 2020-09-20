#////////////////////////////// FILE HEADER ///////////////////////////////////
#/
#/ Title: Summarize Grades Makefile
#/ Files: SummarizeGrades.h, SummarizeGrades.cpp, demo.cpp, Makefile, README.md
#/ Course: CS 368, Spring 2020
#/
#/ Author: Matt Thompson
#/ Student ID: 9081263262
#/ Email: mathompson23@wisc.edu
#// Lecturer's Name: Marc Renault
#/
#/ Online Sources: 
#/ - https://www.geeksforgeeks.org/inserting-elements-in-stdmap-insert-emplace
#/	 	-and-operator/
#/
#/ - https://www.geeksforgeeks.org/traversing-a-map-or-unordered_map-in-cpp-stl/
#/ 
#/ - https://stackoverflow.com/questions/8530529/convert-first-letter-in-string
#/ 		-to-uppercase
#/ 
#/ - http://www.cplusplus.com/reference/iomanip/setprecision/
#/ 
#/////////////////////////// FILE DESCRIPTION /////////////////////////////////
#/ 
#/ This is the makefile for demo.cpp, which displays the Grade Summarizer.
#/
#//////////////////////////////////////////////////////////////////////////////

# Makefile

CXX=g++
CXXFLAGS=-Wall

all: build

SummarizeGrades.o: SummarizeGrades.h

clean:
	-rm SummarizeGrades.o
	-rm demo

build: demo.cpp SummarizeGrades.o
	$(CXX) $(CXXFLAGS) -o demo demo.cpp SummarizeGrades.o