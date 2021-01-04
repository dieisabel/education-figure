#pragma once
#ifndef _FIGURE_H
#define _FIGURE_H

#include <SFML/Graphics.hpp>

#include "./utils/point.cpp"
#include "./utils/math.h"

using namespace sf;
using namespace math;

class Figure
{

private:
    Point _center;
    Color _color;

    int _figureWidth;
    int _figureHeight;

    int _degree;

    void calculateCircle(Point points[], int startDegree, int endDegree);
    VertexArray createCircle();

    void calculateQuadrant(Point points[]);
    void rotateQuadrant(Point points[], int size, int degree);
    VertexArray createQuadrant();

public:
    Figure(Point center, int width, int height, Color color=Color::White);
    ~Figure();

    void move(int offsetX, int offsetY);
    void scale(int offsetScale);
    void draw(RenderWindow &window);
    void rotate(int degree);
};


#endif
