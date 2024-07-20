#pragma once
#include<string>
#include<iostream>
#include<vector>
#include"Vector2.h"
#include"Testframework.h"
#include"ClipAlgorithm.h"
#include"LiangBarskyAlgorithm.h"
#include"CohenSutherlandAlgorithm.h"

void Test(std::string path, int times, int printTimes, const std::function<Algorithm* ()>& CreateSolution, bool guaranteed = false)
{
	TestSerializer_Clip serializer;
	TestSet set = TestSet(serializer.DeserializeFrom(path));
	set.CreateSolution = CreateSolution;

	set.AccuracyTest(printTimes, guaranteed);
	set.TimeTest(times);

	set.DeleteAnswers();
	set.DeleteCases();
	std::cout << std::endl;
}

void TestLiangBarskyAlgorithm(std::string path, int times)
{
	std::cout << "LiangBarsky算法:" << std::endl;
	Test(path, times, 3, LiangBarskyAlgorithm::CreateLiangBarskyAlgorithm, true);
}

void TestCohenSutherlandAlgorithm(std::string path, int times)
{
	std::cout << "CohenSutherland算法:" << std::endl;
	Test(path, times, 0, CohenSutherlandAlgorithm::CreateCohenSutherlandAlgorithm, true);
}