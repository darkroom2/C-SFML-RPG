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

void Game::initKeys() {
    this->supportedKeys.emplace('W', sf::Keyboard::W);
    this->supportedKeys.emplace('S', sf::Keyboard::S);
    this->supportedKeys.emplace('A', sf::Keyboard::A);
    this->supportedKeys.emplace('D', sf::Keyboard::D);
}

void Game::initStates() {
    this->states.push(new GameState(this->window, &this->supportedKeys));
}

// constructors & destructors

Game::Game() {
    this->initWindow();
    this->initKeys();
    this->initStates();
}


Game::~Game() {
    delete this->window;
    while (!this->states.empty()) {
        delete this->states.top();
        this->states.pop();
    }
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

    if (!this->states.empty()) {
        this->states.top()->update(this->dt);
        if (this->states.top()->getQuit()) {
            delete this->states.top();
            this->states.pop();
        }
    }

    else {
        this->window->close();
    }
}

void Game::render() {
    this->window->clear();
    //this->window.draw(shape);
    if (!this->states.empty()) {
        this->states.top()->render();
    }
    this->window->display();
}

void Game::run() {
    while (this->window->isOpen()) {
        this->updateDt();
        update();
        render();
    }
}
