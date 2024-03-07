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

export module Board;

export struct Board
{
   explicit Board(std::shared_ptr<sf::RenderWindow> window)
       : window_{ window }
   {
   }

   void Say() const noexcept { std::cout << "Board::Say()\n"; }

private:
   std::shared_ptr<sf::RenderWindow> window_{};
};
