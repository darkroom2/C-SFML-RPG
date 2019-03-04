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
	std::ifstream ifs("Config/supported_keys.ini");
	if (ifs.is_open()) {
		std::string key = "";
		int key_value = 0;
		while (ifs >> key >> key_value)
			this->supportedKeys[key] = key_value;
	}
	ifs.close();
	this->supportedKeys["Esc"] = sf::Keyboard::Escape;
	this->supportedKeys["W"] = sf::Keyboard::W;
	this->supportedKeys["S"] = sf::Keyboard::S;
	this->supportedKeys["A"] = sf::Keyboard::A;
	this->supportedKeys["D"] = sf::Keyboard::D;

	// debug info
	for (const auto& i : this->supportedKeys) {
		std::cout << i.first << ", " << i.second << "\n";
	}
}

void Game::initStates() {
	this->states.push(new MainMenuState(this->window, &this->supportedKeys));
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
