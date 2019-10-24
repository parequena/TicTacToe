/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#include <iostream>

#include <SFML/Graphics.hpp>

#include <Game.h>
#include <Board.h>
#include <Menu.h>

#define df_windSize 500
#define df_gameName "TicTacToe"


//////////////////////////////////////////////////////////////////
///////////////////////////// PUBLIC /////////////////////////////
//////////////////////////////////////////////////////////////////
// Ctor.
Game::Game():
    m_window(nullptr),
    m_menu(nullptr),
    m_board(nullptr)
{
    // This cout just reserves the stream-out buffer.
    std::cout << "Game started\n";

    // Create the window.
    m_window = new sf::RenderWindow(sf::VideoMode(df_windSize, df_windSize), df_gameName,
        sf::Style::Titlebar | sf::Style::Close);

    // Set-it on the middle of the screen.
    m_window->setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - df_windSize / 2, 
        sf::VideoMode::getDesktopMode().height / 2 - df_windSize / 2));

    // Set the menu
    m_menu = new Menu(m_window);
    // m_board = new Board(m_window, 1, 0);
}

// Dtor.
Game::~Game()
{
    if(m_window)
    {
        m_window->close();
        delete m_window;
        m_window = nullptr;
    }
}

// Play.
void Game::play()
{
    MenuSelect* s = m_menu->select();
    if(!s->m_play)
    {
        std::cout << "Exit\n";
        return;
    }

    // Play the game.
    m_board = new Board(m_window, s->m_nPlayers, s->m_AILevel);

    int winner = static_cast<int>(m_board->play());
    std::cout << "Player: " << winner << " won the game.\n";
}