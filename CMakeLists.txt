cmake_minimum_required(VERSION 3.22)
project(simple_tbg CXX)

set(SOURCES
    src/main.cpp
    src/entity/entity.cpp
    src/game/team.cpp
    src/game/turn_manager.cpp
)

add_executable(SimpleTBG
    ${SOURCES}
)

target_include_directories(SimpleTBG PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)