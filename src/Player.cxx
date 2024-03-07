/*
   Project: TicTacToe (C++20's module update)
   Author : Pablo Requena (Twitter: @conPdePABLO)
   GitHub : https://github.com/parequena/TicTacToe/
   Date   : March 2024
*/
module;

#include <SFML/Graphics/RenderWindow.hpp> // sf::RenderWindow
#include <cstdint>                        // std::uint8_t
#include <iostream>                       // std::cout
#include <memory>                         // std::shared_ptr

export module Player;

export struct Player
{
  virtual ~Player() = default;
  explicit Player(std::shared_ptr<sf::RenderWindow> window)
      : window_{ window }
  {
  }

protected:
  std::shared_ptr<sf::RenderWindow> window_{};
};

// module :private;
// virtual ~Player() = default;
