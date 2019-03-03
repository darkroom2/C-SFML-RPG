#include "pch.h"
#include "Game.h"

// initialazer functions

void Game::initWindow() {

    sf::VideoMode window_bounds(800, 600);
    std::string title = "None";
    unsigned framerate_limit = 120;
    bool vsync_enabled = false;

    std::ifstream ifs("Config/window.ini");

    if (ifs.is_open()) {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vsync_enabled;
    }

    ifs.close();

    //sf::ContextSettings::
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vsync_enabled);
}

// constructors & destructors

Game::Game() {
    this->initWindow();
}


Game::~Game() {
    delete this->window;
}

// functions

void Game::updateDt() {
    this->dt = this->dtClock.restart().asSeconds();
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
        this->updateDt();
        this->update();
        this->render();
    }
}
