#include<iostream>
#include<vector>
#include"Vector2.h"
#include"Test.h"
#include"LiangBarskyAlgorithm.h"
#include"CohenSutherlandAlgorithm.h"
using namespace std;

int main()
{
	Vector2 v1 = Vector2(0, 1);
	Vector2 v2 = Vector2(-1, 1);
	v2 = v2 + v1;
	cout << v2 << endl;

	TestCase_Clip* c = new TestCase_Clip(10, 20, 10, 20, Vector2(0, 0), Vector2(30, 30));
	Solution* s = CohenSutherlandAlgorithm::CreateCohenSutherlandAlgorithm();
	TestAnswer_Clip* a = (TestAnswer_Clip*)s->Run(c);
	const vector<Vector2>& v = *(a->answer);
	cout << v[0] << endl;
	cout << v[1] << endl;
}