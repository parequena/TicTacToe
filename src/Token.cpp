/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#include <cstdint>
#include <array> // std::array
#include <SFML/Graphics.hpp>

#include <Token.hpp>

#define df_XPath "./res/x.png"
#define df_OPath "./res/o.png"

// Ctor.
Token::Token(sf::RenderWindow* window, uint16_t boardPosition, TokenType type):
    m_window(nullptr),
    m_texture(nullptr),
    m_sprite(nullptr)
{
    // Set the window
    if (!window)
        throw std::logic_error("Null SFML Window received (Token).");
    m_window = window;

    m_texture = new sf::Texture();
    if(type == TokenType::O)
        m_texture->loadFromFile(df_OPath);
    else m_texture->loadFromFile(df_XPath);

    // Positions.
    static constexpr std::array<float, 3> coords{ 58.f , 186.f, 314.f};
    m_sprite = new sf::Sprite(*m_texture);
    m_sprite->setPosition(coords[boardPosition%3], coords[boardPosition/3]);
}

// Dtor.
Token::~Token() noexcept
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
}

// Draw.
void Token::draw() 
{
    m_window->draw(*m_sprite);
}
