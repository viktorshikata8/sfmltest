#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <filesystem>
#include <format>
#include "sfml.h"
int main() {
    sf::RenderWindow zxc(sf::VideoMode(1280, 720), "goida");
    zxc.setTitle("Unlimited Potential");
    zxc.setFramerateLimit(60);
    Circle u(zxc,50,sf::Color::Blue,400,300);
    Circle z(zxc,40,sf::Color::Red,200,150);
    sf::Text Score;
    Score.setString("Score");
    Score.setCharacterSize(30);
    Score.setFillColor(sf::Color::Blue);
    auto fontpath=std::filesystem::current_path() /"resources"/"Dotcom.ttf";
    sf::Font font;
    font.loadFromFile("resources/Dotcom.ttf");
    Score.setFont(font);
    Score.setPosition(1200,50);
    while (zxc.isOpen()) {
        sf::Event event1{};
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
                    //auto mousePos=sf::Mouse::getPosition();
                //std::cout << std::format("Pos: [{}, {}]", mousePos.x, mousePos.y) << std::endl;
                break;
            default:
            break;}
        }

        Score.setString(std::to_string(5));
        zxc.clear(sf::Color::Black);
        zxc.draw(Score);
        u.draw();
        z.draw();
        zxc.display();

    }
    return 0;
}
