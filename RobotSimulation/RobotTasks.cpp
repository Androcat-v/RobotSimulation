#include "RobotTasks.h"
#include "Robot.h"
#include <iostream>

void TaskVacuum::Execute(Robot& robot)
{	
	std::cout << "I vacuum the floor!";
	bool taskVacuumComplete{ true };
}

void TaskEmptyDustHolder::Execute(Robot& robot)
{
	std::cout << "I empty my dust holder!";
	
}
