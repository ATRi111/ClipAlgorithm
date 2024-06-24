﻿#pragma once
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