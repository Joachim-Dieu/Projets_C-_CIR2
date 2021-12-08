#include "Plane.hpp"

//Plane::Plane() {}

Plane::Plane(string &identification,Coordonnee &Position_Plane, Coordonnee &Destination) {
	this->Fly_to_Airport_ = true;
	this->Rotate_ = false;
	this->Land_ = false;
	this->TakeOff_ = false;
	this->angle_ = 0;
	this->identification_ = identification;
	this->Position_Plane_ = Position_Plane;
	this->Destination_ = Destination;
	Update();
	t_ = std::thread(update_plane, std::ref(*this), std::ref(stop_thread_));
}

void Plane::FindAngle() {
	int DestinationX = Destination_.getX();
	int DestinationY = Destination_.getY();
	int PlaneX = Position_Plane_.getX();
	int PlaneY = Position_Plane_.getY();

	if ((DestinationX > PlaneX) && (DestinationY > PlaneY)) {									//+X et +Y 
		angle_ = atan((DestinationY - PlaneY) / (DestinationX - PlaneX))*(180/PI);
	}
	else if ((DestinationX < PlaneX) && (DestinationY > PlaneY)) {								//-X et +Y 
		angle_ = 180 - (atan((DestinationY - PlaneY) / (DestinationX - PlaneX)) * (180 / PI));
	}
	else if((DestinationX < PlaneX) && (DestinationY< PlaneY)) {								//-X et -Y 
		angle_ = -90 - atan((DestinationY - PlaneY) / (DestinationX - PlaneX)) * (180 / PI);
	}
	else if((DestinationX > PlaneX) && (DestinationY< PlaneY)) {								//+X et +Y 
		angle_ = -atan((DestinationY - PlaneY) / (DestinationX - PlaneX)) * (180 / PI);
	}
	radius_ = sqrt((DestinationX - PlaneX) ^ 2 - (DestinationY - PlaneY) ^ 2);
}

void Plane::Update()
{
	if((this->Fly_to_Airport_)==0){
		To_Fly_to_Airport();
	}

	if ((this->Rotate_) == 0) {
		To_Rotate();
	}

	if ((this->Land_) == 0) {
		To_Land();
	}

	if ((this->TakeOff_) == 0) {
		To_TakeOff();
	}
}


Coordonnee Plane::getPosition() {
	return this->getPosition();
}

void Plane::To_Fly_to_Airport() {

	int X = Position_Plane_.getX();
	int Y = Position_Plane_.getY();

	X = radius_ * cos(angle_);
	Y = radius_ * sin(angle_);

}

void Plane::To_Rotate() {
	int X = Position_Plane_.getX();
	int Y = Position_Plane_.getY();

	X = radius_ * cos(angle_);
	Y = radius_ * sin(angle_);
}

void Plane::To_Land() {
	int X = Position_Plane_.getX();
	int Y = Position_Plane_.getY();

	X = radius_ * cos(angle_);
	Y = radius_ * sin(angle_);
}

void Plane::To_TakeOff() {
	int X = Position_Plane_.getX();
	int Y = Position_Plane_.getY();

	X = radius_ * cos(angle_);
	Y = radius_ * sin(angle_);
}

/*Plane::~Plane()
{
	stop_thread_ = true;
	t_.join();
	//    std::cout << "Thread was stopped" << std::endl;
}*/

void update_plane(Plane& plane, bool& stop_thread)
{
	while (!stop_thread)
	{
		std::this_thread::sleep_for(1s);
		plane.Update();
		plane.getPosition().print();
	}
}

Coordonnee Airport::getPosition() {
	return this->Position_Airport;
}

void Airport::add_a_plane_to_queue(Plane& plane) {
	Plane_Who_Wait.push_back(plane);
}