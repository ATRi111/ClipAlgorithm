#pragma once
#include<vector>
#include<iostream>
#include<functional>

//base class for all kinds of input
struct TestCase
{
	virtual ~TestCase();
	virtual void Print() const;
};
//base class for all kinds of output
struct TestAnswer
{
	virtual ~TestAnswer();
	virtual bool Match(TestAnswer* other) const;
	virtual void Print() const;
};

//one Solution is used for solving one TestCase
class Solution
{
public:
	static Solution* CreateDefaultSolution();
	double TimeTest(TestCase* t);
	virtual TestAnswer* Run(TestCase* t);
};

//one TestSet is used for measuring time and correctness of a set of Testcases
class TestSet
{
	std::function<Solution*()> CreateSolution;
	void Print(TestCase* c, TestAnswer* points, TestAnswer* output, bool matched);
public:	
	std::vector<TestCase*> cases;
	std::vector<TestAnswer*> answers;
	//both vectors must be allocated and deleted externally; each pointer in both vectors must be unique(or nullptr)
	TestSet(std::vector<TestCase*>& cases, std::vector<TestAnswer*>& answers, const std::function<Solution*()>& CreateSolution);
	~TestSet();
	double TimeTest(int repeatTimes);
	double CorrectnessTest(int printTimes);
	//generate answers with given Solution
	void GenerateAnswers();
	//delete all pointers in answers then clear answers
	void DeleteAnswers();
	//delete all pointers in cases then clear cases
	void DeleteCases();
};