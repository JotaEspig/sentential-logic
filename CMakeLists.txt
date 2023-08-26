cmake_minimum_required(VERSION 2.8.5)
project(sentential-logic C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${sentential-logic_SOURCE_DIR}/include)
set(
    HEADER_FILES
    include/iterator.h
)

set(
    SOURCE_FILES
    src/main.c
    src/iterator.c
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(logic ${SOURCE_FILES} ${HEADER_FILES})
