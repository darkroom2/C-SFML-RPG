#include "pch.h"
#include "GameState.h"


void GameState::initKeybinds() {
    this->keyBinds.emplace("MOVE_UP", this->supportedKeys->at('W'));
    this->keyBinds.emplace("MOVE_DOWN", this->supportedKeys->at('S'));
    this->keyBinds.emplace("MOVE_LEFT", this->supportedKeys->at('A'));
    this->keyBinds.emplace("MOVE_RIGHT", this->supportedKeys->at('D'));
}

GameState::GameState(sf::RenderWindow* window, std::map<char, int>* supportedKeys)
    : State(window, supportedKeys) {
    this->initKeybinds();
}


GameState::~GameState() {
}

void GameState::endState() {
    std::cout << "ending GameState" << "\n";
}

void GameState::updateInput(const float & dt) {
    this->checkForQuit();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP"))))
        this->player.move(dt, 0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_DOWN"))))
        this->player.move(dt, 0.f, 1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_LEFT"))))
        this->player.move(dt, -1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_RIGHT"))))
        this->player.move(dt, 1.f, 0.f);
}

void GameState::update(const float& dt) {
    this->updateInput(dt);
    this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target) {
    if (!target)
        target = this->window;
    this->player.render(target);
}
