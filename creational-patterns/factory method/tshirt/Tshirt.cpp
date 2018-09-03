#include <iostream>
#include <cstring>

class Tshirt 
{
public:
	virtual void color() = 0;
};
 
class Blue: public Tshirt 
{
public:
	void color() 
	{
		std::cout << "Blue Tshirt \n";
	}
};
 
class Red: public Tshirt  
{
public:
	void color() 
	{
		std::cout << "Red Tshirt \n";
	}
};

class Green: public Tshirt  
{
public:
	void color() 
	{
		std::cout << "Green Tshirt \n";
	}
};
 
class TshirtFactory 
{
public:
	virtual Tshirt *createTshirt(char const*) = 0;
};

class KeralaFactory: public TshirtFactory 
{
public:
	Tshirt *createTshirt(char const *color) 
	{
		if(strcmp(color,"blue") == 0) 
		{
			return new Blue;
		}
		else if(strcmp(color,"red") == 0) 
		{
			return new Red;
		}
		else if(strcmp(color,"green") == 0) 
		{
			return new Green;
		}
		else
		{
			throw "error in color";
		}
	}
};

int main()
{
	TshirtFactory* tFactory;
	Tshirt *sht;

	tFactory = new KeralaFactory;

	sht = tFactory->createTshirt("blue");
	sht -> color();
	sht = tFactory->createTshirt("red");
	sht -> color();

	return 0;
}