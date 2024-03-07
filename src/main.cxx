#include <SFML/Graphics/RenderWindow.hpp> // sf::RenderWindow
#include <cstdint>                        // std::uint8_t
#include <memory>                         // std::shared_ptr

import Token;
import Board;
import AIPlayer;

int main()
{
  auto render = std::make_shared<sf::RenderWindow>(
    sf::VideoMode(500, 500), "Test", sf::Style::Titlebar | sf::Style::Close);

  constexpr auto Talker = [](auto const& call) { call.Say(); };

  Token token{ render, std::uint8_t{ 2 }, Token::Type::X };
  Board board{ render };
  AIPlayer ai{ render };

  Talker(token);
  Talker(board);
  Talker(ai);

  return 0;
}
