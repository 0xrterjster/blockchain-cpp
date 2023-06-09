cmake_minimum_required(VERSION 3.25)
project(blockchain)

set(CMAKE_CXX_STANDARD 17)

add_executable(blockchain main.cpp block.cpp miner.cpp user.cpp sha256.cpp)
