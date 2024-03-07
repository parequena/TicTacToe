cmake_minimum_required(VERSION 3.28)

project(TicTacToe LANGUAGES CXX)

# Include CPM to handle dependencies.
include(cmake/CPM.cmake)

# Format.cmake - Formats al C++/CMake files.
CPMAddPackage("gh:TheLartians/Format.cmake@1.8.1")

# SFML - Rendering lib.
# CPMAddPackage("gh:SFML/SFML#2.6.1")

set(PROJECT_WARNINGS "${SANITIZER_FLAGS};${GENERAL_COMPILER_WARNINGS};${SPECIFIC_COMPILER_WARNINGS}")
file(COPY resource DESTINATION ${CMAKE_BINARY_DIR})

add_subdirectory(src)

add_executable(TicTacToe src/main.cxx)
target_compile_options(TicTacToe PRIVATE ${PROJECT_WARNINGS})
set_property(TARGET TicTacToe PROPERTY COMPILE_WARNING_AS_ERROR ON)
set_target_properties(TicTacToe PROPERTIES
  CXX_STANDARD 23
  CXX_EXTENSIONS OFF
)
target_link_libraries(TicTacToe PRIVATE ${LINKER_FLAGS} ${SANITIZER_FLAGS} Token Board Players)
