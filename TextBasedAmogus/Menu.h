#pragma once
class Menu
{
public:
	Menu()
	{
		menuActive = true;
	}

	~Menu()
	{

	}

	void MenuLoop();
	void PollEvents();
	void Run();

private:
	bool menuActive;
};

