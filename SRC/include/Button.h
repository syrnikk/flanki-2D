#pragma once

#include <SFML/Graphics.hpp>
#include "Text.h"
#include "Rect.h"

class Button : public Text, public Rect
{
public:
	Button(const sf::Vector2f& size, const sf::Color& bgColor, const sf::Vector2f& buttonPosition, const sf::Color& outlineColor, float outlineThickness, const std::string& t, const sf::Font& font, const sf::Color& textColor, const sf::Vector2f& textPosition, int charSize);
	bool isMouseOver(sf::RenderWindow& window);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};