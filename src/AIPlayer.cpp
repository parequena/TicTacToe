/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#include <AIPlayer.h>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <vector>

#define df_AISprite "./res/ai.png"

// Dtor.
AIPlayer::~AIPlayer() noexcept
{
    if(m_window)
    {
        // delete m_window; // We are not doing a new!
        m_window = nullptr;
    }

    if(m_texture)
    {
        delete m_texture;
        m_texture = nullptr;
    }

    if(m_sprite)
    {
        delete m_sprite;
        m_sprite = nullptr;
    }

    // Decrease the id.
    --m_staticId;
}

// Difficulty 0.
uint8_t AIPlayer::difficulty0(const uint8_t board[9]) const 
{
    std::vector<uint8_t> freePos;
    freePos.reserve(9);
    
    for(auto i = 0; i < 9; ++i) // Save the free positions.
        if(board[i] == 0) freePos.emplace_back(i);

    return freePos[rand() % freePos.size()]; // Return a random free position.
}

// Difficulty 1.
uint8_t AIPlayer::difficulty1(const uint8_t board[9]) const 
{
    bool empty = true;

    for(auto i = 0; empty && i < 9; ++i)
        if(board[i] != 0) empty = false;

    if(empty) return rand() % 9;

    std::vector<uint8_t> scores;
    scores.reserve(9);

    for(auto i = 0; i < 9; ++i)
    {
        if(board[i] != 0) continue;
        // scores[i] = miniMax(board, true);
    }

    return 0;
}

// MiniMax
uint8_t AIPlayer::miniMax(uint8_t board[9], bool myTurn) const 
{
    if(checkWinner(board) && getWinner(board) == m_playerId)
        return 10;
    else return 1;

    
}

//////////////////////////////////////////////////////////////////
///////////////////////////// PUBLIC /////////////////////////////
//////////////////////////////////////////////////////////////////
// Ctor.
AIPlayer::AIPlayer(sf::RenderWindow* window, uint8_t difficulty):
    m_firstMove(true),
    m_texture(new sf::Texture())
{
    // Set the window
    if (!window)
        throw std::logic_error("Null SFML Window received (AIPlayer).");
    m_window = window;

    // Load texture.
    m_texture->loadFromFile(df_AISprite);

    // Load sprite.
    m_sprite = new sf::Sprite(*m_texture);

    // Set position
    m_sprite->setPosition(100, 100);

    // Set the playing function.
    if(difficulty == 0)
    {
        pfunc = &AIPlayer::difficulty0;
    }
    else // if(difficulty == 1)
    {
        pfunc = &AIPlayer::difficulty1;
    }


    // Increase the id
    m_playerId = m_staticId++;
}

// Select wich position are we going to place the Token.
uint8_t AIPlayer::selectBox(const uint8_t board[9]) 
{
    return (this->*pfunc)(board);
}

// Draw
void AIPlayer::draw() 
{
    m_window->draw(*m_sprite);
}