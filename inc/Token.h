/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#ifndef __TOKEN_H__
#define __TOKEN_H__

enum class TokenType { X, O };
namespace sf { class Texture; class Sprite; class RenderWindow; }

#define df_init 58

class Token
{
    // Sprite position.
    uint16_t m_x, m_y;

    // Window.
    sf::RenderWindow* m_window;

    // Texture.
    sf::Texture* m_texture;

    // Sprite.
    sf::Sprite* m_sprite;

public:
    // Ctor.
    Token(sf::RenderWindow* window, uint16_t boardPos, TokenType type);

    // Dtor.
    ~Token() noexcept;

    // Draw.
    void draw();
};

#endif