#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include <numbers>
#include <filesystem>
#include <format>
#include <vector>
int main() {
    sf::RenderWindow zxc(sf::VideoMode(1280, 720), "goida");
    zxc.setTitle("Unlimited Potential");
    zxc.setFramerateLimit(60);
    sf::CircleShape shape(30.f);
    shape.setFillColor(sf::Color(0, 0, 100));
    sf::Text Score;
    Score.setString("Score");
    Score.setCharacterSize(80);
    Score.setFillColor(sf::Color::Blue);
    auto fontpath = std::filesystem::current_path() / "resources" / "Dotcom.ttf";
    sf::Font font;
    font.loadFromFile("resources/Dotcom.ttf");
    Score.setFont(font);
    Score.setPosition(1000, 50);
    int i = 0;
    int score=0;
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
                    auto mousePos = sf::Mouse::getPosition(zxc);
                auto figpos = shape.getPosition();
                int OX=std::pow((mousePos.x-figpos.x-shape.getRadius()),2);
                int OY=std::pow((mousePos.y-figpos.y-shape.getRadius()),2);
                if (OX+OY<=pow(shape.getRadius(),2)) {
                    score++;
                }
                    //std::cout << std::format("Pos: [{}, {}]",mousePos.x, mousePos.y) << std::endl;
                //std::cout<<std::format("Pos: [{}, {}]",figpos.x+shape.getRadius(), figpos.y+shape.getRadius()) << std::endl;
                break;
            }
        }
        Score.setString("Score:"+std::to_string(score));
        zxc.clear(sf::Color::Black);
        zxc.draw(Score);
        shape.setPosition(++i,90*std::sin(i*std::numbers::pi/180) );
        zxc.draw(shape);
        zxc.display();
    }
    return 0;
}
