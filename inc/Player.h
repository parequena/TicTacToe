#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <cstdint>

class Player
{
public:
    // Dtor.
    virtual ~Player() = default;

    // Select wich position are we going to place the Token.
    virtual uint8_t selectBox(const uint8_t board[9]) const = 0;

    // Draw
    virtual void draw() = 0;
};

#endif