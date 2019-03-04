#include "pch.h"
#include "State.h"


State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) {
	this->window = window;
	this->supportedKeys = supportedKeys;
}


State::~State() {
}

const bool& State::getQuit() const {
	return this->quit;
}

void State::checkForQuit() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("CLOSE"))))
		this->quit = true;
}