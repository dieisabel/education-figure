#include <SFML/Graphics.hpp>

#include "./figure.h"

using namespace sf;


int main()
{
    RenderWindow window(VideoMode(500, 500), "Lab6");
    window.setFramerateLimit(60);

    Figure figure({250, 250}, 300, 300);

    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;

            case Event::KeyPressed:
                switch (event.key.code)
                {
                case Keyboard::Up:
                    figure.move(0, -20);
                    break;

                case Keyboard::Down:
                    figure.move(0, 20);
                    break;

                case Keyboard::Left:
                    figure.move(-20, 0);
                    break;

                case Keyboard::Right:
                    figure.move(20, 0);
                    break;
                case Keyboard::Num1:
                    figure.scale(50);
                    break;

                case Keyboard::Num2:
                    figure.scale(-50);
                    break;

                case Keyboard::Q:
                    figure.rotate(-15);
                    break;

                case Keyboard::E:
                    figure.rotate(15);
                    break;
                }
                break;
            }
        }

        window.clear();
        figure.draw(window);
        window.display();
    }

    return 0;
}
