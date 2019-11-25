/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#ifndef __GAME_H__
#define __GAME_H__

// Forward delcarations.
class Board;
class Menu;
namespace sf { class RenderWindow; }

class Game
{
    // Window.
    sf::RenderWindow* m_window;

    // Menu.
    Menu* m_menu;

    // Playing board.
    Board* m_board;

public:
    // Ctor.
    Game();

    // Dtor.
    ~Game() noexcept;

    // Play
    void play();
};

#endif