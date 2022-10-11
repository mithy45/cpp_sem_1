cmake_minimum_required(VERSION 3.0)

# set the project name
project(cartesian_vector_param)

# add the lib
add_library(vector SHARED vector.cpp)

# add another
#add_library(mysource_2 SHARED sources_2.cpp)

# add the executable
add_executable(main main.cc)

target_link_libraries(main vector)
