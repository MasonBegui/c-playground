cmake_minimum_required(VERSION 3.24)
project(tictactoe VERSION 2026.06.0 DESCRIPTION "Masons Tic-Tac-Toe" LANGUAGES C)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

# raylib's CMakeLists.txt uses project() without LANGUAGES, which
# defaults to C+CXX. Work around the lack of g++.
set(CMAKE_CXX_COMPILER ${CMAKE_C_COMPILER} CACHE FILEPATH "CXX compiler" FORCE)
set(CMAKE_CXX_COMPILER_WORKS TRUE CACHE INTERNAL "")
set(CMAKE_CXX_COMPILER_FORCED TRUE CACHE INTERNAL "")

set(RAYLIB_VERSION 6.0)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    FIND_PACKAGE_ARGS ${RAYLIB_VERSION} EXACT
)

# --- FORCE WAYLAND BUILD OPTIONS HERE ---
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(USE_WAYLAND ON CACHE BOOL "Force Raylib to use Wayland" FORCE)
set(GLFW_BUILD_X11 OFF CACHE BOOL "Disable X11 support in GLFW" FORCE)
set(GLFW_BUILD_WAYLAND ON CACHE BOOL "Enable Wayland support in GLFW" FORCE)
# ----------------------------------------


FetchContent_MakeAvailable(raylib)

#name_of_the_binary source_code 
#Console program
add_executable(${PROJECT_NAME}_console main_console.c ttt_game.c)  

#Raylib program
add_executable(${PROJECT_NAME}_raylib main_raylib.c ttt_game.c)  
target_link_libraries(${PROJECT_NAME}_raylib raylib)
