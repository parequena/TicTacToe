#ifndef __AIPLAYER_H__
#define __AIPLAYER_H__

#include <Player.h>

class AIPlayer : public Player
{
    // Dtor.
    ~AIPlayer();

    // Pointer ftion to set the difficulty.
    uint8_t (AIPlayer::*pfunc)() const;

    // Difficulty 0.
    uint8_t difficulty0() const;
    
public:
    // Ctor.
    AIPlayer(uint8_t difficulty);

    // Select wich position are we going to place the Token.
    uint8_t selectBox() const override;

    // // Draw
    // inline void draw() override { return;}
};

#endif