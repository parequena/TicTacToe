/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#ifndef KEYTOMETHOD_H
#define KEYTOMETHOD_H

#include <SFML/Graphics.hpp>
#include <cstdint> // std::uint8_t

// Struct to whitch between a key and method.
struct KeyToMethod
{
   sf::Keyboard::Key m_key{};
   std::uint8_t (*pfunc)(std::uint8_t){};
};

// Wait for the key release.
inline static void waitUntilRelease(sf::Keyboard::Key k)
{
   while (sf::Keyboard::isKeyPressed(k))
      ;
}

// Menu functions to move.
inline static constexpr std::uint8_t menu_moveUp(std::uint8_t i)
{
   return i == 0 ? 0 : --i;
}
inline static constexpr std::uint8_t menu_moveDown(std::uint8_t i)
{
   return i == 4 ? 4 : ++i;
}

// Board functions to move
inline static constexpr std::uint8_t board_moveUp(std::uint8_t i)
{
   return i <= 2 ? i : i -= 3;
}
inline static constexpr std::uint8_t board_moveDown(std::uint8_t i)
{
   return i >= 6 ? i : i += 3;
}
inline static constexpr std::uint8_t board_moveLeft(std::uint8_t i)
{
   return i % 3 == 0 ? i : --i;
}
inline static constexpr std::uint8_t board_moveRight(std::uint8_t i)
{
   return (i % 3) - 2 == 0 ? i : ++i;
}

#endif
