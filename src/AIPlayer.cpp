#include <AIPlayer.h>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <vector>

#define df_AISprite "./res/ai.png"

// Dtor.
AIPlayer::~AIPlayer()
{
    if(m_window)
    {
        delete m_window;
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
}

// Difficulty 0.
uint8_t AIPlayer::difficulty0(const uint8_t rMax) const
{
    return rand() % rMax;
}

//////////////////////////////////////////////////////////////////
///////////////////////////// PUBLIC /////////////////////////////
//////////////////////////////////////////////////////////////////
// Ctor.
AIPlayer::AIPlayer(sf::RenderWindow* window, uint8_t difficulty)
{
    // Set the window
    if (!window)
        throw std::logic_error("Null SFML Window received (AIPlayer).");
    m_window = window;

    // Load texture.
    m_texture = new sf::Texture();
    m_texture->loadFromFile(df_AISprite);

    // Load sprite.
    m_sprite = new sf::Sprite(*m_texture);

    // Set position
    m_sprite->setPosition(100, 100);


    if(difficulty == 0)
    {
        pfunc = &AIPlayer::difficulty0;
    }
}

// Select wich position are we going to place the Token.
uint8_t AIPlayer::selectBox(const uint8_t board[9]) const
{
    std::vector<uint8_t> freePos;
    freePos.reserve(9); // Reserve for 9.

    // Get free positions.
    for(auto i = 0; i < 9; ++i)
        if(board[i] == 0)
            freePos.emplace_back(i);

    // Return a free position.
    return freePos[(this->*pfunc)(freePos.size())];
}

// Draw
void AIPlayer::draw()
{
    m_window->draw(*m_sprite);
}