cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME RegexEmojiParser)

project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCES RegexEmojiParser.cpp)

add_executable(${PROJECT_NAME} ${SOURCES} )


