#include "Coordonnee.hpp"
#include "Plane.hpp"



int main()
{
	//	vector<Plane> planes
	bool stop_thread = false;
	Coordonnee Position_Plane(5, 5, 0);
	string SuperPlane = "test";
	Coordonnee Destination(10,10, 0);
	Plane myPlane(SuperPlane, Position_Plane, Destination);
	//airport.add_a_plane_to_queue(myPlane);


	while (1)
	{
		string name;
		cin >> name;
		if (name == "0")
		{
			stop_thread = true;
			break;
		}
	}


	//std::cout << "Finish\n";*/

	return 0;
}