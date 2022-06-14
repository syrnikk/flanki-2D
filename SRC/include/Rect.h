#pragma once

#include <SFML/Graphics.hpp>

class Rect : virtual public sf::Drawable
{
public:
	Rect();
	Rect(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& bgColor, const sf::Color& outlineColor, float outlineThickness);
	void setSize(sf::Vector2f size);
	void setBgColor(sf::Color color);
	void setRectanglePosition(sf::Vector2f buttonPosition);
	sf::RectangleShape getRectangle();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
	sf::RectangleShape rectangle;
};