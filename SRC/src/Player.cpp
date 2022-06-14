#include "Player.h"

Player::Player(bool turn, bool throwTurn, Student* student1, Student* student2, Student* student3)
{
	beerStatus = 100;
	isDrinking = false;
	this->turn = turn;
	this->throwTurn = throwTurn;
	this->actualStudent = student1;
	students[0] = student1;
	students[1] = student2;
	students[2] = student3;
}

double Player::getBeerStatus() { return beerStatus; }
bool Player::getTurn() { return turn; }
bool Player::getThrowTurn() { return throwTurn; }
bool Player::getIsDrinking() { return isDrinking; }
Student* Player::getActualStudent() { return actualStudent; }
Student** Player::getStudents() { return students; }
void Player::setBeerStatus(double beerStatus) { this->beerStatus = beerStatus; }
void Player::setTurn(bool turn) { this->turn = turn; }
void Player::setThrowTurn(bool throwTurn) { this->throwTurn = throwTurn; }
void Player::setIsDrinking(bool isDrinking) { this->isDrinking = isDrinking; }
void Player::setActualStudent(Student* actualStudent) { this->actualStudent = actualStudent; }

void Player::nextStudent()
{
	int actualStudentId = actualStudent->getId();
	switch (actualStudentId % 3)
	{
	case 0:
		actualStudent = students[1];
		break;
	case 1:
		actualStudent = students[2];
		break;
	case 2:
		actualStudent = students[0];
		break;
	}
}