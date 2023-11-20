#pragma once
#include "Shape.h"
#include <iostream>
class Triangle : public Shape
{
public:
	Triangle(double b, double h);
	virtual double calculateArea();
	virtual void display();
private:
	double base;
	double height;
};

