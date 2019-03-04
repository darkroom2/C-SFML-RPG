#pragma once
#include "State.h"
#include "Button.h"

class MainMenuState :
	public State {
	private:
		// variables
		sf::RectangleShape background;
		sf::Font font;

		Button* gamestate_btn;

		// functions
		void initFonts();
		void initKeybinds();

	public:
		MainMenuState(sf::RenderWindow* window,
		              std::map<std::string, int>* supportedKeys);
		virtual ~MainMenuState();


		void endState();
		void updateInput(const float& dt);
		void update(const float& dt);
		void render(sf::RenderTarget* target = nullptr);
};

