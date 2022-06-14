#include "Text.h"

Text::Text() = default;

Text::Text(const std::string& t, const sf::Font& font, const sf::Color& textColor, const sf::Vector2f& textPosition, const sf::Color& outlineColor, float outlineThickness, int charSize)
{
	text.setString(t);
	text.setFont(font);
	text.setFillColor(textColor);
	text.setPosition(textPosition);
	text.setCharacterSize(charSize);
	text.setOutlineColor(outlineColor);
	text.setOutlineThickness(outlineThickness);
}

void Text::setString(std::string t) { text.setString(t); }
void Text::setFont(sf::Font font) { text.setFont(font); }
void Text::setTextColor(sf::Color textColor) { text.setFillColor(textColor); }
void Text::setTextPosition(sf::Vector2f position) { text.setPosition(position); }
void Text::setCharSize(int charSize) { text.setCharacterSize(charSize); }

void Text::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(text);
}
