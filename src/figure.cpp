#include "./figure.h"



void Figure::calculateCircle(Point points[], int startDegree, int endDegree)
{
    float radian;
    int tmp = startDegree;

    Point circlePoint = {_center.x + _figureWidth / 8,
                         _center.y - _figureWidth / 8};
    float circleRadius = calculateDistance(circlePoint,
                                                       this->_center);

    for (int i = 0; i < endDegree - startDegree; i++)
    {
        radian = convertDegreesToRadian(tmp++);
        points[i].x = circleRadius * cos(radian) +
                                     this->_center.x;
        points[i].y = circleRadius * sin(radian) +
                                     this->_center.y;
    }
}

VertexArray Figure::createCircle()
{
    VertexArray circle(LineStrip, 0);

    int startDegree = 0;
    int endDegree = 360;
    Point circleCord[endDegree - startDegree];

    calculateCircle(circleCord, startDegree, endDegree);

    for (int i = 0; i < endDegree - startDegree; i++)
    {
        circle.append(Vertex(Vector2f(circleCord[i].x,
                                      circleCord[i].y),
                             _color));
    }

    return circle;
}

void Figure::calculateQuadrant(Point points[])
{
    points[0] = {_center.x, _center.y - _figureHeight / 2};
    points[1] = {_center.x + _figureWidth / 16,
                 _center.y - _figureHeight / 4 -
                 _figureHeight / 6};
    points[2] = {_center.x,
                 _center.y - _figureHeight / 4 -
                 _figureHeight / 12};
    points[3] = {_center.x, _center.y};
    points[4] = {_center.x + _figureWidth / 8,
                 _center.y - _figureWidth / 8};
    points[5] = points[2];
    points[6] = {_center.x,
                 _center.y -
                 calculateDistance(points[4], _center)};
    points[7] = {_center.x +
                 calculateDistance(points[4], _center),
                 _center.y -
                 calculateDistance(points[4], _center)};
    points[8] = {_center.x +
                 calculateDistance(points[4], _center),
                 _center.y};
    points[9] = {_center.x + _figureWidth / 4 + _figureWidth / 12,
                 _center.y};
    points[10] = points[3];
    points[11] = points[4];
    points[12] = points[9];
    points[13] = {_center.x + _figureWidth / 4 + _figureWidth / 6,
                  _center.y - _figureHeight / 16};
    points[14] = {_center.x + _figureWidth / 2, _center.y};
}

void Figure::rotateQuadrant(Point points[], int size, int degree)
{
    float radian = convertDegreesToRadian(degree);

    for (int i = 0; i < size; i++)
    {
        points[i] = calculateRotatePosition(
                                            radian,
                                            this->_center,
                                            {points[i].x, points[i].y});
    }
}

VertexArray Figure::createQuadrant()
{
    int size = 15;
    Point points[size];
    VertexArray quadrant(Lines, 0);

    for (int i = 0; i < 4; i++)
    {
        calculateQuadrant(points);
        rotateQuadrant(points, size, 90 * i + _degree);
        for (int j = 0; j < size - 1; j++)
        {
            quadrant.append(Vertex(Vector2f(points[j].x, points[j].y),
                            _color));
            quadrant.append(Vertex(Vector2f(points[j + 1].x,
                                            points[j + 1].y),
                            _color));
        }
    }

    return quadrant;
}


Figure::Figure(Point center, int width, int height, Color color)
{
    _center = center;
    _figureWidth = width;
    _figureHeight = height;
    _degree = 0;
    _color = color;
}

Figure::~Figure()
{
    
}

void Figure::move(int offsetX, int offsetY)
{
    this->_center.x += offsetX;
    this->_center.y += offsetY;
}

void Figure::scale(int offsetScale)
{
    this->_figureHeight -= offsetScale;
    this->_figureWidth -= offsetScale;
}

void Figure::draw(RenderWindow &window)
{
    window.draw(createCircle());
    window.draw(createQuadrant());
}

void Figure::rotate(int degree)
{
    _degree += degree;
}
