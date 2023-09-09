cmake_minimum_required(VERSION 3.25)
project(The_Mystical_Library_Manager)

set(CMAKE_CXX_STANDARD 17)

add_executable(The_Mystical_Library_Manager main.cpp MysticalDocument.cpp MysticalDocument.h containerDoc.h MysticalLibraryException.cpp MysticalLibraryException.h containerDoc.cpp)
