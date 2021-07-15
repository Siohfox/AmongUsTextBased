#pragma once
#include "Task.h"
class EmergencyTask : public Task
{
public:
	EmergencyTask(std::string taskName, int taskParts)
	{
		m_taskName = taskName;
		m_taskComplete = false;
		m_taskParts = taskParts;
	}

	~EmergencyTask()
	{

	}
};

