#ifndef __AIPLAYER_H__
#define __AIPLAYER_H__

namespace sf { class Texture; class Sprite; class RenderWindow; }
#include <Player.h>

class AIPlayer : public Player
{
    // Window
    sf::RenderWindow* m_window;

    // Texture. 
    sf::Texture* m_texture;

    // Sprite.
    sf::Sprite* m_sprite;

    // Dtor.
    ~AIPlayer();

    // Pointer ftion to set the difficulty.
    uint8_t (AIPlayer::*pfunc)(uint8_t) const;

    // Difficulty 0.
    uint8_t difficulty0(const uint8_t rMax) const;
    
public:
    // Ctor.
    AIPlayer(sf::RenderWindow* window, uint8_t difficulty);

    // Select wich position are we going to place the Token.
    uint8_t selectBox(const uint8_t board[9]) const override;

    // Draw
    void draw() override;
};

#endif