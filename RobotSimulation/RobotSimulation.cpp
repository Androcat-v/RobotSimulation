#include <iostream>
#include <fstream>
#include <string>

#include "ConfigLoader.h"
#include "ConsoleReader.h"
#include "FileReader.h"
#include "Robot.h"
#include "IRobotTask.h"
#include "RobotTasks.h"

enum class ConfigType
{
	Console = 0,
	File
};

enum class TaskType
{
	Vacuum,
	EmptyDustHolder
};

std::unique_ptr<IReader> CreateReader(const ConfigType configType)
{
	switch (configType)
	{
	case ConfigType::Console:
		return std::make_unique<ConsoleReader>();
	case ConfigType::File:
		return std::make_unique<FileReader>(std::ifstream("config.txt"));
	default:
		return{};
	}
}

int main()
{
	std::cout << "Please press if you want to check:" << std::endl
		<< "0 - to enter configuration from console" << std::endl
		<< "1 - to read configuration from a file" << std::endl;

	

	int choice{ ConsoleReader().ReadInt() };
	ConfigLoader loader{};
	loader.SetReader(CreateReader(static_cast<ConfigType>(choice)));

	auto config = loader.LoadConfig();
	Robot robot{ config };


	while (true) {
		std::cout << "Please press if you want to:" << std::endl
			<< "0 - add task vacuum the floor" << std::endl
			<< "1 - add task empty dust holder" << std::endl
			<< "2 - do tasks" << std::endl
			<< "any number - stop the program";
		int taskChoice{ ConsoleReader().ReadInt() };
		switch (taskChoice)
		{
		case 0:
			robot.AddTask(std::make_shared<TaskVacuum>());
		case 1:
			robot.AddTask(std::make_shared<TaskEmptyDustHolder>());
		case 2:
			robot.DoTask();
		default:
			return 0;
		}
	}

}

