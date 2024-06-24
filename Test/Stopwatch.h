#pragma once
#include<chrono>

class Stopwatch
{
	std::chrono::time_point<std::chrono::steady_clock> timePoint;
	long long nanoseconds;
	bool paused;
public:
	Stopwatch();
	Stopwatch(bool startOnAwake);
	void Reset();
	void Restart();
	void Start();
	void Pause();
	long long NanoSeconds() const;
	double Milliseconds() const;
};

