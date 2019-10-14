#ifndef __BOARD_H__
#define __BOARD_H__

namespace sf { class Texture; class Sprite; class RenderWindow; }
class Player;
class Token;

class Board
{
    // Boad.
    uint8_t m_board[9];

    // Window
    sf::RenderWindow* m_window;

    // Texture.
    sf::Texture* m_texture;

    // Sprite.
    sf::Sprite* m_sprites[9];

    // Players.
    Player* m_players[2];

    // Bool that controlls which player moves.
    bool m_firstPlayer;

    // Current token
    uint8_t m_currToken;

    // Array of tokens.
    Token* m_tokens[9];

    // Game end.
    bool gameEnded() const;

    // Is valid
    bool isValid(uint8_t position) const;

    // Check winner.
    bool checkWinner() const;

    // Get the winner.
    uint8_t getWinner() const;

    // Dtor.
    ~Board();

public:
    // Ctor.
    Board(sf::RenderWindow* window, uint8_t nplayers, uint8_t difficulty);

    // Play.
    uint8_t play();

    // Draw.
    void draw();

};

#endif