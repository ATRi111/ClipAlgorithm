#include "CohenSutherlandAlgorithm.h"
using namespace std;

#pragma region CohenSutherlandAlgorithm
CohenSutherlandAlgorithm* CohenSutherlandAlgorithm::CreateCohenSutherlandAlgorithm()
{
    return new CohenSutherlandAlgorithm();
}

bool CohenSutherlandAlgorithm::Clip(float xMin, float xMax, float yMin, float yMax, Vector2& p1, Vector2& p2)
{
    this->p1 = p1;
    this->xMin = xMin;
    this->xMax = xMax;
    this->yMin = yMin;
    this->yMax = yMax;
    r = p2 - p1;
    code1 = Calculate(p1);
    code2 = Calculate(p2);
    while (!(code1 & code2))
    {
        if (!(code1 | code2))
            return true;
        if (code1)
        {
            int last = code1 & ((~code1) + 1);
            p1 = Intersect(last);
            code1 = Calculate(p1);
        }
        else
        {
            int last = code2 & ((~code2) + 1);
            p2 = Intersect(last);
            code2 = Calculate(p2);
        }
    }
    return false;
}

int CohenSutherlandAlgorithm::Calculate(Vector2 p) const
{
    int code = 0;
    if (p.y > yMax)
        code |= 8;
    if (p.y < yMin)
        code |= 4;
    if (p.x > xMax)
        code |= 2;
    if (p.x < xMin)
        code |= 1;
    return code;
}
Vector2 CohenSutherlandAlgorithm::Intersect(int last) const
{
    switch (last)
    {
    case 8:
        return IntersectY(yMax);
    case 4:
        return IntersectY(yMin);
    case 2:
        return IntersectX(xMax);
    case 1:
        return IntersectX(xMin);
    default:
        break;
    }
    throw "Invalid Argument";
}
Vector2 CohenSutherlandAlgorithm::IntersectY(float y) const
{
    float u = (y - p1.y) / r.y;
    return Vector2((p1 + u * r).x, y);  //avoid flopping errors
}
Vector2 CohenSutherlandAlgorithm::IntersectX(float x) const
{
    float u = (x - p1.x) / r.x;
    return Vector2(x, (p1 + u * r).y);  //avoid flopping errors
}
#pragma endregion
