// Polymorphism Time.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Shape.h"
#include <vector>
int main()
{
    std::cout << "Enter the radius of the circle: ";
    double answer;
    std::cin >> answer;
    Circle c(answer);
    std::cout << "Enter the length and width of the rectangle: ";
    double answer2, answer3;
    std::cin >> answer2 >> answer3;
    Rectangle r(answer2, answer3);
    std::cout << "Enter the base and height of the triangle: ";
    double answer4, answer5;
    std::cin >> answer4 >> answer5;
    Triangle t(answer4, answer5);
    std::vector<Shape*> shapes;
    shapes.push_back(&c);
    shapes.push_back(&r);
    shapes.push_back(&t);
    for (int i = 0; i < shapes.size(); i++) 
    {
        shapes[i]->display();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
