#pragma once
#include "Task.h"
class EmergencyTask : public Task
{
public:
	EmergencyTask(std::string taskName)
	{
		m_taskName = taskName;
		m_taskComplete = false;
	}

	~EmergencyTask()
	{

	}
};

