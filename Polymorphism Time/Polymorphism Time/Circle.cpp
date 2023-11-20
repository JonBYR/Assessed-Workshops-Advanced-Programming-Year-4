#include "Circle.h"
Circle::Circle(double r) 
{
	radius = r;
}
double Circle::calculateArea() 
{
	return atan2(0, -1) * radius * radius;
}
void Circle::display() 
{
	std::cout << "This is a circle" << std::endl;
	std::cout << "This is it's radius " << radius << std::endl;
	std::cout << "This is it's area " << calculateArea() << std::endl;
}