#ifndef __SELECTOR_H__
#define __SELECTOR_H__

namespace sf { class Texture; class Sprite; class RenderWindow; class Keyboard; }

// Move up.
uint8_t moveUp(uint8_t position);

// Move left.
uint8_t moveLeft(uint8_t position);

// Move right.
uint8_t moveRight(uint8_t position);

// Move down.
uint8_t moveDown(uint8_t position);

struct KeyToMethod
{
    sf::Keyboard::Key m_key;
    uint8_t (*pfunc)(uint8_t);
};

KeyToMethod ktom[] =
{
    { sf::Keyboard::W, moveUp    },
    { sf::Keyboard::A, moveLeft  },
    { sf::Keyboard::S, moveDown  },
    { sf::Keyboard::D, moveRight }
};

class Selector
{
    // Static id.
    static uint8_t m_id;
    
    // Window
    sf::RenderWindow* m_window;

    // Texture.
    sf::Texture* m_texture;

    // Sprite.
    sf::Sprite* m_sprite;

public:
    // Ctor.
    Selector(sf::RenderWindow* window);
};

#endif