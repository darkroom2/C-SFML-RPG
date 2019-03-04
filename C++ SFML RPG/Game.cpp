#include "pch.h"
#include "Game.h"

// initialazer functions

void Game::initVariables() {
	this->window = nullptr;
	this->fullscreen_enabled = false;
	this->dt = 0.f;
}

void Game::initWindow() {

	this->videoModes = sf::VideoMode::getFullscreenModes();

	std::string title = "Default";
	sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
	this->fullscreen_enabled = true;
	unsigned framerate_limit = 120;
	bool vsync_enabled = true;
	unsigned antialiasing_level = 2;

	std::ifstream ifs("Config/window.ini");

	if (ifs.is_open()) {
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> this->fullscreen_enabled;
		ifs >> framerate_limit;
		ifs >> vsync_enabled;
		ifs >> antialiasing_level;
	}

	ifs.close();

	this->windowSettings.antialiasingLevel = antialiasing_level;

	// windowed
	sf::Uint32 style = sf::Style::Titlebar | sf::Style::Close;
	// fullscreen
	if (this->fullscreen_enabled)
		style = sf::Style::Fullscreen;

	this->window = new sf::RenderWindow(window_bounds, title, style,
	                                    this->windowSettings);
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
	this->states.push(new MainMenuState(this->window, &this->supportedKeys,
	                                    &this->states));
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