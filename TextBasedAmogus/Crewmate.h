#pragma once
#include "Players.h"
#include "Task.h"
#include <vector>


class Crewmate : public Players
{
public:
	Crewmate(std::string _colour)
	{
		this->m_colour = _colour;
		this->m_aliveState = true;
		this->m_player = false;
		// 0 means crewmate
		this->m_playerType = 0;
	}

	~Crewmate()
	{

	}

	void setTasks(std::vector<Task*> taskVector) { crewmateTasks = taskVector; }

	std::vector<Task*> getTaskList() { return crewmateTasks; }

	std::string getTask(int taskNumber) { return crewmateTasks[taskNumber]->getTaskName(); }

	void Update() override;

private:
	std::vector<Task*> crewmateTasks;
};

