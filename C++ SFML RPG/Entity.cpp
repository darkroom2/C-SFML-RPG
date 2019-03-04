#include "pch.h"
#include "Entity.h"


void Entity::initVariables() {
	this->texture = nullptr;
	this->sprite = nullptr;
	this->moveComp = nullptr;
}

Entity::Entity() {
	this->initVariables();
}


Entity::~Entity() {
	delete this->sprite;
}

// component functions
void Entity::createSprite(sf::Texture* texture) {
	this->texture = texture;
	this->sprite = new sf::Sprite(*this->texture);
}

void Entity::createMoveComp(const float maxVelocity) {
	this->moveComp = new MovementComponent(maxVelocity);
}


// functions
void Entity::setPosition(const float x, const float y) {
	if (this->sprite)
		this->sprite->setPosition(x, y);
}

void Entity::move(const float& dt, const float dir_x, const float dir_y) {
	if (this->sprite && this->moveComp) {
		this->moveComp->move(dir_x, dir_y);
		this->sprite->move(this->moveComp->getVelocity() * dt);
	}
}

void Entity::update(const float& dt) {

}

void Entity::render(sf::RenderTarget* target) {
	if (this->sprite)
		target->draw(*this->sprite);
}
