#include <iostream>
#include <cstring>
#include <string>

class President
{

public:
	static President *getInstance(std::string name);
	void name()
	{
		std::cout << "Name is " << name_ << std::endl;
	}
private:
	President(std::string name) 
	{
		name_ = name;
	}
	static President *instance;
	std::string name_;
};

President *President::instance = 0;
President *President::getInstance(std::string name)
{
	if(!instance)
	{
		instance = new President(name);
		std::cout << "getInstance() returned first instance" << std::endl;
		return instance;
	}
	else
	{
		std::cout << "getInstance() returned same instance" << std::endl;
		return instance;
	}
}

int main()
{
	President *p1 = President::getInstance("Obama");
	p1->name();
	President *p2 = President::getInstance("Bill");
	p2->name();
	President *p3 = p2;
	p3->name();
	return 0;
}