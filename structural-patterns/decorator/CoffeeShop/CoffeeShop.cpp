#include <iostream>
#include <string>

class BasicCoffee
{
public:
	virtual std::string description() = 0;
	virtual float cost() = 0;
};

class Latte : public BasicCoffee
{
	virtual std::string description () override
	{
		return "Latte";
	}

	virtual float cost () override
	{
		return 10;
	}
};

class Espresso : public BasicCoffee
{
	virtual std::string description () override
	{
		return "Espresso";
	}

	virtual float cost () override
	{
		return 15;
	}
};

class Cappuccino : public BasicCoffee
{
	virtual std::string description () override
	{
		return "Cappuccino";
	}

	virtual float cost () override
	{
		return 20;
	}
};

class Addons : public BasicCoffee
{
protected:
	BasicCoffee &basicCoffee_;
public:
	Addons(BasicCoffee &basicCoffee) : basicCoffee_(basicCoffee){};
	virtual std::string description() = 0;
	virtual float cost() = 0; 
};

class Caramel: public Addons
{
public:
	Caramel(BasicCoffee &basicCoffee) : Addons(basicCoffee){};
	virtual std::string description () override
	{
		return basicCoffee_.description() + " Caramel Added";
	}
	virtual float cost () override
	{
		return basicCoffee_.cost() + + 2;
	}
};

class Vanila: public Addons
{
public:
	Vanila(BasicCoffee &basicCoffee) : Addons(basicCoffee){};
	virtual std::string description () override
	{
		return basicCoffee_.description() + " Vanila Added";
	}
	virtual float cost () override
	{
		return basicCoffee_.cost() + + 3;
	}
};

class Honey: public Addons
{
public:
	Honey(BasicCoffee &basicCoffee) : Addons(basicCoffee){};
	virtual std::string description () override
	{
		return basicCoffee_.description() + " Honey Added";
	}
	virtual float cost () override
	{
		return basicCoffee_.cost() + + 4;
	}
};

int main()
{
	BasicCoffee *latte1 = new Latte();
	std::cout << latte1->description() << std::endl;
	std::cout << latte1->cost() << std::endl;

	BasicCoffee *espresso = new Espresso();
	Addons *honeyEspresso = new Honey(*espresso);
	std::cout << honeyEspresso->description() << std::endl;
	std::cout << honeyEspresso->cost() << std::endl;

	BasicCoffee *cappuccino = new Cappuccino();
	Addons *caramelCauppuccino = new Caramel(*cappuccino);
	Addons *honeyCaramelCuppuccino = new Honey(*caramelCauppuccino);
	std::cout << honeyCaramelCuppuccino->description() << std::endl;
	std::cout << honeyCaramelCuppuccino->cost() << std::endl;
}