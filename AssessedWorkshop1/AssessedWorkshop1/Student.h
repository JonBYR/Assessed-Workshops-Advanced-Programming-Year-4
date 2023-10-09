#pragma once
class Student
{
public:
	Student(); //default constructor needed
	Student(int s);
	int getScore();
	static float getAverage();
private:
	int score;
	static int totalScores;
};


