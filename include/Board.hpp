/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#ifndef BOARD_H
#define BOARD_H

#include <cstdint> // std::uint8_t
#include <array> // std::array

namespace sf { class Texture; class Sprite; class RenderWindow; }
class Player;
class Token;

class Board
{
    // Boad.
    std::array<std::uint8_t, 9> m_board{ 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    // Window
    sf::RenderWindow* m_window{};

    // Texture.
    sf::Texture* m_texture{};

    // Sprite.
    std::array<sf::Sprite*, 9> m_sprites{};

    // Players.
    std::array<Player*, 2> m_players{};

    // Bool that controlls which player moves.
    bool m_firstPlayer{false};

    // Current token
    std::uint8_t m_currToken{0};

    // Array of tokens.
    std::array<Token*, 9> m_tokens{};

    // Game end.
    bool gameEnded() const;

    // Is valid
    bool isValid(std::uint8_t position) const;

public:
    // Ctor.
    Board(sf::RenderWindow* window, std::uint8_t nplayers, std::uint8_t difficulty);

    // Dtor.
    ~Board() noexcept;

    // Play.
    std::uint8_t play();

    // Draw.
    void draw();

};

#endif
