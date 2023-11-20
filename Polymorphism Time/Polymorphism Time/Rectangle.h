#pragma once
#include "Shape.h"
#include <iostream>
class Rectangle : public Shape
{
public:
	Rectangle(double l, double w);
	virtual double calculateArea();
	virtual void display();
private:
	double width;
	double length;
};

