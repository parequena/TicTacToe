/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <cstdint>

class Player
{
protected:

    // Static Id.
    static std::uint8_t m_staticId;

    // Player id.
    std::uint8_t m_playerId;

public:
    // Dtor.
    virtual ~Player() = default;

    // Select wich position are we going to place the Token.
    inline virtual std::uint8_t selectBox(const std::uint8_t board[9]) = 0;

    // Draw
    inline virtual void draw() = 0;

    // Get the id.
    inline std::uint8_t getId()  { return m_playerId; }

    // Check winner.
    static bool checkWinner(const std::uint8_t board[9]);

    // Get the winner.
    static std::uint8_t getWinner(const std::uint8_t board[9]);
};

#endif
