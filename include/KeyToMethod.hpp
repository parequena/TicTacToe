/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#ifndef KEYTOMETHOD_H
#define KEYTOMETHOD_H

#include <SFML/Graphics.hpp>

#define df_maxMenuOpt 4

// Wait for the key release.
void waitUntilRelease(sf::Keyboard::Key k) ;

// Struct to whitch between a key and method.
struct KeyToMethod
{
    sf::Keyboard::Key m_key;
    std::uint8_t (*pfunc)(std::uint8_t) ;
};

 // Menu functions to move.
std::uint8_t menu_moveUp(std::uint8_t i) ;
std::uint8_t menu_moveDown(std::uint8_t i) ;

// Board functions to move
std::uint8_t board_moveUp(std::uint8_t i) ;
std::uint8_t board_moveDown(std::uint8_t i) ;
std::uint8_t board_moveLeft(std::uint8_t i) ;
std::uint8_t board_moveRight(std::uint8_t i) ;

#endif
