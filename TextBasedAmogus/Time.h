#pragma once
#include <time.h>
#include <SDL/SDL.h>

class Time
{
	Time()
	{
		
	}

public:
	double deltaTime();

private:
	double m_currentTime, m_lastTime, m_framerate;
};

