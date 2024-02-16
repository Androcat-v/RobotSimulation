#pragma once
#include "IRobotTask.h"

class TaskVacuum : public IRobotTask
{
public:
	void Execute(Robot& robot) override;
private:

};

class TaskEmptyDustHolder : public IRobotTask
{
public:
	void Execute(Robot& robot) override;
private:

};

