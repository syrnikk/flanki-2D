#include "SliderBeer.h"

SliderBeer::SliderBeer(const sf::Vector2f& position, const sf::Texture& texture, float scaleX, float scaleY) :
	Beer(position, texture, scaleX, scaleY) 
{
    animationFlag = true;
};

void SliderBeer::animationSlider(int min, int max, double beerStatus)
{
    float x = sprite.getPosition().x;
    float delta_x = 13 + 10 * (100 - beerStatus) / 100;
    if (animationFlag && (x + delta_x < max))
    {
        sprite.setPosition(x + delta_x, 970);
    }
    else if (animationFlag && !(x + delta_x < max))
    {
        animationFlag = false;
        sprite.setPosition(x - delta_x, 970);
    }
    else if (!animationFlag && (x - delta_x > min))
    {
        sprite.setPosition(x - delta_x, 970);
    }
    else if (!animationFlag && !(x - delta_x > min))
    {
        animationFlag = true;
        sprite.setPosition(x + delta_x, 970);
    }
}

void SliderBeer::animationSliderReset(const sf::Vector2f& position)
{
    sprite.setPosition(position);
    animationFlag = true;
}