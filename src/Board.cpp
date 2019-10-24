/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>

#include <Board.h>
#include <AIPlayer.h>
#include <HumanPlayer.h>
#include <Token.h>
#include <KeyToMethod.h>

#define df_boardPath "./res/box.png"

// Game end.
bool Board::gameEnded() const
{
    if(m_currToken == 9) return true;
    return false;
}

// Check winner.
bool Board::checkWinner() const
{
    return (m_board[0] != 0
            && (m_board[0] == m_board[1] && m_board[0] == m_board[2]                    /* 0-1-2 */
            ||  m_board[0] == m_board[3] && m_board[0] == m_board[6]                    /* 0-3-6 */
            ||  m_board[0] == m_board[4] && m_board[0] == m_board[8]))                  /* 0-4-8 */
        || (m_board[3] != 0 && m_board[3] == m_board[4] && m_board[3] == m_board[5])    /* 3-4-5 */
        || (m_board[6] != 0 && m_board[6] == m_board[7] && m_board[6] == m_board[8])    /* 6-7-8 */
        || (m_board[1] != 0 && m_board[1] == m_board[4] && m_board[1] == m_board[7])    /* 1-4-7 */
        || (m_board[2] != 0
            && (m_board[2] == m_board[5] && m_board[2] == m_board[8]                    /* 2-5-8 */
            ||  m_board[2] == m_board[4] && m_board[2] == m_board[6]));                 /* 2-4-6 */
}

// Get the winner.
uint8_t Board::getWinner() const
{
    if(m_board[0] == m_board[1] && m_board[0] == m_board[2]
    ||  m_board[0] == m_board[3] && m_board[0] == m_board[6]
    ||  m_board[0] == m_board[4] && m_board[0] == m_board[8])
        return m_board[0];

    if(m_board[3] == m_board[4] && m_board[3] == m_board[5])
        return m_board[3];
    if(m_board[6] == m_board[7] && m_board[6] == m_board[8])
        return m_board[6];
    if(m_board[1] == m_board[4] && m_board[1] == m_board[7])
        return m_board[1];
    
    if(m_board[2] == m_board[5] && m_board[2] == m_board[8]
    ||  m_board[2] == m_board[4] && m_board[2] == m_board[6])
        return m_board[2];

    return 0;
}

// Dtor.
Board::~Board()
{
    // Delete the window.
    if(m_window)
    {
        delete m_window;
        m_window = nullptr;
    }

    // Delete the texture.
    if(m_texture)
    {
        delete m_texture;
        m_texture = nullptr;
    }

    // Delete the sprites.
    if(m_sprites)
    {
        for(auto &s : m_sprites)
        {
            delete s;
            s = nullptr;
        }
    }

    // Delete the players.
    if(m_players)
    {
        for(auto &s : m_players)
        {
            delete s;
            s = nullptr;
        }
    }

    // Delete the tokens.
    if(m_tokens)
    {
        for(auto &s : m_tokens)
        {
            delete s;
            s = nullptr;
        }
    }
}

//////////////////////////////////////////////////////////////////
///////////////////////////// PUBLIC /////////////////////////////
//////////////////////////////////////////////////////////////////
// Ctor.
Board::Board(sf::RenderWindow* window, uint8_t nplayers, uint8_t difficulty):
    m_board{0, 0, 0, 0, 0, 0, 0, 0, 0},
    m_window(nullptr),
    m_texture(nullptr),
    m_sprites{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
    m_firstPlayer(false),
    m_currToken(0),
    m_players{nullptr, nullptr},
    m_tokens{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr}
{
    // Set the first player.
    srand(time(NULL));
    m_firstPlayer = static_cast<bool>(rand() % 2);

    // Set the window
    if (!window)
        throw std::logic_error("Null SFML Window received (Board).");
    m_window = window;

    // Load texture.
    m_texture = new sf::Texture();
    m_texture->loadFromFile(df_boardPath);

    // Load Sprites.
    m_window->clear(sf::Color::White);

    uint16_t coords[3] = {df_init, 186, 314};
    for(auto i = 0; i < 9; ++i)
    {
        m_sprites[i] = new sf::Sprite(*m_texture);
        m_sprites[i]->setPosition(coords[i/3], coords[i%3]);
    }

    // Load players.
    if(nplayers == 0)
    {
        m_players[0] = new AIPlayer(m_window, difficulty);
        m_players[1] = new AIPlayer(m_window, difficulty);
    }
    else if(nplayers == 1)
    {
        m_players[0] = new HumanPlayer(m_window);
        m_players[1] = new AIPlayer(m_window, difficulty);
    }
    else
    {
        m_players[0] = new HumanPlayer(m_window);
        m_players[1] = new HumanPlayer(m_window);
    }
    
    // Just in case.
    waitUntilRelease(sf::Keyboard::Return);
};

#include <iostream>

// Play.
uint8_t Board::play()
{
    uint8_t selected = 0;
    // Draw the board.
    draw();

    do
    {
        bool d;
        do
        {
            // Get the position.
            selected = m_players[m_firstPlayer]->selectBox(m_board);

            // Draw the board.
            draw();

        } while(selected >= 10 || !sf::Keyboard::isKeyPressed(sf::Keyboard::Return));
        waitUntilRelease(sf::Keyboard::Return);

        // Set the selected to the current player.
        m_board[selected] = m_players[m_firstPlayer]->getId();

        // Create the token.
        m_tokens[m_currToken++] = new Token(m_window, selected, static_cast<TokenType>(m_players[m_firstPlayer]->getId() - 1));

        // Draw the board.
        draw();

        // Swap player.
        m_firstPlayer = !m_firstPlayer;

        if(checkWinner())
            return getWinner();

    } while (!gameEnded());

    return 0;
}

// Draw.
void Board::draw()
{
    // Clear the screen
    m_window->clear(sf::Color::White);

    // Draw the board.
    for(auto s : m_sprites)
        m_window->draw(*s);

    // Draw the tokens.
    for(auto i = 0; i < m_currToken; ++i)
        m_tokens[i]->draw();

    // Draw the player
    m_players[m_firstPlayer]->draw();

    // Display the window.
    m_window->display();
}
