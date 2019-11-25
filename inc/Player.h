/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <cstdint>

class Player
{
protected:

    // Static Id.
    static uint8_t m_staticId;

    // Player id.
    uint8_t m_playerId;

public:
    // Dtor.
    virtual ~Player() = default;

    // Select wich position are we going to place the Token.
    virtual uint8_t selectBox(const uint8_t board[9])  = 0;

    // Draw
    virtual void draw()  = 0;

    // Get the id.
    inline uint8_t getId()  { return m_playerId; }

    // Check winner.
    static bool checkWinner(const uint8_t board[9]) ;

    // Get the winner.
    static uint8_t getWinner(const uint8_t board[9]) ;
};

#endif