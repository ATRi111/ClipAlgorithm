#pragma once
#include<vector>
#include<iostream>
#include<chrono>
#include<functional>
using namespace std;
using namespace std::chrono;
using namespace std::literals::chrono_literals;

class StopWatch
{
	time_point<steady_clock> timePoint;
	long long nanoseconds;
	bool paused;
public:
	StopWatch(bool start);
	void Reset();
	void Restart();
	void Start();
	void Pause();
	long long NanoSeconds() const;
	double Milliseconds() const;
};

//Base class,different problems have different test cases
struct TestCase
{

};

//One Solution is used for solving one TestCase
class Solution
{
public:
	static Solution CreateDefaultSolution();
	double TimeTest(TestCase t);
	virtual bool CorrectnessTest(TestCase t);
	virtual void Run(TestCase t);
};

//One TestLauncher is used for measuring time and correctness of a set of Testcases
class TestLauncher
{
	const vector<TestCase>& set;
	function<Solution()> CreateSolution;
public:
	TestLauncher(const vector<TestCase>& set, const function<Solution()>& CreateSolution);
	double TimeTest();
	double CorrectnessTest();
};