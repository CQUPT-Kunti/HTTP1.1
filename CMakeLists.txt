cmake_minimum_required(VERSION 3.5.0)
project(test VERSION 0.1.0 LANGUAGES C CXX)

find_package(fmt CONFIG REQUIRED)
find_package(unofficial-libmysql REQUIRED)

add_executable(test main.cpp)

target_link_libraries(test PRIVATE fmt::fmt)
target_link_libraries(test PRIVATE unofficial::libmysql::libmysql)

