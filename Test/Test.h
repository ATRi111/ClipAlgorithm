#pragma once
#include<iostream>
#include"Stopwatch.h"

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


//one Algorithm is used for solving one TestCase
class Algorithm
{
public:
	static Algorithm* CreateDefault();
	double TimeTest(TestCase* t);
	virtual TestAnswer* Run(TestCase* t, Stopwatch* timer);
};