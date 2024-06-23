#include"Test.h"

StopWatch::StopWatch(bool start = true) :nanoseconds(0), paused(!start)
{
	if (start)
		timePoint = high_resolution_clock::now();
}
void StopWatch::Reset()
{
	paused = true;
	nanoseconds = 0;
}
void StopWatch::Restart()
{
	Reset();
	Start();
}
void StopWatch::Start()
{
	if (paused)
	{
		paused = false;
		timePoint = high_resolution_clock::now();
	}
}
void StopWatch::Pause()
{
	time_point<steady_clock> temp = high_resolution_clock::now();
	if (!paused)
	{
		paused = true;
		nanoseconds += (temp - timePoint).count();
	}
}
long long StopWatch::NanoSeconds() const
{
	time_point<steady_clock> temp = high_resolution_clock::now();
	if (!paused)
		return nanoseconds + (temp - timePoint).count();
	return nanoseconds;
}
double StopWatch::Milliseconds() const
{
	return NanoSeconds() / 1e6;
}

Solution Solution::CreateDefaultSolution()
{
	return Solution();
}
double Solution::TimeTest(TestCase t)
{
	StopWatch timer;
	timer.Start();
	Run(t);
	timer.Pause();
	return timer.Milliseconds();
}
bool Solution::CorrectnessTest(TestCase t)
{
	return false;
}
void Solution::Run(TestCase t)
{

}

TestLauncher::TestLauncher(const vector<TestCase>& set, const function<Solution()>& CreateSolution)
	:set(set), CreateSolution(CreateSolution)
{

}
double TestLauncher::TimeTest()
{
	double sum = 0.0;
	for (int i = 0; i < set.size(); i++)
	{
		Solution s = CreateSolution();
		sum += s.TimeTest(set[i]);
	}
	return sum;
}
double TestLauncher::CorrectnessTest()
{
	double sum = 0.0;
	for (int i = 0; i < set.size(); i++)
	{
		Solution s = CreateSolution();
		sum += s.CorrectnessTest(set[i]);
	}
	return sum / set.size();
}