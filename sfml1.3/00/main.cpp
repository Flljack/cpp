#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML1.3");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({600, 400});
    shape1.setPosition({100, 200});
    shape1.setFillColor(sf::Color(135, 74, 4));
    window.draw(shape1);

    sf::ConvexShape trapeze;
    trapeze.setFillColor(sf::Color(200, 32, 32));
    trapeze.setPosition(100, 100);
    trapeze.setPointCount(4);
    trapeze.setPoint(0, {+100, 0});
    trapeze.setPoint(1, {+500, 0});
    trapeze.setPoint(2, {+680, 160});
    trapeze.setPoint(3, {-80, 160});
    window.draw(trapeze);

    sf::RectangleShape door;
    door.setSize({100, 200});
    door.setPosition({150, 400});
    door.setFillColor(sf::Color(77, 77, 77));
    window.draw(door);

    sf::CircleShape shape2(20);
    shape2.setPosition({480, 15});
    shape2.setFillColor(sf::Color(185, 185, 185));
    window.draw(shape2);

    sf::CircleShape shape3(15);
    shape3.setPosition({470, 20});
    shape3.setFillColor(sf::Color(185, 185, 185));
    window.draw(shape3);

    sf::CircleShape shape4(20);
    shape4.setPosition({460, 30});
    shape4.setFillColor(sf::Color(185, 185, 185));
    window.draw(shape4);

    sf::CircleShape shape5(25);
    shape5.setPosition({445, 40});
    shape5.setFillColor(sf::Color(185, 185, 185));
    window.draw(shape5);

    sf::RectangleShape trumpet1;
    trumpet1.setSize({100, 40});
    trumpet1.setPosition({420, 80});
    trumpet1.setFillColor(sf::Color(77, 77, 77));
    window.draw(trumpet1);

    sf::RectangleShape trumpet2;
    trumpet2.setSize({50, 100});
    trumpet2.setPosition({445, 80});
    trumpet2.setFillColor(sf::Color(77, 77, 77));
    window.draw(trumpet2);

    window.display();

    sf::sleep(sf::seconds(5));
}