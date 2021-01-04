#include "./math.h"


float math::convertDegreesToRadian(float degree)
{
    return degree * (M_PI / 180);
}

int math::calculateDistance(Point point_1, Point point_2)
{
    float formula = (pow((point_2.x - point_1.x), 2) +
                    (pow((point_2.y - point_1.y), 2)));
    return sqrt(abs(formula));
}

Point math::calculateRotatePosition(float degree, Point center, Point point)
{
    Point positionAfterRotate;

    int positionAfterRotateX = center.x + (point.x - center.x) *
                               cos(degree) - (point.y - center.y) *
                               sin(degree);
    int positionAfterRotateY = center.y + (point.y - center.y) *
                               cos(degree) + (point.x - center.x) *
                               sin(degree);
    positionAfterRotate = {positionAfterRotateX, positionAfterRotateY};
    return positionAfterRotate;
}
