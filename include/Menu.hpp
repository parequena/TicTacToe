/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#ifndef MENU_H_
#define MENU_H_

namespace sf { class RenderWindow; class Font; class Text; }

struct MenuSelect
{
    // Bool that controlles if we want to play, or not.
    bool m_play = true;

    // Checks how many players are going to play.
    std::uint8_t m_nPlayers = 1;

    // Check AI level.
    std::uint8_t m_AILevel = 0;

    // Returns max posible players.
    static std::uint8_t maxPlayers()  { return 2; }

    // Returns max AI level.
    static std::uint8_t maxAILevel()  { return 0; }

    // Ctor
    MenuSelect()  { m_play = true; m_nPlayers = 1; m_AILevel = 0; }
};

class Menu
{
    // Window.
    sf::RenderWindow* m_window;

    // Font.
    sf::Font* m_font;

    // Title
    sf::Text* m_title;

    // Text.
    sf::Text* m_texts[5];

    // Menu Selection.
    MenuSelect* m_selection;

    // Position
    std::uint8_t m_position;

    // Draw
    void draw() const ;

public:
    // Ctor.
    Menu(sf::RenderWindow* window);

    // Dtor.
    ~Menu() noexcept;

    // Select
    MenuSelect* select();
};

#endif
