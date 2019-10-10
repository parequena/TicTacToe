#include <HumanPlayer.h>

#include <Selector.h>

// Dtor.
HumanPlayer::~HumanPlayer()
{
    // Delete the window.
    if(m_selector)
    {
        delete m_selector;
        m_selector = nullptr;
    }
}

//////////////////////////////////////////////////////////////////
///////////////////////////// PUBLIC /////////////////////////////
//////////////////////////////////////////////////////////////////
// Ctor.
HumanPlayer::HumanPlayer(sf::RenderWindow* window):
    m_selector(nullptr)
{
    m_selector = new Selector(window);
}

// Select wich position are we going to place the Token.
uint8_t HumanPlayer::selectBox() const
{
    return m_selector->selectBox();
}

// Draw
void HumanPlayer::draw()
{
    m_selector->draw();
}