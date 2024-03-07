/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

namespace sf
{
class Texture;
class Sprite;
class RenderWindow;
}
#include <Player.hpp>
struct KeyToMethod;

// Move up.
void moveUp(std::uint8_t& pos);

// Move left.
void moveLeft(std::uint8_t& pos);

// Move right.
void moveRight(std::uint8_t& pos);

// Move down.
void moveDown(std::uint8_t& pos);

class HumanPlayer : public Player
{
   // Vertor of positions.
   std::array<float, 3> m_pos{};

   // Selected position.
   std::uint8_t m_position{};

   // Static id.
   static std::uint8_t m_id;

   // Window
   sf::RenderWindow* m_window{};

   // Texture.
   sf::Texture* m_texture{};

   // Sprite.
   sf::Sprite* m_sprite{};

   // Check if is valid.
   static bool isValid(
     std::uint8_t pos, std::array<std::uint8_t, 9> const& board);

public:
   // Ctor.
   HumanPlayer(sf::RenderWindow* window);

   // Dtor.
   ~HumanPlayer() noexcept override;

   // Select wich position are we going to place the Token.
   std::uint8_t selectBox(std::array<std::uint8_t, 9> const& board) override;

   // Draw.
   void draw() override;
};

#endif
