/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#ifndef __AIPLAYER_H__
#define __AIPLAYER_H__

namespace sf { class Texture; class Sprite; class RenderWindow; }
#include <Player.h>
#include <vector>

class AIPlayer : public Player
{
    // Window
    sf::RenderWindow* m_window;

    // Texture. 
    sf::Texture* m_texture;

    // Sprite.
    sf::Sprite* m_sprite;

    // Check first movement
    bool m_firstMove;

    // Dtor.
    ~AIPlayer();

    // Pointer ftion to set the difficulty.
    uint8_t (AIPlayer::*pfunc)(const uint8_t*) const noexcept;

    // Difficulty 0.
    uint8_t difficulty0(const uint8_t board[9]) const noexcept;

    // Difficulty 1.
    uint8_t difficulty1(const uint8_t board[9]) const noexcept;

    // MiniMax
    uint8_t miniMax(uint8_t board[9], bool myTurn) const noexcept;
    
public:
    // Ctor.
    AIPlayer(sf::RenderWindow* window, uint8_t difficulty);

    // Select wich position are we going to place the Token.
    uint8_t selectBox(const uint8_t board[9]) noexcept override;

    // Draw
    void draw() noexcept override;
};

#endif