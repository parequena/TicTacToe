#include <iostream>

#include <SFML/Graphics.hpp>

#include <Game.h>
#include <Board.h>

#define df_windSize 500
#define df_gameName "TicTacToe"

//////////////////////////////////////////////////////////////////
///////////////////////////// PUBLIC /////////////////////////////
//////////////////////////////////////////////////////////////////
// Ctor.
Game::Game():
    m_window(nullptr)/*,
    m_mainMenun(nullptr)*/,
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

    m_board = new Board(m_window, 1, 0);
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
    int winner = static_cast<int>(m_board->play());
    std::cout << "Player: " << winner << " won the game.\n";
}