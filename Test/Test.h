#pragma once
#include<vector>
#include<iostream>
#include<functional>

struct TestCase
{

};
struct TestAnsnwer
{
	virtual bool Match(TestAnsnwer other) const;
};

//One Solution is used for solving one TestCase
class Solution
{
protected:

public:
	static Solution CreateDefaultSolution();
	double TimeTest(TestCase t);
	virtual TestAnsnwer Run(TestCase t);
};

//One TestLauncher is used for measuring time and correctness of a set of Testcases
class TestLauncher
{
	const std::vector<TestCase>& cases;
	const std::vector<TestAnsnwer>& answers;
	std::function<Solution()> CreateSolution;
public:
	TestLauncher(const std::vector<TestCase>& cases, const std::vector<TestAnsnwer>& answers, const std::function<Solution()>& CreateSolution);
	double TimeTest();
	double CorrectnessTest();
};