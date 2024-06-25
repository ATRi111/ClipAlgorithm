#include"Program.h"
using namespace std;


class MyAlgorithm : public ClipAlgorithm
{
	//可以在这里定义成员变量和成员函数
public:
	static MyAlgorithm* CreateMyAlgorithm()
	{
		return new MyAlgorithm();
	}
	//如果最终不保留线段，直接返回false
	//否则，将p1，p2更新为最终保留线段的两端点（无顺序要求，误差在±0.01以内），然后返回true
	bool Clip(float xMin, float xMax, float yMin, float yMax, Vector2& p1, Vector2& p2) override
	{

		return false;
	}
};

void TestMyAlgorithm(std::string path, int times)
{
	std::cout << "我的裁剪算法:" << std::endl;
	Test(path, times, MyAlgorithm::CreateMyAlgorithm);
}

int main(int argc, char* argv[])
{
	string path = argv[0];
	path = path.substr(0, path.find_last_of('\\')) + "\\Answer.txt";
	int times = 10000;

	TestCohenSutherlandAlgorithm(path, times);
	TestLiangBarskyAlgorithm(path, times);
	TestMyAlgorithm(path, times);
}