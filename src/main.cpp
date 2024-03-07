/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#include <Game.hpp>

int main()
{
   Game* g = new Game();
   g->play();
   delete g;

   return 0;
}
