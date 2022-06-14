#include "Beer.h"

Beer::Beer(const sf::Vector2f& position, const sf::Texture& texture, float scaleX, float scaleY)
{
	sprite.setTexture(texture);
	sprite.setScale(scaleX, scaleY);
	sprite.setPosition(position);
}

void Beer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite);
}

void Beer::setTexture(const sf::Texture& texture) { sprite.setTexture(texture); }
void Beer::setScale(float scaleX, float scaleY) { sprite.setScale(scaleX, scaleY); }
void Beer::setRotation(float rotation) { sprite.setRotation(rotation); }
void Beer::setPosition(const sf::Vector2f& position) { sprite.setPosition(position); }
sf::Sprite Beer::getSprite() { return sprite; }