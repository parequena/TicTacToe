/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

namespace sf { class Texture; class Sprite; class RenderWindow; }
#include <Player.hpp>
struct KeyToMethod;

// Move up.
void moveUp(std::uint8_t& pos) ;

// Move left.
void moveLeft(std::uint8_t& pos) ;

// Move right.
void moveRight(std::uint8_t& pos) ;

// Move down.
void moveDown(std::uint8_t& pos) ;

class HumanPlayer : public Player
{
    // Selecting or not
    bool m_selecting;

    // Vertor of positions.
    const int m_pos[3];

    // Selected position.
    std::uint8_t m_position;

    // Static id.
    static std::uint8_t m_id;
    
    // Window
    sf::RenderWindow* m_window;

    // Texture. 
    sf::Texture* m_texture;

    // Sprite.
    sf::Sprite* m_sprite;

    // Keyboad
    KeyToMethod* m_keyboard;

    // Check if is valid.
    static bool isValid(std::uint8_t pos, const std::uint8_t board[9]) ;

public:
    // Ctor.
    HumanPlayer(sf::RenderWindow* window);

    // Dtor.
    ~HumanPlayer() noexcept override;

    // Select wich position are we going to place the Token.
    std::uint8_t selectBox(const std::uint8_t board[9]) override;

    // Draw.
    void draw() override;
};

#endif
