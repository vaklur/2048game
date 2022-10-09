# CMakeList.txt: Projekt CMake pro 2048game, sem přidejte logiku zdrojového
# kódu a definic specifickou pro projekt.
#
cmake_minimum_required (VERSION 3.8)

# Přidejte zdrojový kód ke spustitelnému souboru tohoto projektu.
add_executable (2048game "2048game.cpp" "2048game.h" "2048draw.cpp" "2048draw.h" "structures.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2048game PROPERTY CXX_STANDARD 20)
endif()

# TODO: V případě potřeby přidejte testy a cíle instalace.
