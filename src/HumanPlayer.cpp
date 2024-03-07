/*
    Project: TicTacToe
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github.com/parequena/TicTacToe/
    Date   : October 2019
*/

#include <HumanPlayer.hpp>
#include <KeyToMethod.hpp>
#include <SFML/Graphics.hpp>

#define df_selectorPath "./res/selector"

// Init idsx
std::uint8_t HumanPlayer::m_id = 1;
std::uint8_t Player::m_staticId = 1;

// Board key to method.
static constexpr std::array<KeyToMethod, 8> board_ktom{
   KeyToMethod{ sf::Keyboard::W, board_moveUp },
   KeyToMethod{ sf::Keyboard::A, board_moveLeft },
   KeyToMethod{ sf::Keyboard::S, board_moveDown },
   KeyToMethod{ sf::Keyboard::D, board_moveRight },

   KeyToMethod{ sf::Keyboard::Up, board_moveUp },
   KeyToMethod{ sf::Keyboard::Left, board_moveLeft },
   KeyToMethod{ sf::Keyboard::Down, board_moveDown },
   KeyToMethod{ sf::Keyboard::Right, board_moveRight }
};

// Is valid
bool HumanPlayer::isValid(
  std::uint8_t pos, std::array<std::uint8_t, 9> const& board)
{
   return pos < 9 && board[pos] == 0;
}

//////////////////////////////////////////////////////////////////
///////////////////////////// PUBLIC /////////////////////////////
//////////////////////////////////////////////////////////////////
// Ctor.
HumanPlayer::HumanPlayer(sf::RenderWindow* window)
    : m_pos{ 58, 186, 314 }
    , m_position(5)
    , m_window(nullptr)
    , m_texture(nullptr)
    ,

    m_sprite(nullptr)
{
   // Set the window
   if (!window)
      throw std::logic_error("Null SFML Window received (HumanPlayer).");
   m_window = window;

   // Load texture.
   m_texture = new sf::Texture();
   m_texture->loadFromFile(df_selectorPath + std::to_string(m_id++) + ".png");

   // Load sprite.
   m_sprite = new sf::Sprite(*m_texture);

   // Set position
   m_position = 4;
   m_sprite->setPosition(
     float(m_pos[m_position % 3]), float(m_pos[m_position / 3]));

   // Increase the id
   m_playerId = m_staticId++;

   // Just in case.
   waitUntilRelease(sf::Keyboard::Return);
}

// Dtor.
HumanPlayer::~HumanPlayer() noexcept
{
   if (m_window)
   {
      // delete m_window; // We are not doing a new!
      m_window = nullptr;
   }

   if (m_texture)
   {
      delete m_texture;
      m_texture = nullptr;
   }

   if (m_sprite)
   {
      delete m_sprite;
      m_sprite = nullptr;
   }

   // Decrease the id.
   --m_staticId;
   --m_id;
}

// Select wich position are we going to place the Token.
std::uint8_t HumanPlayer::selectBox(std::array<std::uint8_t, 9> const& board)
{
   for (auto const [key, pFunc] : board_ktom)
   {
      // If any is pressed.
      if (sf::Keyboard::isKeyPressed(key))
      {
         m_position = pFunc(m_position); // Call the function.
         waitUntilRelease(key);
      }
   }

   m_sprite->setPosition(m_pos[m_position % 3], m_pos[m_position / 3]);

   if (isValid(m_position, board))
      return m_position;
   else
      return 10;
}

// Draw.
void HumanPlayer::draw() { m_window->draw(*m_sprite); }
