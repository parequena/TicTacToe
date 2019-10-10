#ifndef __SELECTOR_H__
#define __SELECTOR_H__

namespace sf { class Texture; class Sprite; class RenderWindow; }
struct KeyToMethod;

// Move up.
void moveUp(uint8_t& pos);

// Move left.
void moveLeft(uint8_t& pos);

// Move right.
void moveRight(uint8_t& pos);

// Move down.
void moveDown(uint8_t& pos);

class Selector
{
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

public:
    // Ctor.
    Selector(sf::RenderWindow* window);

    // Dtor.
    ~Selector();

    // Select wich position are we going to place the Token.
    uint8_t selectBox();

    // Draw.
    void draw();
};

#endif