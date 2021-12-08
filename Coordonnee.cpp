
#include "Coordonnee.hpp"

Coordonnee::Coordonnee() {
	x = (rand() % 100);
	y = (rand() % 100);
	z = (rand() % 100);
}

Coordonnee::Coordonnee(float newx, float newy, float newz) {
	this->x = newx;
	this->y = newy;
	this->z = newz;
}

void Coordonnee::setXYZ(float& newx, float& newy, float& newz) {
	this->x = newx;
	this->y = newy;
	this->z = newz;
}

void Coordonnee::setX(float newx) {
	this->x = newx;
}

void Coordonnee::setY(float newy) {
	this->y = newy;
}

void Coordonnee::setZ(float newz) {
	this->z = newz;
}

float Coordonnee::getX(){
	return x;
}

float Coordonnee::getY(){
	return y;
}

float Coordonnee::getZ(){
	return z;
}

void Coordonnee::print() const {
	cout << "XYZ : " << x << "," << y << "," << z << endl;
}

