#include "pch.h"
#include "GameState.h"

// init funcs
void GameState::initKeybinds() {
	std::ifstream ifs("Config/gamestate_keybinds.ini");
	if (ifs.is_open()) {
		std::string key = "";
		std::string key2 = "";
		while (ifs >> key >> key2)
			this->keyBinds[key] = this->supportedKeys->at(key2);
	}
	ifs.close();
}

void GameState::initTextures() {
	if (!this->textures["TEX_PLAYER_IDLE"].loadFromFile(
	        "Resources/Images/Sprites/Player/stand.png")) {
		std::cout << "ERROR::GAMESTATE::FAILED TO LOAD TEXTURE\n";
		throw("ERROR::GAMESTATE::FAILED TO LOAD TEXTURE");
	}
}

void GameState::initPlayers() {
	this->player = new Player(0, 0, &this->textures["TEX_PLAYER_IDLE"]);
}


// ctor dtor
GameState::GameState(sf::RenderWindow* window,
                     std::map<std::string, int>* supportedKeys,
                     std::stack<State*>* states
                    )
	: State(window, supportedKeys, states) {
	this->initKeybinds();
	this->initTextures();
	this->initPlayers();
}

GameState::~GameState() {
	delete this->player;

}


void GameState::updateInput(const float& dt) {
	//this->checkForQuit();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP"))))
		this->player->move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(
	                                   this->keyBinds.at("MOVE_DOWN"))))
		this->player->move(dt, 0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(
	                                   this->keyBinds.at("MOVE_LEFT"))))
		this->player->move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(
	                                   this->keyBinds.at("MOVE_RIGHT"))))
		this->player->move(dt, 1.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("CLOSE"))))
		this->endState();
}

void GameState::update(const float& dt) {
	this->updateMousePos();
	this->updateInput(dt);
	this->player->update(dt);
}

void GameState::render(sf::RenderTarget* target) {
	if (!target)
		target = this->window;
	this->player->render(target);
}
