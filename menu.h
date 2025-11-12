#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

class Menu {
public:
    bool showMenu(sf::RenderWindow& window) {
        // === Cargar fuente ===
        sf::Font font;
        if (!font.openFromFile("assets/ARIAL.ttf")) { // ← En SFML 3 se usa openFromFile()
            std::cout << "❌ No se pudo cargar la fuente 'assets/ARIAL.ttf'\n";
            return false;
        }

        // === Cargar imagen de fondo ===
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("assets/menu.png")) { // ← loadFromFile() en SFML 2.x
            std::cout << "⚠️ No se pudo cargar 'assets/menu.png'\n";
        }
        sf::Sprite background(backgroundTexture);

        // === Crear botones ===
        sf::RectangleShape btnStart({ 250.f, 60.f });
        sf::RectangleShape btnRules({ 250.f, 60.f });
        sf::RectangleShape btnExit({ 250.f, 60.f });

        btnStart.setFillColor(sf::Color(70, 130, 180));
        btnRules.setFillColor(sf::Color(70, 130, 180));
        btnExit.setFillColor(sf::Color(178, 34, 34));

        // === Calcular posiciones ===
        auto windowSize = window.getSize();  // devuelve sf::Vector2u
        float centerX = static_cast<float>(windowSize.x) / 2.f - 125.f;

        btnStart.setPosition({ centerX, 300.f });
        btnRules.setPosition({ centerX, 400.f });
        btnExit.setPosition({ centerX, 500.f });

        // === Crear textos ===
		sf::Font font2("ARIAL.ttf");

		sf::Text txtStart(font2);
		txtStart.setString("salir");
        sf::Text txtRules(font2);
        txtRules.setString("reglas de juego");
        sf::Text txtExit(font2);
        txtExit.setString("iniciar partida");

        txtStart.setPosition({ centerX + 35.f, 310.f });
        txtRules.setPosition({ centerX + 40.f, 410.f });
        txtExit.setPosition({ centerX + 85.f, 510.f });

        // === Loop principal del menú ===
        while (window.isOpen()) {
            while (const std::optional<sf::Event> event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                    return false;
                }

                if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                    if (mousePressed->button == sf::Mouse::Button::Left) {
                        sf::Vector2f mousePos(
                            static_cast<float>(mousePressed->position.x),
                            static_cast<float>(mousePressed->position.y)
                        );

                        if (btnStart.getGlobalBounds().contains(mousePos)) {
                            std::cout << "✅ Iniciando partida...\n";
                            return true;
                        }
                        if (btnRules.getGlobalBounds().contains(mousePos)) {
                            std::cout << "📜 Reglas del juego:\n";
                            std::cout << "1. Solo las piezas en casillas oscuras se mueven.\n";
                            std::cout << "2. Se captura saltando sobre la pieza rival.\n";
                            std::cout << "3. Una dama se crea al llegar al lado opuesto.\n";
                            std::cout << "4. Gana quien capture todas las piezas rivales.\n";
                        }
                        if (btnExit.getGlobalBounds().contains(mousePos)) {
                            std::cout << "👋 Saliendo del juego...\n";
                            window.close();
                            return false;
                        }
                    }
                }
            }

            // === Dibujar ===
            window.clear(sf::Color::Black);
            window.draw(background);
            window.draw(btnStart);
            window.draw(btnRules);
            window.draw(btnExit);
            window.draw(txtStart);
            window.draw(txtRules);
            window.draw(txtExit);
            window.display();
        }

        return false;
    }
};
