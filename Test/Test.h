#pragma once
#include "Test.h"
#include<vector>
#include<iostream>
using namespace std;

class StopWatch
{

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