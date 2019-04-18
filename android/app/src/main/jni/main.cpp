#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main(int argc, char *argv[])
{
    sf::VideoMode videoMode(sf::VideoMode::getDesktopMode());

    sf::RenderWindow window(videoMode, "Long Long Tail!");
    window.setFramerateLimit(60);

    sf::View view(sf::Vector2f(), sf::Vector2f(240, 320));
    window.setView(view);

    sf::Color background = sf::Color::Black;

    sf::Texture texture;
    if(!texture.loadFromFile("logo.png"))
        return EXIT_FAILURE;

    sf::Sprite image(texture);
    image.setPosition(0.0, 0.0);
    image.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(background);
        window.draw(image);
        window.display();
    }
}


