#pragma once
#include "Entity.h"
class Player :
	public Entity {
	private:
		// variables

		// init funcs
		void initVariables();
		void initComponents();
		// functions
	public:
		Player(float x, float y, sf::Texture* texture);
		virtual ~Player();

		// functions
};

