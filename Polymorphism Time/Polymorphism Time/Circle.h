#pragma once
#include "Shape.h"
#include <math.h>
#include <iostream>
class Circle : public Shape
{
public:
	Circle(double r);
	virtual double calculateArea();
	virtual void display();
private:
	double radius;
};

