cmake_minimum_required(VERSION 3.22)
project(simple_tbg CXX)

find_package(PkgConfig REQUIRED)
pkg_check_modules(RAYLIB REQUIRED raylib)

add_executable(SimpleTBG
    main.cpp
)

target_include_directories(SimpleTBG PRIVATE
    include
    ${RAYLIB_INCLUDE_DIRS}
)

target_link_libraries(SimpleTBG 
    ${RAYLIB_LIBRARIES}
)