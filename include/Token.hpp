/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#ifndef TOKEN_H
#define TOKEN_H

enum class TokenType
{
   X,
   O
};
namespace sf
{
class Texture;
class Sprite;
class RenderWindow;
}

// #define df_init 58

class Token
{
   // Window.
   sf::RenderWindow* m_window{};

   // Texture.
   sf::Texture* m_texture{};

   // Sprite.
   sf::Sprite* m_sprite{};

public:
   // Ctor.
   Token(sf::RenderWindow* window, uint16_t boardPos, TokenType type);

   // Dtor.
   ~Token() noexcept;

   // Draw.
   void draw();
};

#endif
