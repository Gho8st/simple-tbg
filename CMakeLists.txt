cmake_minimum_required(VERSION 3.22)
project(simple_tbg CXX)

find_package(PkgConfig REQUIRED)
pkg_check_modules(RAYLIB REQUIRED raylib)

add_executable(SimpleTBG
    src/main.cpp
    src/debug_overlay.cpp

    external/imgui/imgui.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_tables.cpp
    external/imgui/imgui_widgets.cpp

    external/rlImGui/rlImGui.cpp
)

target_include_directories(SimpleTBG PRIVATE
    include
    external/imgui
    external/rlImGui
    ${RAYLIB_INCLUDE_DIRS}
)

target_link_libraries(SimpleTBG 
    ${RAYLIB_LIBRARIES}
)