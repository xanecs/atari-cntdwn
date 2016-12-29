cmake_minimum_required(VERSION 3.6)
project(cntdwn)

set(CMAKE_C_COMPILER m68k-atari-mint-gcc)
set(CMAKE_CXX_COMPILER m68k-atari-mint-g++)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    clock.c
    clock.h
    finish.c
    finish.h
    main.c
    main.h
    state.h
    sound.c
    sound.h
    melody.h)

add_executable(cntdwn ${SOURCE_FILES})

target_link_libraries(cntdwn gem)