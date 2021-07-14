#include "Time.h"

double Time::deltaTime()
{
	m_currentTime = static_cast<double>(SDL_GetTicks()) / 1000.0f;

	double deltaTime = m_currentTime - m_lastTime;

	m_lastTime = m_currentTime;

	if (deltaTime < (m_framerate))
	{
		SDL_Delay((Uint32)(m_framerate - deltaTime) * 1000.0f);
	}

	return deltaTime;
}