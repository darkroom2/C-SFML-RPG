#include "pch.h"
#include "Entity.h"


void Entity::initVariables() {
	this->texture = nullptr;
	this->sprite = nullptr;
	this->moveSpeed = 350.f;
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
	this->sprite->setTexture(*this->texture);
}


// functions
void Entity::move(const float& dt, const float dir_x, const float dir_y) {
	if(this->sprite)
		this->sprite->move(dir_x * this->moveSpeed * dt, dir_y * this->moveSpeed * dt);
}

void Entity::update(const float& dt) {

}

void Entity::render(sf::RenderTarget* target) {
	if(this->sprite)
		target->draw(*this->sprite);
}
