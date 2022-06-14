#include <Windows.h>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Student.h"
#include "Beer.h"
#include "SliderBeer.h"
#include "Text.h"
#include "Rect.h"
#include "Button.h"
#include "images.h"
#include "fonts.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Flanki 2D");
    window.setFramerateLimit(60);

    // fonts
    sf::Font openSans;
    if (!openSans.loadFromMemory(OpenSans_Bold_ttf, OpenSans_Bold_ttf_len))
    {
        throw("Failed to load font OpenSans-Bold.ttf");
    }

    // cursors
    sf::Cursor arrowCursor;
    if (!arrowCursor.loadFromSystem(sf::Cursor::Arrow))
    {
        throw("Failed to load arrow cursor");
    }
    sf::Cursor handCursor;
    if (!handCursor.loadFromSystem(sf::Cursor::Hand))
    {
        throw("Failed to load hand cursor");
    }
    
    // background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromMemory(miasteczko_jpg, miasteczko_jpg_len))
    {
        throw("Failed to load miasteczko.jpg");
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    // students
    sf::Texture studentTexture;
    if (!studentTexture.loadFromMemory(student_png, student_png_len))
    {
        throw("Failed to load student.png");
    }
    Student student1(0, sf::Vector2f(250, 450), studentTexture, sf::Vector2f(370, 570), false);
    Student student2(1, sf::Vector2f(200, 500), studentTexture, sf::Vector2f(310, 625), false);
    Student student3(2, sf::Vector2f(150, 550), studentTexture, sf::Vector2f(260, 675), false);
    Student student4(3, sf::Vector2f(1670, 450), studentTexture, sf::Vector2f(1500, 570), true);
    Student student5(4, sf::Vector2f(1720, 500), studentTexture, sf::Vector2f(1550, 625), true);
    Student student6(5, sf::Vector2f(1770, 550), studentTexture, sf::Vector2f(1600, 675), true);

    // players
    Player leftPlayer(true, true, &student1, &student2, &student3);
    Player rightPlayer(false, true, &student4, &student5, &student6);

    // beers
    sf::Texture beerTexture;
    if (!beerTexture.loadFromMemory(piwo_png, piwo_png_len))
    {
        throw("Failed to load piwo.png");
    }
    sf::Texture crushedCanTexture;
    if (!crushedCanTexture.loadFromMemory(crushedcan_png, crushedcan_png_len))
    {
        throw("Failed to load crushedcan.png");
    }
    sf::Texture handTexture;
    if (!handTexture.loadFromMemory(hand_png, hand_png_len))
    {
        throw("Failed to load hand.png");
    }
    sf::Texture beerIconTexture;
    if (!beerIconTexture.loadFromMemory(beericon_png, beericon_png_len))
    {
        throw("Failed to load beericon.png");
    }
    Beer beer(sf::Vector2f(925, 650), beerTexture, 0.15, 0.15);
    Beer leftBeer(sf::Vector2f(400, 970), beerTexture, 0.1, 0.1);
    Beer rightBeer(sf::Vector2f(1440, 970), beerTexture, 0.1, 0.1);
    Beer crushedCan(sf::Vector2f(370, 570), crushedCanTexture, 0.15, 0.15);
    Beer leftIconBeer(sf::Vector2f(250, 100), beerIconTexture, -0.35, 0.35);
    Beer rightIconBeer(sf::Vector2f(1670, 100), beerIconTexture, 0.35, 0.35);
    Beer beerStudent1(sf::Vector2f(420, 665), beerTexture, 0.1, 0.1);
    Beer beerStudent2(sf::Vector2f(380, 715), beerTexture, 0.1, 0.1);
    Beer beerStudent3(sf::Vector2f(330, 765), beerTexture, 0.1, 0.1);
    Beer beerStudent4(sf::Vector2f(1440, 665), beerTexture, 0.1, 0.1);
    Beer beerStudent5(sf::Vector2f(1490, 715), beerTexture, 0.1, 0.1);
    Beer beerStudent6(sf::Vector2f(1540, 765), beerTexture, 0.1, 0.1);

    SliderBeer leftCrushedCan(sf::Vector2f(25, 970), crushedCanTexture, 0.15, 0.15);
    SliderBeer rightCrushedCan(sf::Vector2f(1065, 970), crushedCanTexture, 0.2, 0.2);
    
    // buttons
    Button againButton(sf::Vector2f(140, 70),
                       sf::Color::Transparent,
                       sf::Vector2f(890, 960),
                       sf::Color::White,
                       2,
                       "Again", 
                       openSans,
                       sf::Color::White,
                       sf::Vector2f(925, 980),
                       24);

    // texts
    Text leftBeerStatus("100%",
        openSans,
        sf::Color::Black,
        sf::Vector2f(140, 190),
        sf::Color::Black,
        0.5,
        28);
    Text rightBeerStatus("100%",
        openSans,
        sf::Color::Black,
        sf::Vector2f(1710, 190),
        sf::Color::Black,
        0.5,
        28);
    Text leftPlayerText("Left Player",
        openSans,
        sf::Color(212, 175, 55, 255),
        sf::Vector2f(525, 270),
        sf::Color::Black,
        5,
        160);
    Text rightPlayerText("Right Player",
        openSans,
        sf::Color(212, 175, 55, 255),
        sf::Vector2f(500, 270),
        sf::Color::Black,
        5,
        160);
    Text winText("Wins !!!",
        openSans,
        sf::Color(212, 175, 55, 255),
        sf::Vector2f(700, 450),
        sf::Color::Black,
        5,
        160);
    Text throwText("",
        openSans,
        sf::Color(212, 175, 55, 255),
        sf::Vector2f(0, 0),
        sf::Color::Black,
        5,
        160);

    // sliders
    Rect leftSlider(sf::Vector2f(800, 5), sf::Vector2f(40, 992), sf::Color::White, sf::Color::White, 2);
    Rect rightSlider(sf::Vector2f(800, 5), sf::Vector2f(1080, 992), sf::Color::White, sf::Color::White, 2);

    // flags
    bool isThrowingAnimation = false;
    bool isRaisingAnimation = false;
    bool isWinner = false;

    // game 
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseMoved)
            {
                if (againButton.isMouseOver(window))
                {
                    againButton.setBgColor(sf::Color::White);
                    againButton.setTextColor(sf::Color::Black);
                    window.setMouseCursor(handCursor);
                }
                else
                {
                    againButton.setBgColor(sf::Color::Black);
                    againButton.setTextColor(sf::Color::White);
                    window.setMouseCursor(arrowCursor);
                }
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (againButton.isMouseOver(window))
                    {
                        isWinner = false;
                        isThrowingAnimation = false;
                        isRaisingAnimation = false;

                        leftPlayer.setBeerStatus(100);
                        leftPlayer.setIsDrinking(false);
                        leftPlayer.setTurn(true);
                        leftPlayer.setThrowTurn(true);
                        leftPlayer.setActualStudent(leftPlayer.getStudents()[0]);
                        leftBeerStatus.setTextPosition(sf::Vector2f(140, 190));
                        leftBeerStatus.setString("100%");
                        leftBeer.setRotation(0);
                        leftBeer.setPosition(sf::Vector2f(400, 970));
                        leftCrushedCan.animationSliderReset(sf::Vector2f(25, 970));

                        rightPlayer.setBeerStatus(100);
                        rightPlayer.setIsDrinking(false);
                        rightPlayer.setTurn(false);
                        rightPlayer.setThrowTurn(true);
                        rightPlayer.setActualStudent(rightPlayer.getStudents()[0]);
                        rightBeerStatus.setTextPosition(sf::Vector2f(1710, 190));
                        rightBeerStatus.setString("100%");
                        rightBeer.setRotation(0);
                        rightBeer.setPosition(sf::Vector2f(1440, 970));
                        rightCrushedCan.animationSliderReset(sf::Vector2f(1065, 970));

                        beer.setRotation(0);
                        crushedCan.setPosition(leftPlayer.getActualStudent()->getCrushedCanPosition());
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed && !isThrowingAnimation && !isRaisingAnimation && !isWinner)
            {
                if (leftPlayer.getTurn() && event.key.code == sf::Keyboard::Space)
                {
                    float x = leftCrushedCan.getSprite().getPosition().x;
                    if (leftPlayer.getThrowTurn())
                    {
                        if (x > 380 && x < 410)
                        {
                            leftCrushedCan.animationSliderReset(sf::Vector2f(25, 970));
                            leftPlayer.setTurn(false);
                            rightPlayer.setTurn(true);
                            rightPlayer.setThrowTurn(false);
                            leftPlayer.setIsDrinking(true);
                            rightBeer.setRotation(90);
                            rightBeer.setPosition(sf::Vector2f(1490, 970));
                            rightCrushedCan.setTexture(handTexture);
                            rightCrushedCan.setScale(0.2, 0.2);
                            isThrowingAnimation = true;
                        }
                        else
                        {
                            leftCrushedCan.animationSliderReset(sf::Vector2f(25, 970));
                            leftPlayer.setTurn(false);
                            rightPlayer.setTurn(true);
                            rightCrushedCan.setTexture(crushedCanTexture);
                            rightCrushedCan.setScale(0.15, 0.15);
                            isThrowingAnimation = true;
                        }
                        leftPlayer.nextStudent();
                    }
                    else
                    {
                        if (x > 380 && x < 410)
                        {
                            leftCrushedCan.animationSliderReset(sf::Vector2f(25, 970));
                            leftPlayer.setThrowTurn(true);
                            rightPlayer.setIsDrinking(false);
                            leftBeer.setRotation(0);
                            leftBeer.setPosition(sf::Vector2f(400, 970));
                            isRaisingAnimation = true;
                        }
                    }
                    
                }

                if (rightPlayer.getTurn() && event.key.code == sf::Keyboard::Enter)
                {
                    float x = rightCrushedCan.getSprite().getPosition().x;
                    if (rightPlayer.getThrowTurn())
                    {
                        if (x > 1420 && x < 1450)
                        {
                            rightCrushedCan.animationSliderReset(sf::Vector2f(1065, 970));
                            rightPlayer.setTurn(false);
                            leftPlayer.setTurn(true);
                            leftPlayer.setThrowTurn(false);
                            rightPlayer.setIsDrinking(true);
                            leftBeer.setRotation(90);
                            leftBeer.setPosition(sf::Vector2f(450, 970));
                            leftCrushedCan.setTexture(handTexture);
                            leftCrushedCan.setScale(0.2, 0.2);
                            isThrowingAnimation = true;
                        }
                        else
                        {
                            rightCrushedCan.animationSliderReset(sf::Vector2f(1065, 970));
                            rightPlayer.setTurn(false);
                            leftPlayer.setTurn(true);
                            leftCrushedCan.setTexture(crushedCanTexture);
                            leftCrushedCan.setScale(0.15, 0.15);
                            isThrowingAnimation = true;
                        }
                        rightPlayer.nextStudent();
                    }
                    else
                    {
                        if (x > 1420 && x < 1450)
                        {
                            rightCrushedCan.animationSliderReset(sf::Vector2f(1065, 970));
                            rightPlayer.setThrowTurn(true);
                            leftPlayer.setIsDrinking(false);
                            rightBeer.setRotation(0);
                            rightBeer.setPosition(sf::Vector2f(1440, 970));
                            isRaisingAnimation = true;
                        }

                    }
                    
                }
            }
        }

        if (!isWinner)
        {
            if (isThrowingAnimation && rightPlayer.getTurn())
            {
                if (leftPlayer.getIsDrinking())
                {
                    isThrowingAnimation = leftPlayer.getActualStudent()->throwingAnimation(crushedCan, beer, throwText, true);
                }
                else
                {
                    isThrowingAnimation = leftPlayer.getActualStudent()->throwingAnimation(crushedCan, beer, throwText, false);
                    if (!isThrowingAnimation)
                    {
                        crushedCan.setPosition(rightPlayer.getActualStudent()->getCrushedCanPosition());
                    }
                }
            }
            else if (isThrowingAnimation && leftPlayer.getTurn())
            {
                if (rightPlayer.getIsDrinking())
                {
                    isThrowingAnimation = rightPlayer.getActualStudent()->throwingAnimation(crushedCan, beer, throwText, true);
                }
                else
                {
                    isThrowingAnimation = rightPlayer.getActualStudent()->throwingAnimation(crushedCan, beer, throwText, false);
                    if (!isThrowingAnimation)
                    {
                        crushedCan.setPosition(leftPlayer.getActualStudent()->getCrushedCanPosition());
                    }
                }
            }

            if (isRaisingAnimation && leftPlayer.getTurn())
            {
                isRaisingAnimation = leftPlayer.getActualStudent()->raisingAnimation(crushedCan, beer);
                if (!isRaisingAnimation)
                {
                    beerStudent4.setPosition(sf::Vector2f(1440, 665));
                    beerStudent4.setRotation(0);
                    beerStudent5.setPosition(sf::Vector2f(1490, 715));
                    beerStudent5.setRotation(0);
                    beerStudent6.setPosition(sf::Vector2f(1540, 765));
                    beerStudent6.setRotation(0);
                    crushedCan.setPosition(leftPlayer.getActualStudent()->getCrushedCanPosition());
                }
            }
            else if (isRaisingAnimation && rightPlayer.getTurn())
            {
                isRaisingAnimation = rightPlayer.getActualStudent()->raisingAnimation(crushedCan, beer);
                if (!isRaisingAnimation)
                {
                    beerStudent1.setPosition(sf::Vector2f(420, 665));
                    beerStudent1.setRotation(0);
                    beerStudent2.setPosition(sf::Vector2f(380, 715));
                    beerStudent2.setRotation(0);
                    beerStudent3.setPosition(sf::Vector2f(330, 765));
                    beerStudent3.setRotation(0);
                    crushedCan.setPosition(rightPlayer.getActualStudent()->getCrushedCanPosition());
                }
            }

            if (!isThrowingAnimation && !isRaisingAnimation)
            {
                if (leftPlayer.getTurn() && leftPlayer.getThrowTurn())
                {
                    leftCrushedCan.setTexture(crushedCanTexture);
                    leftCrushedCan.setScale(0.15, 0.15);
                    leftCrushedCan.animationSlider(25, 800, leftPlayer.getBeerStatus());
                }
                else if (leftPlayer.getTurn() && !leftPlayer.getThrowTurn())
                {
                    leftCrushedCan.setTexture(handTexture);
                    leftCrushedCan.setScale(0.2, 0.2);
                    leftCrushedCan.animationSlider(25, 800, leftPlayer.getBeerStatus());
                }
                else if (rightPlayer.getTurn() && rightPlayer.getThrowTurn())
                {
                    rightCrushedCan.setTexture(crushedCanTexture);
                    rightCrushedCan.setScale(0.15, 0.15);
                    rightCrushedCan.animationSlider(1065, 1835, rightPlayer.getBeerStatus());
                }
                else if (rightPlayer.getTurn() && !rightPlayer.getThrowTurn())
                {
                    rightCrushedCan.setTexture(handTexture);
                    rightCrushedCan.setScale(0.2, 0.2);
                    rightCrushedCan.animationSlider(1065, 1835, rightPlayer.getBeerStatus());
                }

                if (leftPlayer.getIsDrinking())
                {
                    double actualBeerStatus = leftPlayer.getBeerStatus();
                    double deltaBeerStatus = 0.15;
                    leftPlayer.setBeerStatus(actualBeerStatus - deltaBeerStatus);
                    if (leftPlayer.getBeerStatus() >= 10 && leftPlayer.getBeerStatus() < 100)
                    {
                        leftBeerStatus.setString(" " + std::to_string(leftPlayer.getBeerStatus()).substr(0, 2) + "%");
                    }
                    else
                    {
                        leftBeerStatus.setString("  " + std::to_string(leftPlayer.getBeerStatus()).substr(0, 1) + "%");
                    }
                    beerStudent1.setPosition(sf::Vector2f(360, 605));
                    beerStudent1.setRotation(-60);
                    beerStudent2.setPosition(sf::Vector2f(310, 655));
                    beerStudent2.setRotation(-60);
                    beerStudent3.setPosition(sf::Vector2f(260, 710));
                    beerStudent3.setRotation(-60);

                }
                else if (rightPlayer.getIsDrinking())
                {
                    double actualBeerStatus = rightPlayer.getBeerStatus();
                    double deltaBeerStatus = 0.15;
                    rightPlayer.setBeerStatus(actualBeerStatus - deltaBeerStatus);
                    rightBeerStatus.setString(std::to_string(rightPlayer.getBeerStatus()).substr(0, 2) + "%");
                    if (rightPlayer.getBeerStatus() >= 10 && rightPlayer.getBeerStatus() < 100)
                    {
                        rightBeerStatus.setString(" " + std::to_string(rightPlayer.getBeerStatus()).substr(0, 2) + "%");
                    }
                    else
                    {
                        rightBeerStatus.setString("  " + std::to_string(rightPlayer.getBeerStatus()).substr(0, 1) + "%");
                    }
                    beerStudent4.setPosition(sf::Vector2f(1535, 560));
                    beerStudent4.setRotation(60);
                    beerStudent5.setPosition(sf::Vector2f(1585, 615));
                    beerStudent5.setRotation(60);
                    beerStudent6.setPosition(sf::Vector2f(1635, 665));
                    beerStudent6.setRotation(60);
                }
            }
        }
        
        window.clear();
        window.draw(backgroundSprite);
        window.draw(beerStudent1);
        window.draw(student1);
        window.draw(beerStudent2);
        window.draw(student2);
        window.draw(beerStudent3);
        window.draw(student3);
        window.draw(beerStudent4);
        window.draw(student4);
        window.draw(beerStudent5);
        window.draw(student5);
        window.draw(beerStudent6);
        window.draw(student6);
        window.draw(againButton);
        window.draw(leftSlider);
        window.draw(rightSlider);
        window.draw(beer);
        window.draw(leftBeer);
        window.draw(rightBeer);
        window.draw(leftIconBeer);
        window.draw(rightIconBeer);
        window.draw(crushedCan); 
        if (leftPlayer.getTurn() && !isWinner)
        {
            window.draw(leftCrushedCan);
        }
        if (rightPlayer.getTurn() && !isWinner)
        {
            window.draw(rightCrushedCan);
        }
        if (leftPlayer.getBeerStatus() <= 0)
        {
            leftBeerStatus.setTextPosition(sf::Vector2f(130, 190));
            leftBeerStatus.setString("Empty");
            isWinner = true;
            beerStudent1.setPosition(sf::Vector2f(420, 665));
            beerStudent1.setRotation(0);
            beerStudent2.setPosition(sf::Vector2f(380, 715));
            beerStudent2.setRotation(0);
            beerStudent3.setPosition(sf::Vector2f(330, 765));
            beerStudent3.setRotation(0);
            window.draw(leftPlayerText);
            window.draw(winText);
        }
        else if (rightPlayer.getBeerStatus() <= 0)
        {
            rightBeerStatus.setTextPosition(sf::Vector2f(1700, 190));
            rightBeerStatus.setString("Empty");
            isWinner = true;
            beerStudent4.setPosition(sf::Vector2f(1440, 665));
            beerStudent4.setRotation(0);
            beerStudent5.setPosition(sf::Vector2f(1490, 715));
            beerStudent5.setRotation(0);
            beerStudent6.setPosition(sf::Vector2f(1540, 765));
            beerStudent6.setRotation(0);
            window.draw(rightPlayerText);
            window.draw(winText);
        }
        if (isThrowingAnimation)
        {
            window.draw(throwText);
        }
        window.draw(leftBeerStatus);
        window.draw(rightBeerStatus);
        window.display();
    }

    return 0;
}