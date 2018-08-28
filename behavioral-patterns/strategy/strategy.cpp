#include <iostream>
#include <memory>

class Vehicle
{
public:
	virtual void useVehicle() = 0;
};

class HyundaiI20 : public Vehicle
{
public:
	virtual void useVehicle()
	{
		std::cout << "Driving Hyundai I20" << std::endl;
	}
};

class MaruthiSwift : public Vehicle
{
public:
	virtual void useVehicle()
	{
		std::cout << "Driving Maruthi Swift" << std::endl;
	}
};

class SuzukiGixxer : public Vehicle
{
public:
	virtual void useVehicle()
	{
		std::cout << "Driving Suzuki Gixxer" << std::endl;
	}
};

class HondaActiva : public Vehicle
{
public:
	virtual void useVehicle()
	{
		std::cout << "Driving Honda Activa" << std::endl;
	}
	
};

class TransportMode
{
public:
	virtual void use() = 0;
};

class VehicularTransportMode : public TransportMode
{
public:
	std::unique_ptr<Vehicle> vehicle;
	VehicularTransportMode(Vehicle *v): vehicle(v) {}
	virtual void use()
	{ 
		vehicle->useVehicle();
	}
};

class TrainTransportMode : public TransportMode
{
public:
	virtual void use()
	{
		std::cout << "Riding in a train" << std::endl;
	}
};

class PedestrianTransportMode : public TransportMode
{
public:
	virtual void use()
	{
		std::cout << "Walking by foot" << std::endl;
	}
};

class FamilyMember
{
private:
	std::unique_ptr<TransportMode> transportMode;
public:
	virtual void display() = 0;
	void setTransportMode(TransportMode *mode)
	{
		transportMode.reset(mode);
	}
	void transport()
	{
		transportMode->use();
	}
};

class Father : public FamilyMember
{
public:
	virtual void display()
	{
		std::cout << "I am father" << std::endl;
	}
};

class Mother : public FamilyMember
{
public:
	virtual void display()
	{
		std::cout << "I am mother" << std::endl;
	}
};

class Brother : public FamilyMember
{
public:
	virtual void display()
	{
		std::cout << "I am Brother" << std::endl;
	}
};

class Sister : public FamilyMember
{
public:
	virtual void display()
	{
		std::cout << "I am Sister" << std::endl;
	}
};

int main()
{
	FamilyMember *father = new Father();
	father->display();
	father->setTransportMode(new VehicularTransportMode(new SuzukiGixxer()));
	father->transport();

	FamilyMember *mother = new Mother();
	mother->display();
	mother->setTransportMode(new VehicularTransportMode(new MaruthiSwift()));
	mother->transport();

	FamilyMember *brother = new Brother();
	brother->display();
	brother->setTransportMode(new TrainTransportMode());
	brother->transport();

	FamilyMember *sister = new Sister();
	sister->display();
	sister->setTransportMode(new PedestrianTransportMode());
	sister->transport();
}