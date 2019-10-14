# Tic Tac Toe

This TicTacToe developped by Pablo Requena González using SFML 2.5.2 on Manajro (Arch Linux).

[Twitter](https://twitter.com/conPdePABLO)

[LinkedIn](https://www.linkedin.com/in/pablo-requena-gonz%C3%A1lez-387366146/)

[GitHub](https://github.com/parequena)

## Features

- Pointers to function or method
I've never done some pointer to functions or method, so I made them is some features in the game.
    - AI difficulty:
        - Level 0: Random selector.
        - ~~Level 1: TODO~~
    - Keyboard selection:
        - W / Up Arrow   : Move up the selector.
        - A / Left Arrow : Move left the selector.
        - S / Down Arrow : Move down the selector.
        - D / Right Arrow: Move right the selector.
        - Here is the keybinding:
        ```
            // All the move* are functions present on the code.
            KeyToMethod ktom[] =
            {
                { sf::Keyboard::W      , moveUp    },
                { sf::Keyboard::A      , moveLeft  },
                { sf::Keyboard::S      , moveDown  },
                { sf::Keyboard::D      , moveRight },
                
                { sf::Keyboard::Up     , moveUp    },
                { sf::Keyboard::Left   , moveLeft  },
                { sf::Keyboard::Down   , moveDown  },
                { sf::Keyboard::Right  , moveRight },
                { sf::Keyboard::Unknown, 0}
            };
        ```

## File Structure

- **.vscode:** VSCode files.
- **githubResource:** This is a folder with some images to this README.
- **inc:** Header files used on the game.
- **src:** Source files used on the game.
- **res:** Resource folder, this folder has all images used on the game.
- **main.cpp:**  Main of the game.
- **Makefile:**  Compilation file.
 
## Installation and compilation
Thanks to make, we can compile the code using a terminal.
 1. Install dependencies`yaourt sfml`on my case, in other case, just look on [SFML Installation WebSide](https://www.sfml-dev.org/tutorials/2.5/start-linux.php) (Linux on this link, but it is possible to install it on several S.O.
 2. Clone this repository `git clone https://github.com/parequena/TicTacToe.git`
 3. Then insert into the project path `cd TicTacToe`
 4. Compile using Makefile `make`
 5. Execute the game calling the output file `./exe`
 6. Play the game.

## Some Images
<p align="center"><strong>Menu</strong></p>
<p align="center"><img width="248" height="261" src="https://github.com/parequena/TicTacToe/blob/master/githubResource/menu.png"></p>

<p align="center"><strong>Board, both Tokens and Human Selector</strong></p>
<p align="center"><img width="249" height="263" src="https://github.com/parequena/TicTacToe/blob/master/githubResource/both_tokens.png"></p>

<p align="center"><strong>Board, both Tokens and Human Selector</strong></p>
<p align="center">
<img width="128" height="128" src="https://github.com/parequena/TicTacToe/blob/master/res/selector1.png">
<img width="128" height="128" src="https://github.com/parequena/TicTacToe/blob/master/res/selector2.png">
</p>

<p align="center"><strong>AI Selector</strong></p>
<p align="center"><img width="300" height="300" src="https://github.com/parequena/TicTacToe/blob/master/githubResource/ai_choose.png"></p>


# Resources
- **Robot image:** https://emojiisland.com/products/robot-iphone-emoji-jpg
- **Font:** https://www.dafont.com/es/lemon-milk.font