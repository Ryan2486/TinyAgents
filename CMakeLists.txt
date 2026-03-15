cmake_minimum_required(VERSION 4.1)
project(simulation)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(raylib)

add_executable(simulation main.cpp
        Model/pawn.cpp
        Model/pawn.h
        utils.cpp
        utils.h
        Model/MyTexture.cpp
        Model/MyTexture.h
        Model/Entity.h
        World.cpp
        World.h
        Model/Tileset.cpp
        Model/Tileset.h
        Constants.h
        Model/Sheep.cpp
        Model/Sheep.h)

target_link_libraries(simulation raylib)