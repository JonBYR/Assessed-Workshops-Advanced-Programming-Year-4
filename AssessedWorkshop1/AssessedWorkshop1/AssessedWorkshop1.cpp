// AssessedWorkshop1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Student.h"
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    Student students[10];
    //int totalScores = 0;
    vector<int> allScores;
    cout << "Enter scores for 10 students!" << std::endl;
    for (int i = 0; i < 10; i++) 
    {
        int studentScore;
        cout << "Enter the score for student " << i + 1 << " ";
        cin >> studentScore;
        allScores.push_back(studentScore);
        students[i] = Student(studentScore);
    }
    float averageScore = Student::getAverage();
    sort(allScores.begin(), allScores.end());
    int lowestScore = allScores[0];
    int highScore = allScores[9];
    int aboveAverage = 0;
    int belowAverage = 0;
    for (int i = 0; i < 10; i++) 
    {
        if (students[i].getScore() > averageScore) aboveAverage++;
        else if (students[i].getScore() < averageScore) belowAverage++;
    }
    cout << "Total students: 10" << std::endl;
    cout << "Average score: " << averageScore << std::endl;
    cout << "Highest score: " << highScore << std::endl;
    cout << "Lowest score: " << lowestScore << std::endl;
    cout << "Students above average: " << aboveAverage << std::endl;
    cout << "Students below average: " << belowAverage << std::endl;
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
