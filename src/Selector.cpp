#include <SFML/Graphics.hpp>
#include <Selector.h>

#define df_selectorPath "./res/selector"

// Init ids
uint8_t Selector::m_id = 1;

// Move up.
uint8_t moveUp(uint8_t position)
{
    if(position != 0 && position != 1 && position != 2)
        return position - 3;
    return position;
}

// Move left.
uint8_t moveLeft(uint8_t position)
{
    if(position != 0 && position != 3 && position != 6)
        return position - 1;
    return position;
}

// Move right.
uint8_t moveRight(uint8_t position)
{
    if(position != 2 && position != 5 && position != 8)
        return position + 1;
    return position;
}

// Move down.
uint8_t moveDown(uint8_t position)
{
    if(position != 6 && position != 7 && position != 8)
        return position + 3;
    return position;
}

//////////////////////////////////////////////////////////////////
///////////////////////////// PUBLIC /////////////////////////////
//////////////////////////////////////////////////////////////////
// Ctor.
Selector::Selector(sf::RenderWindow* window):
    m_window(nullptr),
    m_texture(nullptr),
    m_sprite(nullptr)
{
    // Set the window
    if (!window)
        throw std::logic_error("Null SFML Window received (Selector).");
    m_window = window;

    // Load texture.
    m_texture = new sf::Texture();
    m_texture->loadFromFile(df_selectorPath + std::to_string(m_id++) + ".png");
}