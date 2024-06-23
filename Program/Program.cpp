#include<iostream>
#include<vector>
#include"Vector2.h"
#include"Test.h"
using namespace std;

int main()
{
	Vector2 v1 = Vector2(0, 1);
	Vector2 v2 = Vector2(-1, 1);
	v2 = v2 + v1;

	int n = 10000;
	vector<TestCase*> set;
	for (int i = 0; i < n; i++)
	{
		set.emplace_back();
	}
	vector<TestAnswer*> empty;
	TestLauncher launcher(set, empty, Solution::CreateDefaultSolution);
	double ms = launcher.TimeTest();
	cout << ms << endl;
	double percent = launcher.CorrectnessTest();
	cout << percent << endl;
}