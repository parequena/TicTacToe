#ifndef __GAME_H__
#define __GAME_H__

// Forward delcarations.
class Board;
namespace sf { class RenderWindow; }

class Game
{
    // Window.
    sf::RenderWindow* m_window;

    // Main menu.
    // MainMenu* m_mainMenu;

    // Playing board.
    Board* m_board;

public:
    // Ctor.
    Game();

    // Dtor.
    ~Game();

    // Play
    void play();
};

#endif