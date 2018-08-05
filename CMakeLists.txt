cmake_minimum_required(VERSION 3.8)

file(GLOB_RECURSE HEADER
	include/*.h
)

project(Scroll)
add_definitions(-DSCROLL_INIT)
add_executable(ScrollTest main.cpp ${HEADER})

target_include_directories(ScrollTest PUBLIC ./include)
