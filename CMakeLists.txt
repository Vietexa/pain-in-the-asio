cmake_minimum_required(VERSION 4.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "")
project(tcp_server LANGUAGES CXX)


find_package(Threads REQUIRED)


add_executable(server 
src/server/main.cpp
src/server/server.cpp
src/server/session.cpp
)


target_link_libraries(server PRIVATE Threads::Threads)