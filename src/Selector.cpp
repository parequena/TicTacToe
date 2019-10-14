#include <SFML/Graphics.hpp>
#include <Selector.h>

#define df_selectorPath "./res/selector"

// Init idsx
uint8_t Selector::m_id = 1;

struct KeyToMethod
{
    sf::Keyboard::Key m_key;
    void (*pfunc)(uint8_t&);
};

KeyToMethod ktom[] =
{
    { sf::Keyboard::W      , moveUp    },
    { sf::Keyboard::A      , moveLeft  },
    { sf::Keyboard::S      , moveDown  },
    { sf::Keyboard::D      , moveRight },
    { sf::Keyboard::Unknown, 0}
};

// Move up.
void moveUp(uint8_t& pos)
{
    if(pos != 0 && pos != 1 && pos != 2)
        pos -= 3;
}

// Move left.
void moveLeft(uint8_t& pos)
{
    if(pos != 0 && pos != 3 && pos != 6)
        --pos;
}

// Move right.
void moveRight(uint8_t& pos)
{
    if(pos != 2 && pos != 5 && pos != 8)
        ++pos;
}

// Move down.
void moveDown(uint8_t& pos)
{
    if(pos != 6 && pos != 7 && pos != 8)
        pos += 3;
}

void waitUntilRelease(sf::Keyboard::Key k)
{
    while(sf::Keyboard::isKeyPressed(k));
}

// Is valid
bool Selector::isValid(uint8_t pos, const uint8_t board[9])
{
    return pos < 9 && board[pos] == 0;
}

//////////////////////////////////////////////////////////////////
///////////////////////////// PUBLIC /////////////////////////////
//////////////////////////////////////////////////////////////////
// Ctor.
Selector::Selector(sf::RenderWindow* window):
    m_selecting(false),
    m_pos{58, 186, 314},
    m_position(5),
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

    // Load sprite.
    m_sprite = new sf::Sprite(*m_texture);

    // Set position
    m_position = 4;
    m_sprite->setPosition(m_pos[m_position%3], m_pos[m_position/3]);
    
    // Set the keyboard manager.
    m_keyboard = ktom;

    // Just in case.
    waitUntilRelease(sf::Keyboard::Return);
}

// Dtor.
Selector::~Selector()
{
    if(m_window)
    {
        delete m_window;
        m_window = nullptr;
    }

    if(m_texture)
    {
        delete m_texture;
        m_texture = nullptr;
    }

    if(m_sprite)
    {
        delete m_sprite;
        m_sprite = nullptr;
    }

    if(m_keyboard)
    {
        delete m_keyboard;
        m_keyboard = nullptr;
    }
}

// Select wich position are we going to place the Token.
uint8_t Selector::selectBox(const uint8_t board[9])
{
    // Loop into the keys.
    while(m_keyboard->m_key != sf::Keyboard::Unknown)
    {
        // If any is pressed.
        if(sf::Keyboard::isKeyPressed(m_keyboard->m_key))
        {
            m_keyboard->pfunc(m_position); // Call the function.
            waitUntilRelease(m_keyboard->m_key);
        }
        ++m_keyboard;
    }

    m_sprite->setPosition(m_pos[m_position%3], m_pos[m_position/3]);
    m_keyboard = ktom; // Set keyboard to init.

    if(isValid(m_position, board))
        return m_position;
    else return 10;
}

// Draw.
void Selector::draw()
{
    m_window->draw(*m_sprite);
}