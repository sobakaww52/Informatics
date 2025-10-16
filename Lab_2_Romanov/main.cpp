#include <SFML/Graphics.hpp>
#include <functional> 
#include <cmath> 

// ������� ��� ��������� �������
void drawGraph(sf::RenderWindow& window, std::function<float(float)> func, float xMin, float xMax, float scaleX, float scaleY, sf::Color color) {
    sf::VertexArray graph(sf::LinesStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x); // ���������� ������ �� �������

        // �������������� ��������� � ��������
        float screenX = 400 + x * scaleX;
        float screenY = 300 - y * scaleY;

        // ���������� ����� � ������ ������
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
    // �������� ����
    setlocale(LC_ALL, "rus");
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML_GRAPH");

    // ���������� ��� �������� ���������������� �����
    sf::CircleShape userPoint(5); // ������ 5 ��������
    userPoint.setFillColor(sf::Color::Red);
    bool userPointExists = false; // ���������� ��� �������� ������������� ���������������� �����

    // 1 _ �������� ������ (�������� ���)
    sf::Font font;
    if (!font.loadFromFile("timesnewromanpsmt.ttf")) {
        return -1;
    }

    // 2 _ ����� ��� ����������� ��������� ����� (�������� ���)
    // ������ ������ 20, ��������� ������ (10,10), ���� �����. ����� ������� � ���������� coordinatesText
    sf::Text coordinatesText;
    coordinatesText.setFont(font);
    coordinatesText.setPosition(10, 10);
    coordinatesText.setCharacterSize(20);
    coordinatesText.setFillColor(sf::Color::White);


    // ��� X � Y
    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(50, 300); // ������ ��� X
    xAxis[0].color = sf::Color::White; // ���� ���
    xAxis[1].position = sf::Vector2f(750, 300); // ����� ��� X
    xAxis[1].color = sf::Color::White;

    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(400, 50); // ������ ��� Y
    yAxis[0].color = sf::Color::White; // ���� ���
    yAxis[1].position = sf::Vector2f(400, 550); // ����� ��� Y
    yAxis[1].color = sf::Color::White;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // �������� ����� �����
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // ��������� ������� �����
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    // �������������� �������� ��������� � "��������������"
                    float mathX = (mousePos.x - 400) / 15.0f; // ������� 30 �� X
                    float mathY = -(mousePos.y - 300) / 15.0f; // ������� 100 �� Y

                    // ��������� ����� ���������������� �����
                    userPoint.setPosition(mousePos.x - userPoint.getRadius(), mousePos.y - userPoint.getRadius());
                    userPointExists = true; // ��������, ��� ����� ����������

                    // 3 _ �������� ������ �������� ����� �� ���������� mathX � mathY !
                    std::string pos;
                    bool module = mathY > std::abs(mathX);
                    bool parabola = mathY > (-0.1 * mathX * mathX) + 4;

                    if (mathY == std::abs(mathX) || mathY == 2.5) {
                        pos = "�������";
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


                    // ���������� ������ � ������������ ����� 
                    coordinatesText.setString("Coordinates: (" + std::to_string(mathX) + ", " + std::to_string(mathY) + ")" + "Area:" + pos);
                }
            }
        }


        // 4 _ ������� ������ (�������� ���)
        window.clear();


        // ��������� ����
        window.draw(xAxis);
        window.draw(yAxis);



        // 5 _  ��������� ������� y1 = 0.5*x (�������� �� ��� ������)
        drawGraph(window, [](float x) { return (-0.1 * x * x) + 4;}, -10, 10, 15, 15, sf::Color::Blue);

        // 5 _   ��������� ������� y2 = x * x - 5 (�������� �� ��� ������)
        drawGraph(window, [](float x) { return abs(x);}, -10, 10, 15, 15, sf::Color::Red);

        // ��������� ���������������� �����, ���� ��� ����������
        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
        }

        // ����������� ������ �����
        window.display();
    }

    return 0;
}