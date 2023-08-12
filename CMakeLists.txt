# CMake Version
cmake_minimum_required(VERSION 3.5)

# Constants
set(PROJECT_NAME "kedar")
set(OpenGL_GL_PREFERENCE LEGACY)

# Project Name
project(${PROJECT_NAME})

# CXX Standard
set(CXX_STANDARD_REQUIRED 11)

# Packages
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

# File Globs
file(GLOB HEADERS_FILES "src/Headers/*.hpp")
file(GLOB CLASSES_FILES "src/Classes/*.cpp")
file(GLOB UTILS_FILES "src/Utils/*.cpp" "src/Utils/.hpp")

# Executable
add_executable(
  ${PROJECT_NAME}
  src/Main.cpp
  ${HEADERS_FILES}
  ${CLASSES_FILES}
  ${UTILS_FILES}
)
target_link_libraries(${PROJECT_NAME} PUBLIC GL GLEW glfw)
