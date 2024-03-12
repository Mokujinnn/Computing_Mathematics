cmake_minimum_required(VERSION 3.5)

project(nonlinearequ LANGUAGES CXX)


file(GLOB CPPS "src/*.cpp")
file(GLOB HPPS "include/*.hpp")

add_executable(${PROJECT_NAME} ${CPPS} ${HPPS})
target_include_directories(${PROJECT_NAME}
    PUBLIC "./include")