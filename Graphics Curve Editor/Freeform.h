//
//  Freeform.h
//  Graphics Curve Editor
//
//  Created by Jon Atkins on 10/22/14.
//  Copyright (c) 2014 AIT. All rights reserved.
//

#ifndef __Graphics_Curve_Editor__Freeform__
#define __Graphics_Curve_Editor__Freeform__

#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <iostream>

#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>

#include "float2.h"
#include <vector>

//macros for curve types
#define BEZIER 'b'
#define LAGRANGE 'l'
#define POLYLINE 'p'
#define CATMULL_CLARK 'c'

// The precision of the curve
const float PRECISION = 1000;
// The magnitude of a tangent vector to a curve
const float TANGENT_LENGTH = .5;
const double DEFAULT_LINE_WIDTH = 5.0;
const GLdouble DEFAULT_COLOR[3] = {0, 0, 0};

#define POINT_HIGHLIGHT_COLOR 1, 1, 1
#define POINT_COLOR .5, .5, .5

class Freeform {
protected:
    std::vector<float2> controlPoints;
    char type;
    bool filled = false;
public:
    //drawing funcitons
    virtual void drawControlPoints(bool isSelectedCurve, int selectedControlPoint);
    virtual void draw();
    virtual void drawFilled();
    
    //high-level setters
    virtual void addControlPoint(float2 p);
    void setType(char t);
    virtual int deleteControlPoint(float2 clickLocation, float radius, int selectedControlPoint);
    void resetControlPoint(float2 p, int index);
    void translate(float2 offset);
    bool fill();
    
    //high-level getters
    virtual float2 getPoint(float t) = 0;
    bool isEmpty();
    virtual bool onLine(float2 clickPosition, float radius);
    bool isFilled();
    
    //getters
    int numControlPoints();
    float2 getControlPoint(int index);
    char getType();

};

#endif /* defined(__Graphics_Curve_Editor__Freeform__) */
