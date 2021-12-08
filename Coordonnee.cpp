
#include "Coordonnee.hpp"

Coordonnee::Coordonnee() {
	x = (rand() % 100);
	y = (rand() % 100);
	z = (rand() % 100);
}

Coordonnee::Coordonnee(int newx, int newy, int newz) {
	this->x = newx;
	this->y = newy;
	this->z = newz;
}

void Coordonnee::setXYZ(int& newx, int& newy, int& newz) {
	this->x = newx;
	this->y = newy;
	this->z = newz;
}

void Coordonnee::setX(int newx) {
	this->x = newx;
}

void Coordonnee::setY(int newy) {
	this->y = newy;
}

void Coordonnee::setZ(int newz) {
	this->z = newz;
}

int Coordonnee::getX(){
	return x;
}

int Coordonnee::getY(){
	return y;
}

int Coordonnee::getZ(){
	return z;
}

void Coordonnee::print() const {
	cout << "XYZ : " << x << "," << y << "," << z << endl;
}

