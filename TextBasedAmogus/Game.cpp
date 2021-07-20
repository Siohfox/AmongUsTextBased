#include "Game.h"
#include "SDL/SDL.h"

void Game::Initialize(int _playerCount)
{
	srand(static_cast<unsigned int>(time(0)));
	m_playerCount = _playerCount;

	InitLocations();

	InitTasks();

	// Initialize each player as a crewmate, using passed in player count
	for (int i = 0; i < _playerCount; i++)
	{
		Crewmate* crewmate = new Crewmate(m_colourList[i]);
		m_crewmates.push_back(crewmate);
		m_crewmates[i]->setTasks(m_tasks);
		std::cout << "Initialized crewmate: " << m_crewmates[i]->GetColour() << std::endl;
	}

	int playerSelector = rand() % _playerCount;
	m_crewmates[playerSelector]->SetPlayerState(true);
	
	// Determine how many imposters to make depending on player count
	// More than 5 crewmates, two imposters needed
	// Less than 6 crewmates, only one imposter needed
	if (m_playerCount < 6)
	{
		// Less than 6 crewmates, only one imposter needed

		// Get a random crewmate and turn it into an imposter
		int imposterSelector = rand() % m_crewmates.size();

		// Initialize random imposter as a new imposter using the crewmates colour and stuff
		Imposter* imposter = new Imposter(m_crewmates[imposterSelector]->GetColour(), m_crewmates[imposterSelector]->GetPlayerState());


		// Add imposter to imposter vector
		m_imposters.push_back(imposter);


		if (m_crewmates[imposterSelector]->GetPlayerState() == true)
		{
			//std::cout << m_crewmates[imposterSelector]->GetColour() << " IS THE IMPOSTERY BOI" << std::endl;
		}

		// remove the imposter from crewmates
		delete m_crewmates[imposterSelector];
		m_crewmates[imposterSelector] = nullptr;
		m_crewmates.erase(std::remove(m_crewmates.begin(), m_crewmates.end(), nullptr), m_crewmates.end());

	}
	else
	{
		// Get two random crewmate and turn them into an imposters

		for (size_t i = 0; i < 2; i++)
		{
			int imposterSelector = rand() % m_crewmates.size();

			// Initialize random imposter as a new imposter using the crewmates colour and stuff
			Imposter* imposter = new Imposter(m_crewmates[imposterSelector]->GetColour(), m_crewmates[imposterSelector]->GetPlayerState());

			if (m_crewmates[imposterSelector]->GetPlayerState() == true)
			{
				std::cout << m_crewmates[imposterSelector]->GetColour() << " IS THE IMPOSTERY BOI" << std::endl;
			}

			// Add imposter to imposter vector
			m_imposters.push_back(imposter);

			// remove the imposter from crewmates
			delete m_crewmates[imposterSelector];
			m_crewmates[imposterSelector] = nullptr;
			m_crewmates.erase(std::remove(m_crewmates.begin(), m_crewmates.end(), nullptr), m_crewmates.end());			
		}
	}

	// Finally list all crewmates and imposters for debugging purposes
	std::cout << std::endl;
	std::cout << "Players: " << m_playerCount << std::endl;

	std::cout << "Crewmates: \n" << std::endl;
	for (size_t i = 0; i < m_crewmates.size(); i++)
	{
		std::cout << "Crewmate " << std::to_string(i) << ": " << m_crewmates[i]->GetColour() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Imposters: \n" << std::endl;
	for (size_t i = 0; i < m_imposters.size(); i++)
	{
		std::cout << "Imposter " << std::to_string(i) << ": " << m_imposters[i]->GetColour() << std::endl;
	}

	// Debug for showing tasks of crewmate 0
	std::cout << "\n" << "Crewmate " << m_crewmates[0]->GetColour() << "'s tasks are: " << "\n";
	for (size_t i = 0; i < m_crewmates[0]->getTaskList().size(); i++)
	{
		std::cout << m_crewmates[0]->getTask(i) << std::endl;
	}
	

	m_crewmates[0]->getTaskList().at(0)->setTaskStatus(false);

	std::cout << "Task " << m_crewmates[0]->getTask(0) << " is " << std::to_string(m_crewmates[0]->getTaskList().at(0)->getTaskStatus()) << std::endl;

	// output task name with get task, output task location using the task's location in the task array, and the get task location func
	std::cout << "Task " << m_crewmates[0]->getTask(0) << " is located at " << m_crewmates[0]->getTaskList().at(0)->getTaskLocation() << std::endl;

	// Start game when initializing is done
	Gameloop();

	return;
}

void Game::Gameloop()
{
	while (m_running)
	{
		PollEvents();
		Update();
		Render();
	}
}

void Game::PollEvents()
{
	// Create var for event
	SDL_Event event;

	// while there is an event happening like a key press, do this:
	while (SDL_PollEvent(&event))
	{
		// If the event is quit, then running is false and it back to menu.
		if (event.type == SDL_QUIT)
		{
			m_running = false;
		}
	}
}

void Game::Update()
{
	for (size_t i = 0; i < m_crewmates.size(); i++)
	{
		m_crewmates[i]->Update();
	}

	for (size_t i = 0; i < m_imposters.size(); i++)
	{
		m_imposters[i]->Update();
	}

	//std::cout << m_locations[0]->getLocationName();
}

void Game::Render()
{

}

void Game::InitLocations()
{
	Location* Cafeteria = new Location("Cafeteria");
	Location* Weapons = new Location("Weapons");
	Location* O2 = new Location("O2");
	Location* Navigation = new Location("Navigation");
	Location* Shields = new Location("Shields");
	Location* Communications = new Location("Communications");
	Location* Storage = new Location("Storage");
	Location* Admin = new Location("Admin");
	Location* Electrical = new Location("Electrical");
	Location* Lower_Engine = new Location("Lower Engine");
	Location* Reactor = new Location("Reactor");
	Location* Security = new Location("Security");
	Location* Upper_Engine = new Location("Upper Engine");
	Location* Med_Bay = new Location("MedBay");

	/*0*/m_locations.push_back(Cafeteria);
	/*1*/m_locations.push_back(Weapons);
	/*2*/m_locations.push_back(O2);
	/*3*/m_locations.push_back(Navigation);
	/*4*/m_locations.push_back(Shields);
	/*5*/m_locations.push_back(Communications);
	/*6*/m_locations.push_back(Storage);
	/*7*/m_locations.push_back(Admin);
	/*8*/m_locations.push_back(Electrical);
	/*9*/m_locations.push_back(Lower_Engine);
	/*10*/m_locations.push_back(Reactor);
	/*11*/m_locations.push_back(Security);
	/*12*/m_locations.push_back(Upper_Engine);
	/*13*/m_locations.push_back(Med_Bay);

}

void Game::InitTasks()
{
	// Init tasks
	Task* ClearAsteroids = new Task("Clear Asteroids", 1, { m_locations[1] });
	Task* Empty_Chute = new Task("Empty Chute", 2, { m_locations[0], m_locations[6], m_locations[2] } );
	Task* Fix_Wires = new Task("Fix Wires", 3, {m_locations[0], m_locations[3], m_locations[4], m_locations[5], m_locations[6], m_locations[7], m_locations[8], });
	Task* Chart_Course = new Task("Chart Course", 1, { m_locations[0] });
	Task* Clean_Oxygen = new Task("Clean Oxygen", 1, { m_locations[0] });
	Task* Empty_Garbage = new Task("Empty Garbage", 2, { m_locations[0] });
	Task* Swipe_Card = new Task("Swipe Card", 1, { m_locations[0] });
	Task* Med_Scan = new Task("Submit Medbay Scan", 1, { m_locations[0] });
	Task* Enter_Code = new Task("Enter Code", 1, { m_locations[0] });
	Task* Download = new Task("Download Data", 1, { m_locations[0] });
	Task* Upload = new Task("Upload Data", 1, { m_locations[0] });
	Task* Fix_Batteries = new Task("Fix Batteries", 2, { m_locations[0], m_locations[1], m_locations[3], m_locations[8], m_locations[9], m_locations[10], m_locations[12] });

	// Emergencies
	EmergencyTask* TNT_Warn = new EmergencyTask("TNT Warning", 1);
	EmergencyTask* O2_Leak = new EmergencyTask("O2 Leak", 2);

	// Add tasks to vector array
	m_tasks.push_back(ClearAsteroids);
	m_tasks.push_back(Empty_Chute);
	m_tasks.push_back(Fix_Wires);
	m_tasks.push_back(Chart_Course);
	m_tasks.push_back(Clean_Oxygen);
	m_tasks.push_back(Empty_Garbage);
	m_tasks.push_back(Swipe_Card);
	m_tasks.push_back(Med_Scan);
	m_tasks.push_back(Enter_Code);
	m_tasks.push_back(Download);
	m_tasks.push_back(Upload);

	// Add emergency tasks to vector array
	m_emergencyTasks.push_back(TNT_Warn);
	m_emergencyTasks.push_back(O2_Leak);


}
