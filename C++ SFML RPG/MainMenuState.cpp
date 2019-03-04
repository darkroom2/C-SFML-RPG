#include "pch.h"
#include "MainMenuState.h"

// init functions

void MainMenuState::initVariables() {
	// REMOVE LATER
	//this->mouseText.setPosition(this->mousePosView + sf::Vector2f(0.1f, 0.1f));
	//this->mouseText.setFont(this->font);
	//this->mouseText.setCharacterSize(12);
	// END REMOVE
}

void MainMenuState::initBackground() {
	this->background.setSize((sf::Vector2f)this->window->getSize());
	if (!this->bgTexture.loadFromFile("Resources/Images/Backgrounds/bg1.png")) {
		std::cout << "ERROR::MAINMENUSTATE::FAILED TO LOAD TEXTURE" << "\n";
		throw("ERROR::MAINMENUSTATE::FAILED TO LOAD TEXTURE");
	}
	this->background.setTexture(&this->bgTexture);
}

void MainMenuState::initFonts() {
	if (!this->font.loadFromFile("Resources/Fonts/CenturyGothic.ttf")) {
		std::cout << "Error font" << "\n";
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::initKeybinds() {
	std::ifstream ifs("Config/mainmenustate_keybinds.ini");
	if (ifs.is_open()) {
		std::string key = "";
		std::string key2 = "";
		while (ifs >> key >> key2)
			this->keyBinds[key] = this->supportedKeys->at(key2);
	}
	ifs.close();
}

void MainMenuState::initButtons() {
	this->buttons["BTN_GAME_STATE"] = new Button(300, 480, 150, 50,
	                                             &this->font, "Play",
	                                             sf::Color(50, 50, 50, 200),
	                                             sf::Color(70, 70, 70, 200),
	                                             sf::Color(150, 150, 150, 255)
	                                            );
	this->buttons["BTN_SETTINGS_STATE"] = new Button(300, 580, 150, 50,
	                                                 &this->font, "Settings",
	                                                 sf::Color(50, 50, 50, 200),
	                                                 sf::Color(70, 70, 70, 200),
	                                                 sf::Color(150, 150, 150, 255)
	                                                );
	this->buttons["BTN_EXIT_STATE"] = new Button(300, 780, 150, 50,
	                                             &this->font, "Quit",
	                                             sf::Color(20, 20, 20, 200),
	                                             sf::Color(70, 70, 70, 200),
	                                             sf::Color(150, 150, 150, 255)
	                                            );
}

MainMenuState::MainMenuState(sf::RenderWindow* window,
                             std::map<std::string, int>* supportedKeys,
                             std::stack<State*>* states
                            )
	: State(window, supportedKeys, states) {
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
}

MainMenuState::~MainMenuState() {
	for (auto& i : buttons) {
		delete i.second;
	}
}

void MainMenuState::endState() {
	std::cout << "ending MainMenuState" << "\n";
}

void MainMenuState::updateInput(const float& dt) {
	this->checkForQuit();
}

void MainMenuState::updateButtons() {
	for (const auto& i : this->buttons) {
		i.second->update(this->mousePosView);
	}

	// new game button action
	if (this->buttons["BTN_GAME_STATE"]->isPressed()) {
		this->states->push(new GameState(this->window, this->supportedKeys,
		                                 this->states));
	}

	// quit button action
	if (this->buttons["BTN_EXIT_STATE"]->isPressed()) {
		this->endState();
		this->quit = true;
	}
}

void MainMenuState::update(const float& dt) {
	this->updateMousePos();
	this->updateInput(dt);
	this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget* target) {
	for (const auto& i : this->buttons) {
		i.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target) {
	if (!target)
		target = this->window;
	target->draw(this->background);
	this->renderButtons(target);

	// REMOVE LATER
	//this->mouseText.setPosition(this->mousePosView + sf::Vector2f(-15.0f, -15.0f));
	//std::stringstream ss;
	//ss << this->mousePosView.x << " " << this->mousePosView.y << "\n";
	//this->mouseText.setString(ss.str());
	//target->draw(this->mouseText);
	// END REMOVE

}
