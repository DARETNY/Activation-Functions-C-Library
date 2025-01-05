cmake_minimum_required(VERSION 3.10)
project(activation_lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include dizinini ekle
include_directories(${PROJECT_SOURCE_DIR}/include)

# Örnek uygulamayı derle
add_executable(activation_example examples/main.cpp) 