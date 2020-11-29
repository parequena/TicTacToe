#include <Player.hpp>

// Check winner.
bool Player::checkWinner(const std::uint8_t board[9]) 
{
    return (board[0] != 0
            && (((board[0] == board[1]) && (board[0] == board[2]))                    /* 0-1-2 */
            ||  ((board[0] == board[3]) && (board[0] == board[6]))                    /* 0-3-6 */
            ||  ((board[0] == board[4]) && (board[0] == board[8]))))                  /* 0-4-8 */
        || (board[3] != 0 && board[3] == board[4] && board[3] == board[5])    /* 3-4-5 */
        || (board[6] != 0 && board[6] == board[7] && board[6] == board[8])    /* 6-7-8 */
        || (board[1] != 0 && board[1] == board[4] && board[1] == board[7])    /* 1-4-7 */
        || (board[2] != 0
            && (((board[2] == board[5]) && (board[2] == board[8]))                    /* 2-5-8 */
            ||  ((board[2] == board[4]) && (board[2] == board[6]))));                 /* 2-4-6 */
}

// Get the winner.
std::uint8_t Player::getWinner(const std::uint8_t board[9]) 
{
    if(board[0] != 0 &&
    (   ((board[0] == board[1]) && (board[0] == board[2]))
    ||  ((board[0] == board[3]) && (board[0] == board[6]))
    ||  ((board[0] == board[4]) && (board[0] == board[8]))))
        return board[0];

    if(board[3] != 0 && (board[3] == board[4] && board[3] == board[5]))
        return board[3];
    if(board[6] != 0 && (board[6] == board[7] && board[6] == board[8]))
        return board[6];
    if(board[1] != 0 && (board[1] == board[4] && board[1] == board[7]))
        return board[1];
    
    if(board[2] != 0 && (((board[2] == board[5]) && (board[2] == board[8]))
    ||  ((board[2] == board[4]) && (board[2] == board[6]))))
        return board[2];

    return 0;
}