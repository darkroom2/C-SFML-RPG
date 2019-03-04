#include "pch.h"
#include "MainMenuState.h"

void MainMenuState::initFonts() {
	if (!this->font.loadFromFile("Resources/Fonts/CenturyGothic.ttf")) {
		std::cout << "Error font" << "\n";
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
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
	this->gamestate_btn = new Button(100, 100, 150, 50,
	                                 &this->font, "Start",
	                                 sf::Color(20, 20, 20, 200),
	                                 sf::Color(70, 70, 70, 200),
	                                 sf::Color(150, 150, 150, 255)
	                                );
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

	this->gamestate_btn->update(this->mousePosView);
}

void MainMenuState::render(sf::RenderTarget* target) {
	if (!target)
		target = this->window;
	target->draw(this->background);

	this->gamestate_btn->render(target);
}
