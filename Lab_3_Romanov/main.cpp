#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "");

    int n = 10;
    int cellSize = 50;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);


        float center_x = n / 2;
        float center_y = n / 2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
                cell.setPosition(i * cellSize, j * cellSize);

                float delta_y = j - 1;
                
                if (std::abs(center_x - i) <= delta_y && j <= center_y)
                    cell.setFillColor(sf::Color::Green);

                delta_y = n - j - 1;
                if(std::abs(center_x - i) <= delta_y && j >= center_y)
                    cell.setFillColor(sf::Color::Green);



                cell.setOutlineThickness(1);
                cell.setOutlineColor(sf::Color::Black);

                window.draw(cell);
            }
        }

        window.display();
    }

    return 0;
}
