#include "pch.h"
#include "MainMenuState.h"


void MainMenuState::initKeybinds() {
	std::ifstream ifs("Config/gamestate_keybinds.ini");
	if (ifs.is_open()) {
		std::string key = "";
		std::string key2 = "";
		while (ifs >> key >> key2)
			this->keyBinds[key] = this->supportedKeys->at(key2);
	}
	ifs.close();
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys) {
	this->initKeybinds();
	this->background.setSize((sf::Vector2f)window->getSize());
	this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState() {
}

void MainMenuState::endState() {
	std::cout << "ending MainMenuState" << "\n";
}

void MainMenuState::updateInput(const float& dt) {
	this->checkForQuit();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP"))))
		this->background.setFillColor(sf::Color::Yellow);
}

void MainMenuState::update(const float& dt) {
	this->updateInput(dt);
}

void MainMenuState::render(sf::RenderTarget* target) {
	if (!target)
		target = this->window;
	target->draw(this->background);
}
