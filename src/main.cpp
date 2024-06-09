#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include <numbers>
#include <filesystem>
#include <format>
int main() {
    sf::RenderWindow zxc(sf::VideoMode(1280, 720), "goida");
    zxc.setTitle("Unlimited Potential");
    zxc.setFramerateLimit(60);
    sf::CircleShape shape(30.f);
    shape.setFillColor(sf::Color(0, 0, 100));
    sf::Text Score;
    Score.setString("Score");
    Score.setCharacterSize(30);
    Score.setFillColor(sf::Color::Blue);
    auto fontpath=std::filesystem::current_path() /"resources"/"Dotcom.ttf";
    sf::Font font;
    font.loadFromFile("resources/Dotcom.ttf");
    Score.setFont(font);
    Score.setPosition(1200,50);
    int i=0;

    while (zxc.isOpen()) {
        sf::Event event1;
        while (zxc.pollEvent(event1)) {
            switch (event1.type) {
                case sf::Event::Closed:
                    zxc.close();
                    break;
                case::sf::Event::TextEntered:
                    if (event1.type == sf::Event::TextEntered) {
                        if (event1.text.unicode < 128) {
                            std::cout << static_cast<char>(event1.text.unicode) << std::endl;
                        }
                    }
                    break;
                case::sf::Event::KeyPressed:
                    zxc.setKeyRepeatEnabled(false);
                    break;
                case::sf::Event::KeyReleased:
                    std::cout << "Stop it please) \n";
                    break;
                case::sf::Event::MouseButtonPressed:
                    auto mousePos=sf::Mouse::getPosition();
                    auto figpos=shape.getPosition();
                    if(mousePos.x>=figpos.x and mousePos.y==figpos.x )
                //std::cout << std::format("Pos: [{}, {}]", mousePos.x, mousePos.y) << std::endl;
                break;
            }
        }

        Score.setString(std::to_string(i));
        zxc.clear(sf::Color::Black);
        zxc.draw(Score);
        shape.setPosition(++i, 90 * sin(i * std::numbers::pi/ 180));
        zxc.draw(shape);
        zxc.display();

    }
    return 0;
}
