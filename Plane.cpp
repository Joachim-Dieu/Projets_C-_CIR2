#include "Plane.hpp"

//Plane::Plane() {}

Plane::Plane(string& identification, Coordonnee& Position_Plane, Coordonnee& Destination) :
	TakeOff_(false),
	Fly_to_Airport_(false),
	Rotate_(true),
	Land_(false)
{
	this->identification_ = identification;
	this->Position_Plane_ = Position_Plane;
	this->Destination_ = Destination;
	this->angle_ = FindAngle();
	this->radius_ = sqrt(pow((Destination_.getX() - Position_Plane_.getX()), 2) + pow((Destination_.getY() - Position_Plane_.getY()), 2));
	t_ = std::thread(update_plane, std::ref(*this), std::ref(stop_thread_));
}

float Plane::FindAngle() {
	float DestinationX = Destination_.getX();
	float DestinationY = Destination_.getY();
	float PlaneX = Position_Plane_.getX();
	float PlaneY = Position_Plane_.getY();

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
	float DestinationX = Destination_.getX();
	float DestinationY = Destination_.getY();
	float PlaneX = Position_Plane_.getX();
	float PlaneY = Position_Plane_.getY();

	if ((DestinationX == PlaneX) && (DestinationY == PlaneY)) {
		stop_thread_ = true;
		cout << "L'Avion a fini sa course" << endl;
	}
	else {

		if ((this->Fly_to_Airport_) == 1) {
			cout << endl;
			To_Fly_to_Airport();
		}

		if ((this->Rotate_) == 1) {
			cout << endl;
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

	float X = Position_Plane_.getX();
	float Y = Position_Plane_.getY();

	cout << radius_ << " , " << angle_ << endl;

	//cout << "Avant :" << X << " , " << Y << endl;
	//cout << "Avant :" << cos((angle_* PI) / 180)  << " , " << sin((angle_* PI) / 180) << endl;

	X += ((radius_)/10) * (cos((angle_ * PI) / 180));
	Y += ((radius_)/10) * (sin((angle_ * PI) / 180));

	//cout << "Apres" <<X << " , " << Y << endl;

	Position_Plane_.setX(X);
	Position_Plane_.setY(Y);

	this->angle_ = FindAngle();

}

void Plane::To_Rotate() {		//Pour airport 
	radius_ = 5;
	int X = Position_Plane_.getX();
	int Y = Position_Plane_.getY();

	
	cout << angle_ << endl;		//Prends l'angle entre l'avion et l'airport alors qu'il devrait prendre angle airport avion 

	X = radius_ * (cos((angle_ * PI) / 180)) + Destination_.getX();
	Y = radius_ * (sin((angle_ * PI) / 180)) + Destination_.getY();

	Position_Plane_.setX(X);
	Position_Plane_.setY(Y);
	
	angle_ = (angle_ + 20.f);
}

void Plane::To_Land() {
	int X = Position_Plane_.getX();
	int Y = Position_Plane_.getY();

	
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
		plane.getPosition().print();
		std::this_thread::sleep_for(1s);
		plane.Update();
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