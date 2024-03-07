/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#include <AIPlayer.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <vector>

#define df_AISprite "./res/ai.png"

// Difficulty 0.
std::uint8_t AIPlayer::difficulty0(
  std::array<std::uint8_t, 9> const& board) const
{
   std::vector<std::uint8_t> freePos;
   freePos.reserve(9);

   for (std::size_t i = 0; i < 9; ++i) // Save the free positions.
      if (board[i] == 0)
         freePos.emplace_back(i);

   return freePos[std::size_t(rand())
     % freePos.size()]; // Return a random free position.
}

// Difficulty 1.
std::uint8_t AIPlayer::difficulty1(
  std::array<std::uint8_t, 9> const& board) const
{
   bool empty = true;

   for (std::size_t i = 0; empty && i < 9; ++i)
      if (board[i] != 0)
         empty = false;

   if (empty)
      return std::uint8_t(rand() % 9);

   std::vector<std::uint8_t> scores;
   scores.reserve(9);

   for (std::size_t i = 0; i < 9; ++i)
   {
      if (board[i] != 0)
         continue;
      // scores[i] = miniMax(board, true);
   }

   return 0;
}

//////////////////////////////////////////////////////////////////
///////////////////////////// PUBLIC /////////////////////////////
//////////////////////////////////////////////////////////////////
// Ctor.
AIPlayer::AIPlayer(sf::RenderWindow* window, std::uint8_t difficulty)
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

   // Set the playing function.
   if (difficulty == 0)
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

// Dtor.
AIPlayer::~AIPlayer() noexcept
{
   if (m_window)
   {
      m_window = nullptr;
   }

   if (m_texture)
   {
      delete m_texture;
      m_texture = nullptr;
   }

   if (m_sprite)
   {
      delete m_sprite;
      m_sprite = nullptr;
   }

   // Decrease the id.
   --m_staticId;
}

// Select wich position are we going to place the Token.
std::uint8_t AIPlayer::selectBox(std::array<std::uint8_t, 9> const& board)
{
   return (this->*pfunc)(board);
}

// Draw
void AIPlayer::draw() { m_window->draw(*m_sprite); }
