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
	StopWatch(bool start = true) :nanoseconds(0),paused(!start)
	{
		if (start)
			timePoint = high_resolution_clock::now();
	}
	void Reset()
	{
		paused = true;
		nanoseconds = 0;
	}
	void Restart()
	{
		Reset();
		Start();
	}
	void Start()
	{
		if (paused)
		{
			paused = false;
			timePoint = high_resolution_clock::now();
		}
	}
	void Pause()
	{
		time_point<steady_clock> temp = high_resolution_clock::now();
		if (!paused)
		{
			paused = true;
			nanoseconds += (temp - timePoint).count();
		}
	}
	long long NanoSeconds() const
	{
		time_point<steady_clock> temp = high_resolution_clock::now();
		if (!paused)
			return nanoseconds + (temp - timePoint).count();
		return nanoseconds;
	}
	double Milliseconds() const
	{
		return NanoSeconds() / 1e6;
	}
};

//Base class,different problems have different test cases
struct TestCase
{

};

//One Solution is used for solving one TestCase
class Solution
{
public:
	static Solution CreateDefaultSolution()
	{
		return Solution();
	}
	double TimeTest(TestCase t)
	{
		StopWatch timer;
		timer.Start();
		Run(t);
		timer.Pause();
		return timer.Milliseconds();
	}
	virtual bool CorrectnessTest(TestCase t)
	{
		return false;
	}
	virtual void Run(TestCase t)
	{

	}
};

//One TestLauncher is used for measuring time and correctness of a set of Testcases
class TestLauncher
{
	const vector<TestCase>& set;
	function<Solution()> CreateSolution;
public:
	TestLauncher(const vector<TestCase>& set, const function<Solution()>& CreateSolution)
		:set(set), CreateSolution(CreateSolution)
	{
		
	}
	double TimeTest()
	{
		double sum = 0.0;
		for (int i = 0; i < set.size(); i++)
		{
			Solution s = CreateSolution();
			sum += s.TimeTest(set[i]);
		}
		return sum;
	}
	double CorrectnessTest()
	{
		double sum = 0.0;
		for (int i = 0; i < set.size(); i++)
		{
			Solution s = CreateSolution();
			sum += s.CorrectnessTest(set[i]);
		}
		return sum / set.size();
	}
};