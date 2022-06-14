#pragma once

#include <SFML/Graphics.hpp>
#include "Beer.h"
#include "Text.h"

class Student : public sf::Drawable
{
public:
	Student(int id, const sf::Vector2f& position, const sf::Texture& texture, const sf::Vector2f& crushedCanPosition, bool isFlipped = false);
	int getId();
	sf::Vector2f getCrushedCanPosition();
	void nextSprite();
	bool throwingAnimation(Beer& crushedCan, Beer& beer, Text& text, bool hit);
	bool raisingAnimation(Beer& crushedCan, Beer& beer);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	int id;
	static const int width = 165;
	static const int height = 292;
	sf::Sprite sprite;
	bool isFlipped;
	sf::Vector2f crushedCanPosition;
	sf::Vector2f initialPosition;
};