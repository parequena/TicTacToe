/*
   Project: TicTacToe (C++20's module update)
   Author : Pablo Requena (Twitter: @conPdePABLO)
   GitHub : https://github.com/parequena/TicTacToe/
   Date   : March 2024
*/
module;

import Player;
#include <SFML/Graphics/RenderWindow.hpp> // sf::RenderWindow
#include <iostream>                       // std::cout
#include <memory>                         // std::unique_ptr

export module AIPlayer;

export struct AIPlayer : Player
{
  explicit AIPlayer(std::shared_ptr<sf::RenderWindow> window)
      : Player{ window }
  {
  }

  void Say() const noexcept { std::cout << "AIPlayer::Say()\n"; }
};
