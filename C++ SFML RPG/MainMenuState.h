#pragma once
#include "Button.h"
#include "GameState.h"

class MainMenuState :
	public State {
	private:
		// REMOVE LATER
		//sf::Text mouseText;
		// END REMOVE

		// variables
		sf::Texture bgTexture;
		sf::RectangleShape background;
		sf::Font font;

		std::map<std::string, Button*> buttons;

		// functions
		void initVariables();
		void initBackground();
		void initFonts();
		void initKeybinds();
		void initButtons();

	public:
		MainMenuState(sf::RenderWindow* window,
		              std::map<std::string, int>* supportedKeys,
		              std::stack<State*>* states
		             );
		virtual ~MainMenuState();


		void updateInput(const float& dt);
		void updateButtons();
		void update(const float& dt);
		void renderButtons(sf::RenderTarget* target = nullptr);
		void render(sf::RenderTarget* target = nullptr);
};

