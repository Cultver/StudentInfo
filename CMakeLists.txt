cmake_minimum_required(VERSION 3.22)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled1  main.c model/User.h handle/userHandler.h handle/userHandler.c common/Config.h common/StringUtils.c common/StringUtils.h common/Tips.h common/Tips.c)
