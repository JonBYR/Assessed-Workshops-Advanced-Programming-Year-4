#include "Student.h"
int Student::totalScores = 0;
Student::Student() {
	score = 0;
}
Student::Student(int s) {
	score = s;
	totalScores += s;
}
int Student::getScore() {
	return score;
}
float Student::getAverage() 
{
	return totalScores / 10.0;
}