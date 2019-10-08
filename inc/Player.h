#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <cstdint>

class Player
{
public:
    // Dtor.
    virtual ~Player() = default;

    // Select wich position are we going to place the Token.
    virtual uint8_t selectBox() const = 0;
};

#endif