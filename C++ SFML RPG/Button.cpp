#include "pch.h"
#include "Button.h"

enum button_state { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

Button::Button(float x, float y,
               float width, float height,
               sf::Font* font,
               std::string text,
               sf::Color idleColor,
               sf::Color hoverColor,
               sf::Color activeColor) {

	this->btnState = BTN_IDLE;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(12);

	this->text.setPosition(
	    this->shape.getPosition().x / 2.f - this->text.getGlobalBounds().width / 2.f,
	    this->shape.getPosition().y / 2.f - this->text.getGlobalBounds().height / 2.f
	);

	this->idleColor = idleColor;
	this->idleColor = hoverColor;
	this->idleColor = activeColor;

	this->shape.setFillColor(this->idleColor);
}


Button::~Button() {
}


// accessors

const bool Button::isPressed() const {
	if (this->btnState == BTN_ACTIVE)
		return true;
	return false;
}


// functions

void Button::update(const sf::Vector2f mousePos) {
	// update the bools for hover and press

	// idle
	this->btnState = BTN_IDLE;

	// hover
	if (this->shape.getGlobalBounds().contains(mousePos)) {
		this->btnState = BTN_HOVER;

		// pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->btnState = BTN_ACTIVE;
		}
	}

	switch (this->btnState) {
		case BTN_IDLE:
			this->shape.setFillColor(this->idleColor);
			break;
		case BTN_HOVER:
			this->shape.setFillColor(this->hoverColor);
			break;
		case BTN_ACTIVE:
			this->shape.setFillColor(this->activeColor);
			break;
		default:
			this->shape.setFillColor(sf::Color::Red);
			break;
	}
}

void Button::render(sf::RenderTarget* target) {
	target->draw(this->shape);
}
