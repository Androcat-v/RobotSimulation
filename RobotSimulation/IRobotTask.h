#pragma once

class Robot;

class IRobotTask
{
public:
	virtual void Execute(Robot& robot)=0;
};

