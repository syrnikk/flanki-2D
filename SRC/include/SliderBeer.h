#pragma once

#include <SFML/Graphics.hpp>
#include "Beer.h"

class SliderBeer : public Beer
{
public:
	SliderBeer(const sf::Vector2f& position, const sf::Texture& texture, float scaleX, float scaleY);
	void animationSlider(int min, int max, double beerStatus = 100);
	void animationSliderReset(const sf::Vector2f& position);

private:
	bool animationFlag;
};