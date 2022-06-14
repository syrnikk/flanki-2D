#include "Button.h"

Button::Button(const sf::Vector2f& size, const sf::Color& bgColor, const sf::Vector2f& buttonPosition, const sf::Color& outlineColor, float outlineThickness, const std::string& t, const sf::Font& font, const sf::Color& textColor, const sf::Vector2f& textPosition, int charSize)
{
	rectangle.setSize(size);
	rectangle.setFillColor(bgColor);
	rectangle.setPosition(buttonPosition);
	rectangle.setOutlineColor(outlineColor);
	rectangle.setOutlineThickness(outlineThickness);

	text.setString(t);
	text.setFont(font);
	text.setFillColor(textColor);
	text.setPosition(textPosition);
	text.setCharacterSize(charSize);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectangle);
	target.draw(text);
}

bool Button::isMouseOver(sf::RenderWindow& window)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float windowSizeX = window.getSize().x;
	float windowSizeY = window.getSize().y;

	float btnPosX = rectangle.getPosition().x * (windowSizeX / 1920);
	float btnPosY = rectangle.getPosition().y * (windowSizeY / 1080);

	float btnPosWidth = (rectangle.getPosition().x + rectangle.getLocalBounds().width) * (windowSizeX / 1920);
	float btnPosHeight = (rectangle.getPosition().y + rectangle.getLocalBounds().height) * (windowSizeY / 1080);

	if (mouseX < btnPosWidth && mouseX > btnPosX && mouseY < btnPosHeight && mouseY > btnPosY)
	{
		return true;
	}
	return false;
}