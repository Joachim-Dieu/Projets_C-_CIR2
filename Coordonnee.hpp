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
	int x, y, z;

public:
	Coordonnee();
	Coordonnee(int newx, int newy, int newz);

	void setXYZ(int& newx, int& newy, int& newz);
	void setX(int newx);
	void setY(int newy);
	void setZ(int newz);
	int getX();
	int getY();
	int getZ();

	void print() const;
};

#endif
