#pragma once
class State {
	private:

	protected:
		std::stack<State*>* states;
		sf::RenderWindow* window;
		std::map<std::string, int>* supportedKeys;
		std::map<std::string, int> keyBinds;

		bool quit;

		sf::Vector2i mousePosScreen;
		sf::Vector2i mousePosWindow;
		sf::Vector2f mousePosView;

		// resources
		std::vector<sf::Texture> textures;

		// functions
		virtual void initKeybinds() = 0;

	public:
		State(sf::RenderWindow* window,
		      std::map<std::string, int>* supportedKeys,
		      std::stack<State*>* states
		     );
		virtual ~State();

		const bool& getQuit() const;
		void endState();

		virtual void updateMousePos();
		virtual void updateInput(const float& dt) = 0;
		virtual void update(const float& dt) = 0;
		virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

