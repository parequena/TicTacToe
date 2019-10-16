#include <SFML/Graphics.hpp>
#include <Menu.h>
#include <KeyToMethod.h>

// Draw
void Menu::draw() const
{
    m_window->clear(sf::Color::White);
    m_window->draw(*m_title);
    for(auto t : m_texts)
        m_window->draw(*t);
    m_window->display();
}

//////////////////////////////////////////////////////////////////
///////////////////////////// PUBLIC /////////////////////////////
//////////////////////////////////////////////////////////////////
// Ctor.
Menu::Menu(sf::RenderWindow* window):
    m_window(nullptr),
    m_font(nullptr),
    m_title(nullptr),
    m_texts{nullptr, nullptr, nullptr, nullptr},
    m_selection(nullptr),
    m_position(0)
{
    // Set the window.
    if (!window)
        throw std::logic_error("Null SFML Window received (Menu).");
    m_window = window;

    // Load the font.
    m_font = new sf::Font();
    m_font->loadFromFile("arial.tff");

    // Set the Title.
    m_title = new sf::Text("TicTacToe", *m_font, 50);

    // Load the selection
    m_selection = new MenuSelect();

    // Load the texts
    m_texts[0] = new sf::Text("Play", *m_font, 30);
    m_texts[1] = new sf::Text("N. Players: " + std::to_string(m_selection->m_nPlayers), *m_font, 30);
    m_texts[2] = new sf::Text("AI Level  : " + std::to_string(m_selection->m_AILevel), *m_font, 30);
    m_texts[3] = new sf::Text("Exit", *m_font, 30);

    m_texts[0]->setPosition(0, 100);
    m_texts[1]->setPosition(0, 200);
    m_texts[2]->setPosition(0, 300);
    m_texts[3]->setPosition(0, 400);

    // Set to Blue.
    m_texts[m_position]->setFillColor(sf::Color::Blue);
}

// Dtor.
Menu::~Menu()
{

}

// Board key to method.
KeyToMethod menu_ktom[] =
{
    { sf::Keyboard::W      , menu_moveUp    },
    { sf::Keyboard::S      , menu_moveDown  },

    { sf::Keyboard::Up     , menu_moveUp    },
    { sf::Keyboard::Down   , menu_moveDown  },
    { sf::Keyboard::Unknown, 0}
};

// Select
MenuSelect* Menu::select()
{
    /*
    (0) Play
    (1) Human Players
    (2) AI Level
    (3) Exit
    */
    KeyToMethod* kb = menu_ktom;
    uint8_t pos = 0;

    do
    {   
        // Loop into the keys.
        while(kb->m_key != sf::Keyboard::Unknown)
        {
            // If any is pressed.
            if(sf::Keyboard::isKeyPressed(kb->m_key))
            {
                pos = kb->pfunc(m_position); // Call the function.
                m_texts[m_position]->setFillColor(sf::Color::Black); // Set previous to Black.
                m_position = pos;   // Set m_position to actual.
                m_texts[m_position]->setFillColor(sf::Color::Blue); // Set actual to Blue.
                waitUntilRelease(kb->m_key);
            }
            ++kb;
        }

        // Set to beggining.
        draw();
        kb = menu_ktom;

    } while ((m_position != 0 || m_position != 3) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Return));
    waitUntilRelease(sf::Keyboard::Return);

    // Set if we want to play, or not.
    m_selection->m_play = !m_position;

    return m_selection;
}