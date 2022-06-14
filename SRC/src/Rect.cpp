#include "Rect.h"

Rect::Rect() = default;

Rect::Rect(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& bgColor, const sf::Color& outlineColor, float outlineThickness)
{
	rectangle.setSize(size);
	rectangle.setFillColor(bgColor);
	rectangle.setPosition(position);
	rectangle.setOutlineColor(outlineColor);
	rectangle.setOutlineThickness(outlineThickness);
}

void Rect::setSize(sf::Vector2f size) { this->rectangle.setSize(size); }
void Rect::setBgColor(sf::Color bgColor) { this->rectangle.setFillColor(bgColor); }
void Rect::setRectanglePosition(sf::Vector2f position) { rectangle.setPosition(position); }
sf::RectangleShape Rect::getRectangle() { return rectangle; }

void Rect::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectangle);
}