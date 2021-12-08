#pragma once
#include "Coordonnee.hpp"
#include <thread>
#include <mutex>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>


#ifndef PLANE_H
#define PLANE_H

#define PI 3.14159265

//std::mutex airport_mutex;

class Plane {
private:
	std::thread t_;
	string identification_;		//Nom de l'Avion
	Coordonnee Position_Plane_;	//Coordonnée de l'avion
	Coordonnee Destination_;
	float angle_;
	float radius_;
	bool Fly_to_Airport_ = true;
	bool Rotate_ = false;
	bool Land_ = false;
	bool TakeOff_ = false;
	bool stop_thread_ = false;


public:
	//Plane();
	Plane(string& identification, Coordonnee& Position_Plane, Coordonnee& Destination);
	void To_Fly_to_Airport();
	void To_Rotate();
	void To_Land();
	void To_TakeOff();
	void Update();
	float FindAngle();
	//float FindRadius();
	Coordonnee getPosition();
	//~Plane();

};

void update_plane(Plane& plane, bool& stop_thread);

//*************************************//
//									   //
//			CLASS AIRPORT			   //
//									   //
//*************************************//

/**class Airport {
private:
	vector <Plane> Plane_Who_Wait;
	Coordonnee Position_Airport;
public:
	void add_a_plane_to_queue(Plane& plane);
	Coordonnee getPosition();

};


**/

#endif