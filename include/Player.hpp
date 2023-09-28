/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <cstdint>
#include <array>

class Player
{
protected:

    // Static Id.
    static std::uint8_t m_staticId;

    // Player id.
    std::uint8_t m_playerId{};

public:
    // Dtor.
    virtual ~Player();

    // Select wich position are we going to place the Token.
    inline virtual std::uint8_t selectBox(std::array<std::uint8_t, 9> const& board) = 0;

    // Draw
    inline virtual void draw() = 0;

    // Get the id.
    constexpr std::uint8_t getId() const noexcept { return m_playerId; }

    // Check winner.
    static bool checkWinner(std::array<std::uint8_t, 9> const& board);

    // Get the winner.
    static std::uint8_t getWinner(std::array<std::uint8_t, 9> const& board);
};

#endif
