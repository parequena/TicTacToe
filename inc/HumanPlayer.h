#ifndef __HUMANPLAYER_H__
#define __HUMANPLAYER_H__

#include <Player.h>

class Selector;
namespace sf { class RenderWindow; }

class HumanPlayer : public Player
{
    // Selector
    Selector* m_selector;

    // Dtor.
    ~HumanPlayer();
    
public:
    // Ctor.
    HumanPlayer(sf::RenderWindow* window);

    // Select wich position are we going to place the Token.
    uint8_t selectBox() const override;

    // Draw
    void draw();
};

#endif