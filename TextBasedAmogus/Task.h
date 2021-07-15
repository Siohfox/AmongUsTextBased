#pragma once
#include <iostream>
#include <vector>
#include <string>

class Task
{
public:
	Task()
	{
		m_taskName = "null";
		m_taskComplete = false;
		m_taskParts = 1;

	}

	Task(std::string taskName, int taskParts)
	{
		m_taskName = taskName;
		m_taskComplete = false;
		m_taskParts = taskParts;
	}

	~Task()
	{
		
	}

	// Getters
	std::string getTaskName() { return m_taskName; }
	bool getTaskStatus() { return m_taskComplete; }

	// Setters
	void setTaskStatus(bool complete) { m_taskComplete = complete; }
	void setTaskName(std::string name) { m_taskName = name; }

protected:
	std::string m_taskName;
	int m_taskParts;
	bool m_taskComplete;
};

