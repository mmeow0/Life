cmake_minimum_required(VERSION 3.21)
project(Life)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

add_executable(Life main.cpp main.h UI/Buttons.cpp UI/Buttons.h UI/Qt.h life.cpp life.h)

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)