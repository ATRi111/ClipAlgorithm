#include<iostream>
#include"Test.h"
#include<vector>

int main()
{
	int n = 1000000;
	vector<TestCase> set;
	for (int i = 0; i < n; i++)
	{
		set.emplace_back();
	}
	TestLauncher launcher(set, Solution::CreateDefaultSolution);
	double ms = launcher.TimeTest();
	cout << ms << endl;
}