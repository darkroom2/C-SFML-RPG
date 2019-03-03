#include "pch.h"
#include "Game.h"

// initialazer functions

void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "C++ SFML RPG");
}

Game::Game() {
    this->initWindow();
}


Game::~Game() {
    delete this->window;
}

void Game::updateSFMLEvents() {
    while (this->window->pollEvent(this->sfEvent)) {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update() {
    this->updateSFMLEvents();
}

void Game::render() {
    this->window->clear();
    //this->window.draw(shape);
    this->window->display();
}

void Game::run() {
    while (this->window->isOpen()) {
        this->update();
        this->render();
    }
}

//Functions