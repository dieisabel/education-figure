#pragma once
#ifndef _MATH_SOMETHING_H
#define _MATH_SOMETHING_H

#include <cmath>

#include "./point.cpp"

#define _USE_MATH_DEFINES


namespace math
{
    float convertDegreesToRadian(float degree);
    int calculateDistance(Point point_1, Point point_2);
    Point calculateRotatePosition(float degree, Point center, Point point);
}

#endif
