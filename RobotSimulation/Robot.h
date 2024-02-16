#pragma once
#include "RobotConfiguration.h"
#include "IRobotTask.h"
#include <deque>
#include <memory>

class Robot
{
public:
	Robot(const RobotConfiguration& config){	}

	void AddTask(std::shared_ptr<IRobotTask> task) {
		m_tasks.push_back(task);

	}

	void DoTask()
	{
		while (!m_tasks.empty())
		{
		m_tasks.front()->Execute(*this);
		m_tasks.pop_front();
		}
	}

private:
	std::deque<std::shared_ptr<IRobotTask>> m_tasks{};
	int dustLevel{};
};