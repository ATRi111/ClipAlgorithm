#include "Stopwatch.h"
using namespace std::chrono;

#pragma region Stopwatch
Stopwatch::Stopwatch() :nanoseconds(0), paused(false)
{
	timePoint = high_resolution_clock::now();
}
Stopwatch::Stopwatch(bool startOnAwake) :nanoseconds(0), paused(!startOnAwake)
{
	if (startOnAwake)
		timePoint = high_resolution_clock::now();
}
void Stopwatch::Reset()
{
	paused = true;
	nanoseconds = 0;
}
void Stopwatch::Restart()
{
	Reset();
	Start();
}
void Stopwatch::Start()
{
	if (paused)
	{
		paused = false;
		timePoint = high_resolution_clock::now();
	}
}
void Stopwatch::Pause()
{
	time_point<steady_clock> temp = high_resolution_clock::now();
	if (!paused)
	{
		paused = true;
		nanoseconds += (temp - timePoint).count();
	}
}
long long Stopwatch::NanoSeconds() const
{
	time_point<steady_clock> temp = high_resolution_clock::now();
	if (!paused)
		return nanoseconds + (temp - timePoint).count();
	return nanoseconds;
}
double Stopwatch::Milliseconds() const
{
	return NanoSeconds() / 1e6;
}
#pragma endregion