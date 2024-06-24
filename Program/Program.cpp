#include<iostream>
#include<string>
#include<vector>
#include"Vector2.h"
#include"Test.h"
#include"LiangBarskyAlgorithm.h"
#include"CohenSutherlandAlgorithm.h"
using namespace std;

int main(int argc, char* argv[])
{
	string path = argv[0];
	path = path.substr(0, path.find_last_of('\\')) + "\\Answer.txt";
	TestSerializer_Clip serializer;
	TestSet set = TestSet(serializer.DeserializeFrom(path));

	set.CorrectnessTest(3);
	set.DeleteAnswers();
	set.DeleteCases();
}