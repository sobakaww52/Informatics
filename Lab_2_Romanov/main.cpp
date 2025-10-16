#include <SFML/Graphics.hpp>
#include <functional> 
#include <cmath> 

void drawGraph(sf::RenderWindow& window, std::function<float(float)> func, float xMin, float xMax, float scaleX, float scaleY, sf::Color color) {
    sf::VertexArray graph(sf::LinesStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x); 
        
        float screenX = 400 + x * scaleX;
        float screenY = 300 - y * scaleY;

       
        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
}


float f1(float x)
{
    return (-0.1 * x * x) + 4;
}
float f2(float x)
{
    return (abs(x));
}


int main() {
    
    setlocale(LC_ALL, "rus");
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML_GRAPH");

    sf::CircleShape userPoint(5); // Ðàäèóñ 5 ïèêñåëåé
    userPoint.setFillColor(sf::Color::Red);
    bool userPointExists = false; // Ïåðåìåííàÿ äëÿ ïðîâåðêè ñóùåñòâîâàíèÿ ïîëüçîâàòåëüñêîé òî÷êè

    sf::Font font;
    if (!font.loadFromFile("timesnewromanpsmt.ttf")) {
        return -1;
    }

    sf::Text coordinatesText;
    coordinatesText.setFont(font);
    coordinatesText.setPosition(10, 10);
    coordinatesText.setCharacterSize(20);
    coordinatesText.setFillColor(sf::Color::White);



    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(50, 300); // Íà÷àëî îñè X
    xAxis[0].color = sf::Color::White; // Öâåò îñè
    xAxis[1].position = sf::Vector2f(750, 300); // Êîíåö îñè X
    xAxis[1].color = sf::Color::White;

    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(400, 50); // Íà÷àëî îñè Y
    yAxis[0].color = sf::Color::White; // Öâåò îñè
    yAxis[1].position = sf::Vector2f(400, 550); // Êîíåö îñè Y
    yAxis[1].color = sf::Color::White;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();


            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Ïîëó÷åíèå ïîçèöèè êëèêà
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);


                    float mathX = (mousePos.x - 400) / 15.0f; 
                    float mathY = -(mousePos.y - 300) / 15.0f; 

                   
                    userPoint.setPosition(mousePos.x - userPoint.getRadius(), mousePos.y - userPoint.getRadius());
                    userPointExists = true; 


                    std::string pos;
                    bool module = mathY > std::abs(mathX);
                    bool parabola = mathY > (-0.1 * mathX * mathX) + 4;

                    if (mathY == std::abs(mathX) || mathY == ((-0.1 * mathX * mathX) + 4)) {
                        pos = "Granica";
                    }
                    else if (module && parabola) {
                        pos = "2";
                    }
                    else if (!parabola && module) {
                        pos = "1";
                    }
                    else if (parabola && !module && mathX < 0) {
                        pos = "4";
                    }
                    else if (!module && !parabola) {
                        pos = "3";
                    }
                    else {
                        pos = "5";
                    }



                    coordinatesText.setString("Coordinates: (" + std::to_string(mathX) + ", " + std::to_string(mathY) + ")" + "Area:" + pos);
                }
            }
        }



        window.clear();



        window.draw(xAxis);
        window.draw(yAxis);




        drawGraph(window, [](float x) { return (-0.1 * x * x) + 4;}, -10, 10, 15, 15, sf::Color::Blue);

        drawGraph(window, [](float x) { return abs(x);}, -10, 10, 15, 15, sf::Color::Red);

        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
        }

        window.display();
    }

    return 0;

}
