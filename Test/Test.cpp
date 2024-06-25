#include"Test.h"
#include<vector>
using namespace std;

#pragma region TestCase
TestCase::~TestCase()
{

}
void TestCase::Print() const
{
	cout << endl;
}
#pragma endregion

#pragma region TestAnswer
TestAnswer::~TestAnswer()
{

}
bool TestAnswer::Match(TestAnswer* other) const
{
	return other;
}
void TestAnswer::Print() const
{
	cout << "(null)" << endl;
}
#pragma endregion

#pragma region Algorithm
Algorithm* Algorithm::CreateDefault()
{
	return new Algorithm();
}
double Algorithm::TimeTest(TestCase* t)
{
	Stopwatch timer(false);
	Run(t, &timer);
	return timer.Milliseconds();
}
TestAnswer* Algorithm::Run(TestCase* t, Stopwatch* timer)
{
	if (timer)
		timer->Start();

	if (timer)
		timer->Pause();
	return new TestAnswer();
}
#pragma endregion
