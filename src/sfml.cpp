#include "sfml.h"
#include <cmath>
#include <numbers>

Circle::Circle(sf::RenderWindow &window, float radius, sf::Color const &color, int startx, int starty)
    : m_window(window)
      , m_circle(radius) {
    this->m_circle.setFillColor(color);
    this->m_circle.setPosition(startx,starty);

}

auto Circle::draw() -> void {
    auto Pos = this->m_circle.getPosition();
    Pos.x++;
    Pos.y = 100 * std::sin(std::numbers::pi * Pos.x / 180);
    this->m_circle.setPosition(Pos);
    this->m_window.draw(this->m_circle);
}
