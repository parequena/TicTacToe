#include <HumanPlayer.h>

#include <Selector.h>

// Dtor.
HumanPlayer::~HumanPlayer()
{

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

#include <iostream>

// Select wich position are we going to place the Token.
uint8_t HumanPlayer::selectBox() const
{
    int in;
    std::cin >> in;
    return static_cast<uint8_t>(in);
}