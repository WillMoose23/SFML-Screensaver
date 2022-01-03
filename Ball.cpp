//
// Created by Moose on 3/7/2021.
//

#include "Ball.h"

using namespace std;
using namespace sf;

Ball::Ball(){}

Ball::~Ball(){}

void Ball::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(ball);
}

void Ball::bounce()
{
    const int window_width = 2000;
    const int window_height = 1000;
    const float ball_radius = 50.f;
    const int bpp = 32;

    sf::RenderWindow window(sf::VideoMode(window_width, window_height, bpp), "Bouncing ball");
    window.setVerticalSyncEnabled(true);

    sf::Vector2f direction(random(17,21), random(17,21));
    const float velocity = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    sf::CircleShape ball(ball_radius - 4);
    ball.setOutlineThickness(10);
    ball.setOutlineColor(sf::Color::Black);
    ball.setFillColor(sf::Color::Green);
    ball.setOrigin(ball.getRadius(), ball.getRadius());
    ball.setPosition(window_width / 2, window_height / 2);

    sf::Clock clock;
    sf::Time elapsed = clock.restart();
    const sf::Time update_ms = sf::seconds(1.f / 30.f);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
                window.close();
                break;
            }
        }

        elapsed += clock.restart();
        while (elapsed >= update_ms) {
            const auto pos = ball.getPosition();
            const auto delta = update_ms.asSeconds() * velocity;
            sf::Vector2f new_pos(pos.x + direction.x * delta, pos.y + direction.y * delta);

            if (new_pos.x - ball_radius < 0)
            {
                direction.x = abs(direction.x);
                new_pos.x = 0 + ball_radius;
            }
            else if (new_pos.x + ball_radius >= window_width)
            {
                direction.x = -abs(direction.x);
                new_pos.x = window_width - ball_radius;
            }
            else if (new_pos.y - ball_radius < 0)
            {
                direction.y *= -1;
                new_pos.y = 0 + ball_radius;
            }
            else if (new_pos.y + ball_radius >= window_height)
            {
                direction.y *= -1;
                new_pos.y = window_height - ball_radius;
            }
            ball.setPosition(new_pos);

            elapsed -= update_ms;
        }

        window.clear(sf::Color(130, 10, 120));
        window.draw(ball);
        window.display();
    }
}



int random(int min, int max)
{
    std::random_device device;
    std::mt19937 random_engine(device());
    std::uniform_int_distribution<int> dt(min, max);

    int a = dt(random_engine);

    return a;
}

