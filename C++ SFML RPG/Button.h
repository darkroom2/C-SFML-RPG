#pragma once
class Button {
	private:
		short unsigned btnState;

		sf::RectangleShape shape;
		sf::Font* font;
		sf::Text text;

		sf::Color idleColor;
		sf::Color hoverColor;
		sf::Color activeColor;



	public:
		Button(float x, float y,
		       float width, float height,
		       sf::Font* font,
		       std::string text,
		       sf::Color idleColor,
		       sf::Color hoverColor,
		       sf::Color activeColor
		      );
		~Button();
		// accessors
		const bool isPressed() const;
		// functions
		void update(const sf::Vector2f mousePos);
		void render(sf::RenderTarget* target);
};

