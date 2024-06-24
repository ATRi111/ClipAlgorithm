#include "LiangBarskyAlgorithm.h"
using namespace std;

#pragma region LiangBarskyAlgorithm
LiangBarskyAlgorithm* LiangBarskyAlgorithm::CreateLiangBarskyAlgorithm()
{
    return new LiangBarskyAlgorithm();
}

LiangBarskyAlgorithm::LiangBarskyAlgorithm()
    :uIn(0),uOut(1)
{
    uIn = 0;
    uOut = 1;
}
vector<Vector2>* LiangBarskyAlgorithm::Clip(float xMin, float xMax, float yMin, float yMax, Vector2 p1, Vector2 p2)
{
    vector<Vector2>* result = new vector<Vector2>();
    r = p2 - p1;
    if (
        IntersectAndCheck(-r.x, p1.x - xMin)
        && IntersectAndCheck(r.x, xMax - p1.x)
        && IntersectAndCheck(-r.y, p1.y - yMin)
        && IntersectAndCheck(r.y, yMax - p1.y)
        )
    {
        result->emplace_back(p1 + uIn * r);
        result->emplace_back(p1 + uOut * r);
    }
    return result;
}
bool LiangBarskyAlgorithm::IntersectAndCheck(float p, float q)
{
    if (p < 0)
    {
        float u = q / p;
        if (u > uOut)
            return false;
        uIn = max(uIn, u);
    }
    else if (p > 0)
    {
        float u = q / p;
        if (u < uIn)
            return false;
        uOut = min(uOut, u);
    }
    else
        return q < 0;
    return true;
}
#pragma endregion