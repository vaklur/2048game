# CMakeList.txt: Soubor projektu CMake na nejvyšší úrovni, proveďte na tomto
# místě globální konfiguraci a zahrňte podprojekty.
#
cmake_minimum_required (VERSION 3.8)

project ("2048game")

# Zahrňte podprojekty.
add_subdirectory ("2048game")
