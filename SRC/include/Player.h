#pragma once

#include <SFML/Graphics.hpp>
#include "Student.h"

class Player
{
public:
	Player(bool turn, bool throwTurn, Student* student1, Student* student2, Student* student3);
	double getBeerStatus();
	bool getTurn();
	bool getThrowTurn();
	bool getIsDrinking();
	Student* getActualStudent();
	Student** getStudents();
	void setBeerStatus(double beerStatus);
	void setTurn(bool turn);
	void setThrowTurn(bool throwTurn);
	void setIsDrinking(bool isDrinking);
	void setActualStudent(Student* actualStudent);
	void nextStudent();

private:
	double beerStatus;
	bool turn;
	bool throwTurn;
	bool isDrinking;
	Student* actualStudent;
	Student* students[3];
};