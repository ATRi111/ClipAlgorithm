#pragma once
#include "Test.h"
#include<vector>
#include<iostream>
#include<chrono>
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
		return nanoseconds;
	}
	double Milliseconds() const
	{
		return nanoseconds / 1e6;
	}
};

class TestCase
{

};

class Solution
{
public:
	vector<TestCase> set;
	Solution(vector<TestCase>& set) :set(set)
	{
		
	}
	virtual int TimeTest() = 0;
	virtual float CorrectnessTest() = 0;
};