#pragma once
#include<string>
#include"Vector2.h"
#include"Test.h"
#include"ClipAlgorithm.h"
#include"LiangBarskyAlgorithm.h"
#include"CohenSutherlandAlgorithm.h"

void Test(std::string path, int times, const std::function<Solution* ()>& CreateSolution)
{
	TestSerializer_Clip serializer;
	TestSet set = TestSet(serializer.DeserializeFrom(path));
	set.CreateSolution = CreateSolution;

	set.AccuracyTest(3);
	set.TimeTest(times);

	set.DeleteAnswers();
	set.DeleteCases();
	std::cout << std::endl;
}

void TestLiangBarskyAlgorithm(std::string path, int times)
{
	std::cout << "LiangBarsky算法:" << std::endl;
	Test(path, times, LiangBarskyAlgorithm::CreateLiangBarskyAlgorithm);
}

void TestCohenSutherlandAlgorithm(std::string path, int times)
{
	std::cout << "CohenSutherland算法:" << std::endl;
	Test(path, times, CohenSutherlandAlgorithm::CreateCohenSutherlandAlgorithm);
}


class MyAlgorithm : public ClipAlgorithm
{
	//可以在这里定义成员变量
public:
	static MyAlgorithm* CreateMyAlgorithm()
	{
		return new MyAlgorithm();
	}
	std::vector<Vector2>* Clip(float xMin, float xMax, float yMin, float yMax, Vector2 p1, Vector2 p2) override;
};

void TestMyAlgorithm(std::string path, int times)
{
	std::cout << "我的裁剪算法:" << std::endl;
	Test(path, times, MyAlgorithm::CreateMyAlgorithm);
}