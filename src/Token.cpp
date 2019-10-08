#include <cstdint>
#include <SFML/Graphics.hpp>

#include <Token.h>

#define df_initX 58
#define df_initY 58

#define df_XPath "./res/x.png"
#define df_OPath "./res/x.png"

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
}

// Dtor.
Token::~Token()
{

}

// Draw.
void Token::draw()
{
    m_window->draw(*m_sprite);
}