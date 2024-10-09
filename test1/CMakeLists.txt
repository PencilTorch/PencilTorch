cmake_minimum_required(VERSION 3.5)

project(test1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package (SQLite3 REQUIRED)
if (SQLITE3_FOUND)
    include_directories(${SQLITE3_INCLUDE_DIRS})
    link_directories(${SQLite3_LIBRARY_DIR})
    add_definitions(-lsqlite3)
endif ()

add_executable(test1 main.cpp)

target_link_libraries(test1 sqlite3)
