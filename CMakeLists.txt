cmake_minimum_required(VERSION 3.16)
project(StudentuInformacinesistema VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(programa
    main.cpp
    menu.cpp
    enter.cpp
    generate.cpp
    file.cpp
    calculate.cpp
    print.cpp
    test.cpp
)

target_include_directories(programa PRIVATE ${CMAKE_SOURCE_DIR})

if(MSVC)
    target_compile_options(programa PRIVATE /W4 /O2)
else()
    target_compile_options(programa PRIVATE -Wall -Wextra -O2)
endif()
