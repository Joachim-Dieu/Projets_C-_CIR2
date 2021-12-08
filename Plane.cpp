#include "Plane.hpp"

//Plane::Plane() {}

Plane::Plane(string& identification, Coordonnee& Position_Plane, Coordonnee& Destination) :
	TakeOff_(false),
	Fly_to_Airport_(true),
	Rotate_(false),
	Land_(false)
{
	this->identification_ = identification;
	this->Position_Plane_ = Position_Plane;
	this->Destination_ = Destination;
	this->angle_ = FindAngle();
	this->radius_ = 2;
	Update();
	t_ = std::thread(update_plane, std::ref(*this), std::ref(stop_thread_));
}

float Plane::FindAngle() {
	int DestinationX = Destination_.getX();
	int DestinationY = Destination_.getY();
	int PlaneX = Position_Plane_.getX();
	int PlaneY = Position_Plane_.getY();

	if ((DestinationX > PlaneX) && (DestinationY > PlaneY)) {									//+X et +Y 
		angle_ = atan((DestinationY - PlaneY) / (DestinationX - PlaneX)) * (180 / PI);
	}
	else if ((DestinationX < PlaneX) && (DestinationY > PlaneY)) {								//-X et +Y 
		angle_ = 180 - (atan((DestinationY - PlaneY) / (DestinationX - PlaneX)) * (180 / PI));
	}
	else if ((DestinationX < PlaneX) && (DestinationY < PlaneY)) {								//-X et -Y 
		angle_ = -90 - atan((DestinationY - PlaneY) / (DestinationX - PlaneX)) * (180 / PI);
	}
	else if ((DestinationX > PlaneX) && (DestinationY < PlaneY)) {								//+X et +Y 
		angle_ = -atan((DestinationY - PlaneY) / (DestinationX - PlaneX)) * (180 / PI);
	}
	return angle_;
}

/*float Plane::FindRadius() {
	int DestinationX = Destination_.getX();
	int DestinationY = Destination_.getY();
	int PlaneX = Position_Plane_.getX();
	int PlaneY = Position_Plane_.getY();

	cout << DestinationX << DestinationY << endl;
	cout << PlaneX << PlaneY << endl;
	this->radius_ = sqrt(pow((DestinationX - PlaneX),2) + pow((DestinationY - PlaneY),2));
	cout << "le raduis est" << radius_ << endl;
	return radius_;
}*/

void Plane::Update()
{
	int DestinationX = Destination_.getX();
	int DestinationY = Destination_.getY();
	int PlaneX = Position_Plane_.getX();
	int PlaneY = Position_Plane_.getY();

	if ((DestinationX == PlaneX) || (DestinationY == PlaneY)) {
		stop_thread_ = true;
		cout << "L'Avion a fini sa course" << endl;
	}
	else {

		if ((this->Fly_to_Airport_) == 1) {
			cout << endl;
			To_Fly_to_Airport();
		}

		if ((this->Rotate_) == 1) {
			cout << "Rotate" << endl;
			To_Rotate();
		}

		if ((this->Land_) == 1) {
			cout << "Land" << endl;
			To_Land();
		}

		if ((this->TakeOff_) == 1) {
			cout << "TakeOff" << endl;
			To_TakeOff();
		}
	}
}


Coordonnee Plane::getPosition() {
	return this->Position_Plane_;
}

void Plane::To_Fly_to_Airport() {

	int X = Position_Plane_.getX();
	int Y = Position_Plane_.getY();

	cout << radius_ << " , " << angle_ << endl;

	X += radius_ * cos(angle_);
	Y += radius_ * sin(angle_);

	Position_Plane_.setX(X);
	Position_Plane_.setY(Y);

	this->angle_ = FindAngle();

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
/*
Coordonnee Airport::getPosition() {
	return this->Position_Airport;
}

void Airport::add_a_plane_to_queue(Plane& plane) {
	Plane_Who_Wait.push_back(plane);
}
*/