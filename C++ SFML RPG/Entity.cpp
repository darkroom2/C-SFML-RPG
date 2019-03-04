#include "pch.h"
#include "Entity.h"


Entity::Entity() {
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->shape.setFillColor(sf::Color::White);
	this->moveSpeed = 50.f;
}


Entity::~Entity() {
}

void Entity::move(const float& dt, const float dir_x, const float dir_y) {
	this->shape.move(dir_x * this->moveSpeed * dt, dir_y * this->moveSpeed * dt);
}

void Entity::update(const float& dt) {

}

void Entity::render(sf::RenderTarget* target) {
	target->draw(this->shape);
}
