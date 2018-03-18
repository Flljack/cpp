#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

// структура глаза
// самого глаза shape
// глазного яблока shape
// позиция глазного яблока Vector2f
// поворот глаза int
struct EyeLeft
{
    sf::ConvexShape eyeLeft;
    sf::ConvexShape appleLeft;
    sf::Vector2f position;
    float rotation = 0;
};

struct EyeRight
{
    sf::ConvexShape eyeRight;
    sf::ConvexShape appleRight;
    sf::Vector2f position;
    float rotation = 0;
};

// из 04 задания
sf::Vector2f toEuclidean(float radiusX, float radiusY, float angle)
{
    return {
        radiusX * cos(angle),
        radiusY * sin(angle)};
}

// обновляем позиция левого глаза
void updateEyeLeftElements(EyeLeft &EyeLeft)
{
    EyeLeft.eyeLeft.setPosition(EyeLeft.position);
    const sf::Vector2f appleLeft0ffset = toEuclidean(25, 55, EyeLeft.rotation);
    EyeLeft.appleLeft.setPosition(EyeLeft.position + appleLeft0ffset);
}

// обновляем позиция правого глаза
void updateEyeRightElements(EyeRight &EyeRight)
{
    EyeRight.eyeRight.setPosition(EyeRight.position);
    const sf::Vector2f appleRight0ffset = toEuclidean(25, 55, EyeRight.rotation);
    EyeRight.appleRight.setPosition(EyeRight.position + appleRight0ffset);
}

// инициализируем глаза
void initEyes(EyeLeft &EyeLeft, EyeRight &EyeRight)
{
    const sf::Vector2f eyeRadius = {40.f, 80.f};
    const sf::Vector2f appleRadius = {10.f, 20.f};
    const int pointCount = 100;
    EyeLeft.position = {350, 300};
    EyeRight.position = {450, 300};

    //  рисуем левый глаз
    EyeLeft.eyeLeft.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    EyeLeft.eyeLeft.setPointCount(pointCount);
    for (int pointI = 0; pointI < pointCount; ++pointI)
    {
        float angle = float(2 * M_PI * pointI) / float(pointCount);
        sf::Vector2f point = {
            eyeRadius.x * std::sin(angle),
            eyeRadius.y * std::cos(angle)};
        EyeLeft.eyeLeft.setPoint(pointI, point);
    }

    EyeLeft.appleLeft.setFillColor(sf::Color(0, 0, 0));
    EyeLeft.appleLeft.setPointCount(pointCount);
    for (int pointI = 0; pointI < pointCount; ++pointI)
    {
        float angle = float(2 * M_PI * pointI) / float(pointCount);
        sf::Vector2f point = {
            appleRadius.x * std::sin(angle),
            appleRadius.y * std::cos(angle)};
        EyeLeft.appleLeft.setPoint(pointI, point);
    }
    //  рисуем правый глаз
    EyeRight.eyeRight.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    EyeRight.eyeRight.setPointCount(pointCount);
    for (int pointI = 0; pointI < pointCount; ++pointI)
    {
        float angle = float(2 * M_PI * pointI) / float(pointCount);
        sf::Vector2f point = {
            eyeRadius.x * std::sin(angle),
            eyeRadius.y * std::cos(angle)};
        EyeRight.eyeRight.setPoint(pointI, point);
    }

    EyeRight.appleRight.setFillColor(sf::Color(0, 0, 0));
    EyeRight.appleRight.setPointCount(pointCount);
    for (int pointI = 0; pointI < pointCount; ++pointI)
    {
        float angle = float(2 * M_PI * pointI) / float(pointCount);
        sf::Vector2f point = {
            appleRadius.x * std::sin(angle),
            appleRadius.y * std::cos(angle)};
        EyeRight.appleRight.setPoint(pointI, point);
    }

    updateEyeLeftElements(EyeLeft);
    updateEyeRightElements(EyeRight);
}

// из 04 задания
void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << " mouse y=" << event.y << std::endl;
    mousePosition = {float(event.x), float(event.y)};
}

// из 04 задания
void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

// обновляем кадр и вызываем функции обновления глаз
void update(const sf::Vector2f &mousePosition, EyeLeft &EyeLeft, EyeRight &EyeRight)
{
    const sf::Vector2f delta1 = mousePosition - EyeLeft.position;
    EyeLeft.rotation = atan2(delta1.y, delta1.x);
    updateEyeLeftElements(EyeLeft);

    const sf::Vector2f delta2 = mousePosition - EyeRight.position;
    EyeRight.rotation = atan2(delta2.y, delta2.x);
    updateEyeRightElements(EyeRight);
}

// перерисовываем кадр
void redrawFrame(sf::RenderWindow &window, EyeLeft &EyeLeft, EyeRight &EyeRight)
{
    window.clear();
    window.draw(EyeLeft.eyeLeft);
    window.draw(EyeLeft.appleLeft);
    window.draw(EyeRight.eyeRight);
    window.draw(EyeRight.appleRight);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Eyes follow the cursor", sf::Style::Default, settings);

    EyeLeft EyeLeft;
    EyeRight EyeRight;
    initEyes(EyeLeft, EyeRight);
    sf::Vector2f mousePosition;

    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, EyeLeft, EyeRight);
        redrawFrame(window, EyeLeft, EyeRight);
    }
}