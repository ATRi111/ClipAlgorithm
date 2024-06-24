#include<iostream>
#include<vector>
#include"Program.h"
using namespace std;

int main(int argc, char* argv[])
{
	string path = argv[0];
	path = path.substr(0, path.find_last_of('\\')) + "\\Answer.txt";
	int times = 10000;

	TestCohenSutherlandAlgorithm(path, times);
	TestLiangBarskyAlgorithm(path, times);
	TestMyAlgorithm(path, times);
}


//完成这个函数，可以在头文件中定义成员变量
vector<Vector2>* MyAlgorithm::Clip(float xMin, float xMax, float yMin, float yMax, Vector2 p1, Vector2 p2)
 {
	//如果没有要保留的线段，直接返回空数组；否则将保留线段的两个端点加入数组（无顺序要求，误差在±0.01以内）
	vector<Vector2>* result = new vector<Vector2>();
	return result;
 }