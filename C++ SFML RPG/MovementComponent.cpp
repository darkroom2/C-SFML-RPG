#include "pch.h"
#include "MovementComponent.h"


MovementComponent::MovementComponent(float maxVelocity) {
	this->maxVelocity = maxVelocity;
}


MovementComponent::~MovementComponent() {
}


// accesor



const sf::Vector2f& MovementComponent::getVelocity() const {
	return this->velocity;
}

// functions

void MovementComponent::move(const float dir_x,
                             const float dir_y/*, const float& dt*/) {
	this->velocity.x = this->maxVelocity * dir_x;
	this->velocity.y = this->maxVelocity * dir_y;
}

void MovementComponent::update(const float& dt) {
}
