#include <AIPlayer.h>
#include <cstdlib>

// Dtor.
AIPlayer::~AIPlayer()
{

}

// Difficulty 0.
uint8_t AIPlayer::difficulty0() const
{
    return rand() % 9;
}

//////////////////////////////////////////////////////////////////
///////////////////////////// PUBLIC /////////////////////////////
//////////////////////////////////////////////////////////////////
// Ctor.
AIPlayer::AIPlayer(uint8_t difficulty)
{
    if(difficulty == 0)
    {
        pfunc = &AIPlayer::difficulty0;
    }
}

// Select wich position are we going to place the Token.
uint8_t AIPlayer::selectBox() const
{
    return (this->*pfunc)();
}