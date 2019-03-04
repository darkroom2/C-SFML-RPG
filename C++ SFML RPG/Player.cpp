#include "pch.h"
#include "Player.h"

// init funcs
void Player::initVariables() {

}

void Player::initComponents() {
}

//ctor dtor
Player::Player(float x, float y, sf::Texture* texture) {
	this->initVariables();
	this->initComponents();

	this->createSprite(texture);
	this->setPosition(x, y);
}


Player::~Player() {
}

// functions
