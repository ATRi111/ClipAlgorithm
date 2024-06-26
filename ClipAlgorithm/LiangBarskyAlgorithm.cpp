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
bool LiangBarskyAlgorithm::Clip(float xMin, float xMax, float yMin, float yMax, Vector2& p1, Vector2& p2)
{
    r = p2 - p1;
    if (IntersectAndCheck(r.x, xMax - p1.x, p1.x - xMin)
        && IntersectAndCheck(r.y, yMax - p1.y, p1.y - yMin))
    {
        p2 = p1 + uOut * r;
        p1 = p1 + uIn * r;
        return true;
    }
    return false;
}
bool LiangBarskyAlgorithm::IntersectAndCheck(float p,float q1,float q2)
{
    if (p < 0)
    {
        float u1 = q1 / p;
        if (u1 > uOut)
            return false;
        uIn = max(uIn, u1);    
        float u2 = q2 / (-p);
        if (u2 < uIn)
            return false;
        uOut = min(uOut, u2);
    }
    else if (p > 0)
    {
        float u1 = q1 / p;
        if (u1 < uIn)
            return false;
        uOut = min(uOut, u1);
        float u2 = q2 / (-p);
        if (u2 > uOut)
            return false;
        uIn = max(uIn, u2);
    }
    else
        return q1 < 0 && q2 < 0;
    return true;
}
#pragma endregion