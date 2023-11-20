#include "Triangle.h"
Triangle::Triangle(double b, double h)
{
	base = b;
	height = h;
}
double Triangle::calculateArea()
{
	return 0.5 * base * height;
}
void Triangle::display()
{
	std::cout << "This is a triangle" << std::endl;
	std::cout << "Base: " << base << std::endl;
	std::cout << "Height: " << height << std::endl;
	std::cout << "Area: " << calculateArea() << std::endl;
}