#pragma once
class Entity {
	private:

	protected:
		sf::RectangleShape shape;
		float moveSpeed;

	public:
		Entity();
		virtual ~Entity();

		// functions
		virtual void move(const float& dt, const float x, const float y);

		virtual void update(const float& dt);
		virtual void render(sf::RenderTarget* target);
};

