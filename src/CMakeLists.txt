find_package(SFML 2.6 COMPONENTS graphics)

# ----------------------------------------------------------------------
add_library(Token)
target_compile_options(Token PRIVATE ${PROJECT_WARNINGS})
target_link_libraries(Token PRIVATE ${LINKER_FLAGS} ${SANITIZER_FLAGS} sfml-graphics)
target_sources(Token
  PUBLIC
    FILE_SET CXX_MODULES FILES
      Token.cxx)

set_target_properties(Token PROPERTIES
  CXX_STANDARD 23
  CXX_EXTENSIONS OFF
)

# ----------------------------------------------------------------------
add_library(Board)
target_compile_options(Board PRIVATE ${PROJECT_WARNINGS})
target_link_libraries(Board PRIVATE ${LINKER_FLAGS} ${SANITIZER_FLAGS} sfml-graphics)
target_sources(Board
  PUBLIC
    FILE_SET CXX_MODULES FILES
      Board.cxx)

set_target_properties(Board PROPERTIES
  CXX_STANDARD 23
  CXX_EXTENSIONS OFF
)

# ----------------------------------------------------------------------
add_library(Players)
target_compile_options(Players PRIVATE ${PROJECT_WARNINGS})
      target_link_libraries(Players PRIVATE ${LINKER_FLAGS} ${SANITIZER_FLAGS} sfml-graphics)
      target_sources(Players
        PUBLIC
          FILE_SET CXX_MODULES FILES
          Player.cxx
          AIPlayer.cxx
            )

set_target_properties(Players PROPERTIES
  CXX_STANDARD 23
  CXX_EXTENSIONS OFF
)
