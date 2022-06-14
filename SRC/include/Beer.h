#pragma once

#include <SFML/Graphics.hpp>

class Beer : public sf::Drawable
{
public:
	Beer(const sf::Vector2f& position, const sf::Texture& texture, float scaleX, float scaleY);
	void setTexture(const sf::Texture& texture);
	void setScale(float scaleX, float scaleY);
	void setRotation(float rotation);
	void setPosition(const sf::Vector2f& position);
	sf::Sprite getSprite();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
	sf::Sprite sprite;
};