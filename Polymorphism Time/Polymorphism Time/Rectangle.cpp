#include "Rectangle.h"
Rectangle::Rectangle(double l, double w) 
{
	length = l;
	width = w;
}
double Rectangle::calculateArea() 
{
	return width * length;
}
void Rectangle::display() 
{
	std::cout << "This is a rectangle" << std::endl;
	std::cout << "Length: " << length << std::endl;
	std::cout << "Width: " << width << std::endl;
	std::cout << "Area: " << calculateArea() << std::endl;
}