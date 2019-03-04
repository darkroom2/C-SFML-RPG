#pragma once
#include "GameState.h"
#include "MainMenuState.h"

class Game {
	private:
		// variables
		sf::RenderWindow* window;
		sf::Event sfEvent;
		std::vector<sf::VideoMode> videoModes;
		sf::ContextSettings windowSettings;
		bool fullscreen_enabled;

		sf::Clock dtClock;
		float dt;

		std::stack<State*> states;

		std::map<std::string, int> supportedKeys;

		// init funcs
		void initVariables();
		void initWindow();
		void initStates();
		void initKeys();

	public:
		Game();
		virtual ~Game();

		// functions
		void updateDt();
		void updateSFMLEvents();
		void update();
		void render();
		void run();
};

