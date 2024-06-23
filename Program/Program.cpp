#include<iostream>
#include<vector>
#include"Vector2.h"
#include"Test.h"
#include"LiangBarskyAlgorithm.h"
using namespace std;

int main()
{
	Vector2 v1 = Vector2(0, 1);
	Vector2 v2 = Vector2(-1, 1);
	v2 = v2 + v1;
	cout << v2 << endl;

	TestCase_Clip c = TestCase_Clip(10, 10, 20, 20, Vector2(0, 0), Vector2(30, 30));
	Solution* s = LiangBarskyAlgorithm::CreateLiangBarskyAlgorithm();
	vector<TestAnswer*> empty;
}