#include <SFML/Graphics.hpp>

#include <Board.h>
#include <AIPlayer.h>
#include <HumanPlayer.h>
#include <Token.h>

#define df_boardPath "./res/box.png"

// Game end.
bool Board::gameEnded() const
{
    if(m_currToken == 9) return true;
    return false;
}

// Is valid
bool Board::isValid(uint8_t position) const
{
    return m_board[position] == 0;
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

#include <iostream>

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
    // Set the window
    if (!window)
        throw std::logic_error("Null SFML Window received (Board).");

    m_window = window;

    // Load texture.
    m_texture = new sf::Texture();
    m_texture->loadFromFile(df_boardPath);

    // Load Sprites.
    m_window->clear(sf::Color::White);

    int coords[3] = {df_initX, 186, 314};
    for(auto i = 0; i < 9; ++i)
    {
        m_sprites[i] = new sf::Sprite(*m_texture);
        m_sprites[i]->setPosition(coords[i/3], coords[i%3]);
    }

    std::cin.get();
    // Load players.
    if(nplayers == 0)
    {
        m_players[0] = new AIPlayer(difficulty);
        m_players[1] = new AIPlayer(difficulty);
    }
    else if(nplayers == 1)
    {
        m_players[0] = new HumanPlayer();
        m_players[1] = new AIPlayer(difficulty);
    }
    else
    {
        m_players[0] = new HumanPlayer();
        m_players[1] = new HumanPlayer();
    }
    
};

// Play.
void Board::play()
{
    uint8_t selected = 0;
    do
    {
        do
        {
            selected = m_players[m_firstPlayer]->selectBox();
        } while(!isValid(selected));
    } while (!gameEnded());
}

// Draw.
void Board::draw()
{
    for(auto s : m_sprites)
        m_window->draw(*s);

    for(auto i = 0; i < m_currToken; ++i)
        m_tokens[i]->draw();

    m_window->display();
}
