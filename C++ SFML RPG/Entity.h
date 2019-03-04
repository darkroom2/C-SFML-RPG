#pragma once
#include "MovementComponent.h"

class Entity {
	private:
		void initVariables();
	protected:
		sf::Texture* texture;
		sf::Sprite* sprite;

		MovementComponent* moveComp;

	public:
		Entity();
		virtual ~Entity();

		// component functions
		void createSprite(sf::Texture* texture);
		void createMoveComp(const float maxVelocity);

		// functions
		virtual void setPosition(const float x, const float y);
		virtual void move(const float& dt, const float x, const float y);

		virtual void update(const float& dt);
		virtual void render(sf::RenderTarget* target);
};

