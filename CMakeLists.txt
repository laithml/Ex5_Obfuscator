cmake_minimum_required(VERSION 3.21)
project(Ex5_Obfuscator)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ex5_Obfuscator main.cpp Obfuscator.cpp Obfuscator.h CommentObfuscator.cpp CommentObfuscator.h LineObfuscator.cpp LineObfuscator.h VarObfuscator.cpp VarObfuscator.h)
