/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#include <KeyToMethod.h>

// Wait for the key release.
void waitUntilRelease(sf::Keyboard::Key k) { while(sf::Keyboard::isKeyPressed(k)); }

// Menu functions to move.
uint8_t menu_moveUp(uint8_t i)   { return i == 0 ? 0 : --i; }
uint8_t menu_moveDown(uint8_t i) { return i == df_maxMenuOpt ? df_maxMenuOpt : ++i; }

// Board functions to move
uint8_t board_moveUp(uint8_t i)     { return i <= 2 ? i : i-=3; }
uint8_t board_moveDown(uint8_t i)   { return i >= 6 ? i : i+=3; }
uint8_t board_moveLeft(uint8_t i)   { return i%3 == 0 ? i : --i; }
uint8_t board_moveRight(uint8_t i)  { return (i%3)-2 == 0 ? i : ++i; }