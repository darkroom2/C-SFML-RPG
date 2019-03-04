#include "pch.h"
#include "MainMenuState.h"

void MainMenuState::initFonts() {
	if (!this->font.loadFromFile("Resources/Fonts/CenturyGothic.ttf")) {
		std::cout << "Error font" << "\n";
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::initKeybinds() {
	std::ifstream ifs("Config/mainmenustate_keybinds.ini");
	if (ifs.is_open()) {
		std::string key = "";
		std::string key2 = "";
		while (ifs >> key >> key2)
			this->keyBinds[key] = this->supportedKeys->at(key2);
	}
	ifs.close();
}

void MainMenuState::initButtons() {
	this->buttons["BTN_GAME_STATE"] = new Button(100, 100, 150, 50,
	                                             &this->font, "Start",
	                                             sf::Color(20, 20, 20, 200),
	                                             sf::Color(70, 70, 70, 200),
	                                             sf::Color(150, 150, 150, 255)
	                                            );
	this->buttons["BTN_EXIT_STATE"] = new Button(100, 200, 150, 50,
	                                             &this->font, "Quit",
	                                             sf::Color(20, 20, 20, 200),
	                                             sf::Color(70, 70, 70, 200),
	                                             sf::Color(150, 150, 150, 255)
	                                            );
}

MainMenuState::MainMenuState(sf::RenderWindow* window,
                             std::map<std::string, int>* supportedKeys,
                             std::stack<State*>* states
                            )
	: State(window, supportedKeys, states) {
	this->initFonts();
	this->initKeybinds();
	this->initButtons();

	this->background.setSize((sf::Vector2f)window->getSize());
	this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState() {
	for (auto& i : buttons) {
		delete i.second;
	}
}

void MainMenuState::endState() {
	std::cout << "ending MainMenuState" << "\n";
}

void MainMenuState::updateInput(const float& dt) {
	this->checkForQuit();
}

void MainMenuState::updateButtons() {
	for (const auto& i : this->buttons) {
		i.second->update(this->mousePosView);
	}

	// new game button action
	if (this->buttons["BTN_GAME_STATE"]->isPressed()) {
		this->states->push(new GameState(this->window, this->supportedKeys,
		                                 this->states));
	}

	// quit button action
	if (this->buttons["BTN_EXIT_STATE"]->isPressed()) {
		this->endState();
		this->quit = true;
	}
}

void MainMenuState::update(const float& dt) {
	this->updateMousePos();
	this->updateInput(dt);
	this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget* target) {
	for (const auto& i : this->buttons) {
		i.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target) {
	if (!target)
		target = this->window;
	target->draw(this->background);
	this->renderButtons(target);

}
