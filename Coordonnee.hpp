#include <iostream>
#include <istream>
#include <ostream>
#include <random>
#include <cstdlib>

using namespace std;

#ifndef COORDONNEE_H
#define COORDONNEE_H

class Coordonnee {

private:
	float x, y, z;

public:
	Coordonnee();
	Coordonnee(float newx, float newy, float newz);

	void setXYZ(float& newx, float& newy, float& newz);
	void setX(float newx);
	void setY(float newy);
	void setZ(float newz);
	float getX();
	float getY();
	float getZ();

	void print() const;
};

#endif
