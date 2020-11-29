/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#ifndef AI_PLAYER_HPP_
#define AI_PLAYER_HPP_

namespace sf { class Texture; class Sprite; class RenderWindow; }
#include <Player.hpp>
#include <vector>

class AIPlayer : public Player
{
    // Window
    sf::RenderWindow* m_window{};

    // Texture. 
    sf::Texture* m_texture{};

    // Sprite.
    sf::Sprite* m_sprite{};

    // Check first movement
    bool m_firstMove{true};

    // Pointer ftion to set the difficulty.
    std::uint8_t (AIPlayer::*pfunc)(const std::uint8_t*) const;

    // Difficulty 0.
    std::uint8_t difficulty0(const std::uint8_t board[9]) const;

    // Difficulty 1.
    std::uint8_t difficulty1(const std::uint8_t board[9]) const;
    
public:
    // Ctor.
    AIPlayer(sf::RenderWindow* window, std::uint8_t difficulty);

    // Dtor.
    ~AIPlayer() noexcept override;

    // Select wich position are we going to place the Token.
    std::uint8_t selectBox(const std::uint8_t board[9])  override;

    // Draw
    void draw()  override;
};

#endif
