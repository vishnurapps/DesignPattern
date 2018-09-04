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

template<typename DoorType, typename WorkerType>
class DoorFactory : public IDoorFactory
{
public:
	virtual IDoor* getDoor()
	{
		return new DoorType();
	}
	virtual IWorker* getWorker()
	{
		return new WorkerType();
	}
};


int main()
{
	IDoorFactory* woodFactory = new DoorFactory<WoodenDoor, Carpenter>();
	IDoor *door1 = woodFactory->getDoor();
	IWorker *worker1 = woodFactory->getWorker();
	door1->getDescription();
	worker1->getJobDescription();
	

	IDoorFactory* ironFactory = new DoorFactory<IronDoor, Welder>();
	IDoor *door2 = ironFactory->getDoor();
	IWorker *worker2 = ironFactory->getWorker();
	door2->getDescription();
	worker2->getJobDescription();
	
	return 0;
}