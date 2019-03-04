#pragma once
class MovementComponent {
	private:
		// variables
		float maxVelocity;
		sf::Vector2f velocity;
		sf::Vector2f acceleration;
		sf::Vector2f deceleration;

		// init funcs
		void initVariables();

	public:
		MovementComponent(float maxVelocity);
		virtual ~MovementComponent();

		// accesor
		const sf::Vector2f& getVelocity() const;

		// functions
		void move(const float dir_x, const float dir_y);
		void update(const float& dt);
};

