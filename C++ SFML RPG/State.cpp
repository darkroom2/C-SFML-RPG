#include "pch.h"
#include "State.h"


State::State(sf::RenderWindow* window, std::map<char, int>* supportedKeys) {
    this->window = window;
    this->supportedKeys = supportedKeys;
}


State::~State() {
}

const bool & State::getQuit() const {
    return this->quit;
}

void State::checkForQuit() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        this->quit = true;
}