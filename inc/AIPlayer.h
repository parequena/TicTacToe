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
    ~AIPlayer() noexcept;

    // Pointer ftion to set the difficulty.
    uint8_t (AIPlayer::*pfunc)(const uint8_t*) const ;

    // Difficulty 0.
    uint8_t difficulty0(const uint8_t board[9]) const ;

    // Difficulty 1.
    uint8_t difficulty1(const uint8_t board[9]) const ;

    // MiniMax
    uint8_t miniMax(uint8_t board[9], bool myTurn) const ;
    
public:
    // Ctor.
    AIPlayer(sf::RenderWindow* window, uint8_t difficulty);

    // Select wich position are we going to place the Token.
    uint8_t selectBox(const uint8_t board[9])  override;

    // Draw
    void draw()  override;
};

#endif