#pragma once
#include<functional>
#include<iomanip>
#include<vector>
#include"Test.h"
#include"Stopwatch.h"

//one TestSet is used for measuring time and accuracy of a set of Testcases
class TestSet
{
	void Print(TestCase* c, TestAnswer* points, TestAnswer* output, bool matched);
public:
	std::vector<TestCase*> cases;
	std::vector<TestAnswer*> answers;
	std::function<Algorithm* ()> CreateSolution;
	//both vectors must be allocated and deleted externally; each pointer in both vectors must be unique(or nullptr)
	TestSet(std::vector<TestCase*>& cases, std::vector<TestAnswer*>& answers, const std::function<Algorithm* ()>& CreateSolution);
	~TestSet();
	double TimeTest(int repeatTimes);
	double AccuracyTest(int printTimes);
	//generate answers with given Algorithm
	void GenerateAnswers();
	//delete all pointers in answers then clear answers
	void DeleteAnswers();
	//delete all pointers in cases then clear cases
	void DeleteCases();
};