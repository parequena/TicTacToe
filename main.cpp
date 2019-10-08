#include <Game.h>

int main()
{
    Game* g = new Game();
    g->play();
    delete g;

    return 0;
}