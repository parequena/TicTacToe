/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#ifndef __HUMANPLAYER_H__
#define __HUMANPLAYER_H__

namespace sf { class Texture; class Sprite; class RenderWindow; }
#include <Player.h>
struct KeyToMethod;

// Move up.
void moveUp(uint8_t& pos);

// Move left.
void moveLeft(uint8_t& pos);

// Move right.
void moveRight(uint8_t& pos);

// Move down.
void moveDown(uint8_t& pos);

class HumanPlayer : public Player
{
    // Selecting or not
    bool m_selecting;

    // Vertor of positions.
    const int m_pos[3];

    // Selected position.
    uint8_t m_position;

    // Static id.
    static uint8_t m_id;
    
    // Window
    sf::RenderWindow* m_window;

    // Texture. 
    sf::Texture* m_texture;

    // Sprite.
    sf::Sprite* m_sprite;

    // Keyboad
    KeyToMethod* m_keyboard;

    // Check if is valid.
    static bool isValid(uint8_t pos, const uint8_t board[9]);

public:
    // Ctor.
    HumanPlayer(sf::RenderWindow* window);

    // Dtor.
    ~HumanPlayer();

    // Select wich position are we going to place the Token.
    uint8_t selectBox(const uint8_t board[9]);

    // Draw.
    void draw();
};

#endif