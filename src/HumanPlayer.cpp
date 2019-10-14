#include <SFML/Graphics.hpp>
#include <HumanPlayer.h>
#include <KeyToMethod.h>

#define df_selectorPath "./res/selector"

// Init idsx
uint8_t HumanPlayer::m_id = 1;
uint8_t Player::m_staticId = 1;


// Board key to method.
KeyToMethod board_ktom[] =
{
    { sf::Keyboard::W      , board_moveUp    },
    { sf::Keyboard::A      , board_moveLeft  },
    { sf::Keyboard::S      , board_moveDown  },
    { sf::Keyboard::D      , board_moveRight },

    { sf::Keyboard::Up     , board_moveUp    },
    { sf::Keyboard::Left   , board_moveLeft  },
    { sf::Keyboard::Down   , board_moveDown  },
    { sf::Keyboard::Right  , board_moveRight },
    { sf::Keyboard::Unknown, 0}
};


// Is valid
bool HumanPlayer::isValid(uint8_t pos, const uint8_t board[9])
{
    return pos < 9 && board[pos] == 0;
}

//////////////////////////////////////////////////////////////////
///////////////////////////// PUBLIC /////////////////////////////
//////////////////////////////////////////////////////////////////
// Ctor.
HumanPlayer::HumanPlayer(sf::RenderWindow* window):
    m_selecting(false),
    m_pos{58, 186, 314},
    m_position(5),
    m_window(nullptr),
    m_texture(nullptr),

    m_sprite(nullptr)
{
    // Set the window
    if (!window)
        throw std::logic_error("Null SFML Window received (HumanPlayer).");
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
    m_keyboard = board_ktom;

    // Increase the id
    m_playerId = m_staticId++;

    // Just in case.
    waitUntilRelease(sf::Keyboard::Return);
}

// Dtor.
HumanPlayer::~HumanPlayer()
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

    // Decrease the id.
    --m_staticId;
}

// Select wich position are we going to place the Token.
uint8_t HumanPlayer::selectBox(const uint8_t board[9])
{
    // Loop into the keys.
    while(m_keyboard->m_key != sf::Keyboard::Unknown)
    {
        // If any is pressed.
        if(sf::Keyboard::isKeyPressed(m_keyboard->m_key))
        {
            m_position = m_keyboard->pfunc(m_position); // Call the function.
            waitUntilRelease(m_keyboard->m_key);
        }
        ++m_keyboard;
    }

    m_sprite->setPosition(m_pos[m_position%3], m_pos[m_position/3]);
    m_keyboard = board_ktom; // Set keyboard to init.

    if(isValid(m_position, board))
        return m_position;
    else return 10;
}

// Draw.
void HumanPlayer::draw()
{
    m_window->draw(*m_sprite);
}