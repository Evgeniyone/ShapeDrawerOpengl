cmake_minimum_required(VERSION 3.21)
project(Drawer)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
set(PROJECT_SOURCES source/main.cpp source/Shape.cpp source/Shape.h
                    source/Render.cpp source/Render.h)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME} OpenGL::GL GLUT::GLUT)
