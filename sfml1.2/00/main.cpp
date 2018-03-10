#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({400, 400}), "Rectangles and circle");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({10, 60});
    shape1.setPosition({10, 10});
    shape1.setFillColor(sf::Color(67, 67, 67));
    window.draw(shape1);

    sf::CircleShape shape2(19);
    shape2.setPosition({9, 2});
    shape2.setFillColor(sf::Color(67, 67, 67));
    window.draw(shape2);

    sf::RectangleShape shape3;
    shape3.setSize({10, 70});
    shape3.setRotation(-30);
    shape3.setPosition({10, 10});
    shape3.setFillColor(sf::Color(67, 67, 67));
    window.draw(shape3);

    sf::CircleShape shape4(10);
    shape4.setPosition({18, 12});
    shape4.setFillColor(sf::Color(0, 0, 0));
    window.draw(shape4);

    sf::CircleShape shape5(30);
    shape5.setPosition({66, 10});
    shape5.setFillColor(sf::Color(67, 67, 67));
    window.draw(shape5);

    sf::CircleShape shape6(15);
    shape6.setPosition({80, 25});
    shape6.setFillColor(sf::Color(0, 0, 0));
    window.draw(shape6);

    sf::RectangleShape shape7;
    shape7.setSize({10, 60});
    shape7.setPosition({80, 10});
    shape7.setFillColor(sf::Color(67, 67, 67));
    window.draw(shape7);

    sf::RectangleShape shape8;
    shape8.setSize({20, 60});
    shape8.setPosition({60, 10});
    shape8.setFillColor(sf::Color(0, 0, 0));
    window.draw(shape8);

    sf::RectangleShape shape9;
    shape9.setSize({10, 60});
    shape9.setRotation(15);
    shape9.setPosition({170, 10});
    shape9.setFillColor(sf::Color(67, 67, 67));
    window.draw(shape9);

    sf::RectangleShape shape10;
    shape10.setSize({10, 60});
    shape10.setRotation(-15);
    shape10.setPosition({170, 10});
    shape10.setFillColor(sf::Color(67, 67, 67));
    window.draw(shape10);

    sf::RectangleShape shape11;
    shape11.setSize({10, 30});
    shape11.setRotation(-90);
    shape11.setPosition({160, 60});
    shape11.setFillColor(sf::Color(67, 67, 67));
    window.draw(shape11);

    window.display();

    sf::sleep(sf::seconds(5));
}