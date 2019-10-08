#ifndef __HUMANPLAYER_H__
#define __HUMANPLAYER_H__

#include <Player.h>

class HumanPlayer : public Player
{
    // Dtor.
    ~HumanPlayer();
    
public:
    // Ctor.
    HumanPlayer();

    // Select wich position are we going to place the Token.
    uint8_t selectBox() const override;
};

#endif