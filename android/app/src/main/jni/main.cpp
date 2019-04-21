#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main(int argc, char* argv[])
{
    sf::VideoMode videoMode(sf::VideoMode::getDesktopMode());

    sf::View view(sf::Vector2f(), sf::Vector2f(240.0, 240.0 / videoMode.width * videoMode.height));

    sf::RenderWindow window(videoMode, "");

    sf::Color background = sf::Color::Black;

    sf::Texture texture;
    if(!texture.loadFromFile("logo.png"))
        return EXIT_FAILURE;

    sf::Sprite image(texture);
    image.setPosition(0.0, 0.0);
    image.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);

    bool isActive = true;
    while (window.isOpen()) {

        sf::Event event;
        while (isActive ? window.pollEvent(event) : window.waitEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseLeft:
                isActive = false;
                break;
            case sf::Event::MouseEntered:
                isActive = true;
                window.create(videoMode, "");
                window.setView(view);
                window.setFramerateLimit(60);
                break;
            }
        }

        if (isActive) {
            window.clear(background);
            window.draw(image);
            window.display();
        }
    }
}


