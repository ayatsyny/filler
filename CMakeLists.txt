cmake_minimum_required(VERSION 3.6)
project(filler)

set(CCMAKE_C_FLAGS "-std=c99")

set(SOURCE_FILES
        pars_data.c
        put_piece.c
        del_matrix.c
        filler.h)

add_executable(filler ${SOURCE_FILES})
target_link_libraries(filler ${CMAKE_SOURCE_DIR}/libft/libft.a)