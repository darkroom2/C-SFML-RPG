#include "pch.h"
#include "MainMenuState.h"

void MainMenuState::initFonts() {
	if (this->font.loadFromFile("Resources/Fonts/Century Gothic.ttf"))
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
}

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

MainMenuState::MainMenuState(sf::RenderWindow* window,
                             std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys) {
	this->initFonts();
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
	this->updateMousePos();
	this->updateInput(dt);

	std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";
	std::cout << this->mousePosWindow.x << " " << this->mousePosWindow.y << "\n";
	std::cout << this->mousePosScreen.x << " " << this->mousePosScreen.y << "\n";
}

void MainMenuState::render(sf::RenderTarget* target) {
	if (!target)
		target = this->window;
	target->draw(this->background);
}
