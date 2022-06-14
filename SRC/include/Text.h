#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class Text : virtual public sf::Drawable
{
public:
	Text();
	Text(const std::string& t, const sf::Font& font, const sf::Color& textColor, const sf::Vector2f& textPosition, const sf::Color& outlineColor, float outlineThickness, int charSize);
	void setString(std::string t);
	void setFont(sf::Font font);
	void setTextColor(sf::Color color);
	void setCharSize(int charSize);
	void setTextPosition(sf::Vector2f textPosition);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
	sf::Text text;
};