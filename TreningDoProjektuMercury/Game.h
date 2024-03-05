#ifndef GAME_H
#define GAME_H
#include "GameState.h"

class Game
{
private:
	//Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;
	bool fullscreen;

	sf::Clock dtClock;
	float dt;

	std::stack <State*> states;

	std::map<std::string, int> supportedKeys;
	//Initialization
	void initVariables();
	void initWindow();
	void initKeys();
	void initStates();
	

public:
	//Constructors and destructors
	Game();
	virtual ~Game();
	

	void endApplication();
	//Functions
	void updateDt();
	void update();
	void updateSFMLEvents();
	void render();
	void run();
};
#endif // !GAME_H



