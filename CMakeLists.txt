cmake_minimum_required(VERSION 3.22)
project(poly_link_list C)

set(CMAKE_C_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

aux_source_directory(. MAIN_SRC)
aux_source_directory(./src MAIN_SRC)
add_executable(${PROJECT_NAME} ${MAIN_SRC})

