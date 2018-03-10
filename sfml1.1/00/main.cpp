#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({160, 400}), "Rectangles and circle");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({140, 380});
    shape1.setPosition({10, 10});
    shape1.setFillColor(sf::Color(67, 67, 67));
    window.draw(shape1);

    sf::CircleShape shape2(60);
    shape2.setPosition({20, 15});
    shape2.setFillColor(sf::Color(0, 255, 0));
    window.draw(shape2);

    sf::CircleShape shape3(60);
    shape3.setPosition({20, 140});
    shape3.setFillColor(sf::Color(255, 255, 0));
    window.draw(shape3);

    sf::CircleShape shape4(60);
    shape4.setPosition({20, 265});
    shape4.setFillColor(sf::Color(255, 0, 0));
    window.draw(shape4);

    window.display();

    sf::sleep(sf::seconds(5));
}