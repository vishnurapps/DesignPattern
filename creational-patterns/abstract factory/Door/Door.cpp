#include <iostream>

class IDoor
{
public:
	virtual void getDescription() = 0;
};

class WoodenDoor : public IDoor
{
public:
	virtual void getDescription()
	{
		std::cout << "This is a Wodden Door" << std::endl;
	}
};

class IronDoor : public IDoor
{
public:
	virtual void getDescription()
	{
		std::cout << "This is an Iron Door" << std::endl;
	}
};

class IWorker
{
public:
	virtual void getJobDescription() = 0;
};

class Carpenter : public IWorker
{
public:
	virtual void getJobDescription()
	{
		std::cout << "I am a Carpenter" << std::endl;
	}
};

class Welder : public IWorker
{
public:
	virtual void getJobDescription()
	{
		std::cout << "I am a Welder" << std::endl;
	}
};

class IDoorFactory
{
public:
	virtual IDoor* getDoor() = 0;
	virtual IWorker* getWorker() = 0;
};

class WoodenDoorFactory : public IDoorFactory
{
public:
	virtual IDoor* getDoor()
	{
		return new WoodenDoor();
	}
	virtual IWorker* getWorker()
	{
		return new Carpenter();
	}
};

class IronDoorFactory : public IDoorFactory
{
public:
	virtual IDoor* getDoor()
	{
		return new IronDoor();
	}
	virtual IWorker* getWorker()
	{
		return new Welder();
	}
};

int main()
{
	IDoorFactory* woodFactory = new WoodenDoorFactory();
	IDoor *door1 = woodFactory->getDoor();
	IWorker *worker1 = woodFactory->getWorker();
	door1->getDescription();
	worker1->getJobDescription();
	

	IDoorFactory* ironFactory = new IronDoorFactory();
	IDoor *door2 = ironFactory->getDoor();
	IWorker *worker2 = ironFactory->getWorker();
	door2->getDescription();
	worker2->getJobDescription();
	
	return 0;
}