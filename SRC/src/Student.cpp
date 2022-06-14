#include "Student.h"

Student::Student(int id, const sf::Vector2f& position, const sf::Texture& texture, const sf::Vector2f& crushedCanPosition, bool isFlipped)
{
    this->id = id;
    initialPosition = position;
    this->crushedCanPosition = crushedCanPosition;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, width, height));
    sprite.setPosition(position);
    this->isFlipped = isFlipped;
    if (isFlipped)
        sprite.setScale(sf::Vector2f(-1, 1));
}

void Student::nextSprite()
{
    static int x = 0, y = 0;
    x++;
    if (x > 11)
        y++;
    x %= 12;
    y %= 2;
    if (y == 1 && x == 11)
        x = y = 0;
    sprite.setTextureRect(sf::IntRect(x * width, y * height, width, height));
    if (isFlipped)
        sprite.setScale(sf::Vector2f(-1, 1));
}

void Student::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

int Student::getId() { return id; }
sf::Vector2f Student::getCrushedCanPosition() { return crushedCanPosition; }

bool Student::throwingAnimation(Beer& crushedCan, Beer& beer, Text& text, bool hit)
{
    sf::Vector2f position = crushedCan.getSprite().getPosition();
    float x = position.x;
    float y = position.y;
    float deltaX = 13;
    static int delay = 0;

    if (hit)
    {
        text.setString("Hit");
        text.setTextPosition(sf::Vector2f(825, 100));
    }
    else
    {
        text.setString("Missed");
        text.setTextPosition(sf::Vector2f(690, 100));
    }

    if (!isFlipped && x + deltaX < 925)
    {
        x = x + deltaX;
        if (id % 3 == 1 && hit)
        {
            y = y + 2;
        }
        else if (id % 3 == 0 && hit)
        {
            y = y - 0.7;
        }
        else if (id % 3 == 1)
        {
            y = y + 5;
        }
        else if (id % 3 == 0)
        {
            y = y - 3;
        }
        else if (id % 3 == 2 && !hit)
        {
            y = y - 2;
        }
        else
        {
            y = y + 1;
        }
        crushedCan.setPosition(sf::Vector2f(x, y));
        return true;
    }
    else if (isFlipped && x - deltaX > 925)
    {
        x = x - deltaX;
        if (id % 3 == 1 && hit)
        {
            y = y + 2;
        }
        else if (id % 3 == 0 && hit)
        {
            y = y - 0.7;
        }
        else if (id % 3 == 1)
        {
            y = y - 1;
        }
        else if (id % 3 == 0)
        {
            y = y + 3;
        }
        else if (id % 3 == 2 && !hit)
        {
            y = y + 3;
        }
        else
        {
            y = y + 1;
        }
        crushedCan.setPosition(sf::Vector2f(x, y));
        return true;
    }
    else
    {
        delay++;
        if (delay < 5)
            return true;
        if (hit)
        {
            crushedCan.setPosition(sf::Vector2f(2000, 1200));
            beer.setRotation(90);
        }
        delay = 0;
        return false;
    }
}

bool Student::raisingAnimation(Beer& crushedCan, Beer& beer)
{
    sf::Vector2f position = sprite.getPosition();
    float x = position.x;
    float y = position.y;
    float deltaX = 7;
    float deltaY = 0.5;
    static int delay = 0;
    static bool isReturning = false;
    
    if (!isReturning)
    {
        if (!isFlipped && x + deltaX < 750)
        {
            x = x + deltaX;
            if (id % 3 == 0)
            {
                y = y + deltaY;
            }
            else if (id % 3 == 2)
            {
                y = y - deltaY;
            }
            this->nextSprite();
            sprite.setPosition(sf::Vector2f(x, y));
            return true;
        }
        else if (isFlipped && x - deltaX > 1100)
        {
            x = x - deltaX;
            if (id % 3 == 0)
            {
                y = y + deltaY;
            }
            else if (id % 3 == 2)
            {
                y = y - deltaY;
            }
            this->nextSprite();
            sprite.setPosition(sf::Vector2f(x, y));
            return true;
        }
        else
        {
            delay++;
            if (delay < 20)
                return true;
            beer.setRotation(0);
            if (delay < 40)
                return true;
            isReturning = true;
            delay = 0;
            return true;
        }
    }
    else
    {
        if (!isFlipped && x - deltaX > 300)
        {
            x = x - deltaX;
            if (id % 3 == 0)
            {
                y = y - deltaY;
            }
            else if (id % 3 == 2)
            {
                y = y + deltaY;
            }
            this->nextSprite();
            sprite.setScale(-1, 1);
            sprite.setPosition(sf::Vector2f(x, y));
            return true;
        }
        else if (isFlipped && x + deltaX < 1500)
        {
            x = x + deltaX;
            if (id % 3 == 0)
            {
                y = y - deltaY;
            }
            else if (id % 3 == 2)
            {
                y = y + deltaY;
            }
            this->nextSprite();
            sprite.setScale(1, 1);
            sprite.setPosition(sf::Vector2f(x, y));
            return true;
        }
        else
        {
            sprite.setTextureRect(sf::IntRect(0, 0, width, height));
            if (isFlipped)
                sprite.setScale(-1, 1);
            else
                sprite.setScale(1, 1);
            sprite.setPosition(initialPosition);
            crushedCan.setPosition(this->getCrushedCanPosition());
            isReturning = false;
            return false;
        }
    }
}