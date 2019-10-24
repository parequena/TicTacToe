/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#ifndef __KEYTOMETHOD_H__
#define __KEYTOMETHOD_H__

#include <SFML/Graphics.hpp>

#define df_maxMenuOpt 4

// Wait for the key release.
void waitUntilRelease(sf::Keyboard::Key k);

// Struct to whitch between a key and method.
struct KeyToMethod
{
    sf::Keyboard::Key m_key;
    uint8_t (*pfunc)(uint8_t);
};

 // Menu functions to move.
uint8_t menu_moveUp(uint8_t i);
uint8_t menu_moveDown(uint8_t i);

// Board functions to move
uint8_t board_moveUp(uint8_t i);
uint8_t board_moveDown(uint8_t i);
uint8_t board_moveLeft(uint8_t i);
uint8_t board_moveRight(uint8_t i);

#endif