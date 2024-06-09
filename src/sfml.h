#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class Circle  {
public:
    explicit Circle( sf::RenderWindow& window, float radius, sf::Color const& color,int startx,int starty);
    auto draw()->void;
private:
    sf::CircleShape m_circle;
    sf::RenderWindow& m_window;

};