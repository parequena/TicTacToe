/*
   Project: TicTacToe (C++20's module update)
   Author : Pablo Requena (Twitter: @conPdePABLO)
   GitHub : https://github.com/parequena/TicTacToe/
   Date   : March 2024
*/
module;

#include <SFML/Graphics/RenderWindow.hpp> // sf::RenderWindow
#include <SFML/Graphics/Sprite.hpp>       // sf::Sprite
#include <SFML/Graphics/Texture.hpp>      // sf::Texture
#include <array>                          // std::array
#include <cstdint>                        // std::uint8_t
#include <iostream>                       // std::cout
#include <memory>                         // std::shared_ptr, std::unique_ptr
#include <string>                         // std::string

export module Token;

static constexpr auto Xpng{ "./resource/x.png" };
static constexpr auto Opng{ "./resource/o.png" };

export struct Token
{
  enum class Type : std::uint8_t
  {
    X,
    O
  };

  explicit Token(std::shared_ptr<sf::RenderWindow> window,
    std::uint8_t const boardPos, Type const type)
      : window_{ window }
      , texture_{ std::make_unique<sf::Texture>() }
  {
    std::string const fileName = (type == Type::X) ? Opng : Xpng;
    texture_->loadFromFile(fileName);

    sprite_ = std::make_unique<sf::Sprite>(*texture_);
    auto const x = coords_[boardPos % 3];
    auto const y = coords_[boardPos / 3];
    sprite_->setPosition(x, y);
  }

  constexpr void Draw() const noexcept { window_->draw(*sprite_); }
  void Say() const noexcept { std::cout << "Token::Say()\n"; }

private:
  static constexpr std::array<float, 3> coords_{ 58.F, 186.F, 314.F };
  std::shared_ptr<sf::RenderWindow> window_{};
  std::unique_ptr<sf::Texture> texture_{};
  std::unique_ptr<sf::Sprite> sprite_{};
};
